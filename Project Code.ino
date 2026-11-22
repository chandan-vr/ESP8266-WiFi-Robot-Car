#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Wi-Fi Access Point Details

const char *ssid = "My_Robot_Car";
const char *password = "12345678";

// Web Server on port 80

ESP8266WebServer server(80);

// Motor Driver Input Pins Definition

#define IN1 D5
#define IN2 D6
#define IN3 D7
#define IN4 D8

// Buzzer Pin Definition (Passive Buzzer)

#define BUZZER_PIN D0

// Variables

String command;

int currentSpeed = 1023;

// Function Prototypes

void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void stopCar();
void soundHorn();
void HTTP_handleRoot();

void setup() {

  Serial.begin(115200);

  // Set Motor Pins as Output

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set Buzzer Pin as Output

  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  // Stop motors initially

  stopCar();

  // Start ESP8266 Wi-Fi Access Point

  WiFi.mode(WIFI_AP);

  WiFi.softAP(ssid, password);

  Serial.println("");
  Serial.println("Wi-Fi Access Point Started!");

  Serial.print("SSID: ");
  Serial.println(ssid);

  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Handle Requests from App

  server.on("/", HTTP_handleRoot);
  server.onNotFound(HTTP_handleRoot);

  server.begin();

  Serial.println("HTTP Server Started");
}

void loop() {

  server.handleClient();
}

// Function to parse commands from App

void HTTP_handleRoot() {

  // Check for Speed Command

  if (server.hasArg("Speed")) {

    String speedValueString = server.arg("Speed");

    int newSpeedValue = speedValueString.toInt();

    if (newSpeedValue >= 0 && newSpeedValue <= 1023) {

      currentSpeed = newSpeedValue;

      Serial.print("New Speed: ");
      Serial.println(currentSpeed);
    }
  }

  // Check for Direction/Stop Command

  if (server.hasArg("State")) {

    command = server.arg("State");

    Serial.print("Command Received: ");
    Serial.println(command);

    if (command == "F") {

      moveForward();

    } else if (command == "B") {

      moveBackward();

    } else if (command == "L") {

      turnLeft();

    } else if (command == "R") {

      turnRight();

    } else if (command == "S") {

      stopCar();

    } else if (command == "V") {

      soundHorn();
    }
  }

  // Send HTTP Response OK

  server.send(200, "text/plain", "OK");
}

// Direction Control Logic

void moveForward() {

  analogWrite(IN1, currentSpeed);
  analogWrite(IN2, 0);

  analogWrite(IN3, currentSpeed);
  analogWrite(IN4, 0);
}

void moveBackward() {

  analogWrite(IN1, 0);
  analogWrite(IN2, currentSpeed);

  analogWrite(IN3, 0);
  analogWrite(IN4, currentSpeed);
}

void turnLeft() {

  analogWrite(IN1, 0);
  analogWrite(IN2, currentSpeed);

  analogWrite(IN3, currentSpeed);
  analogWrite(IN4, 0);
}

void turnRight() {

  analogWrite(IN1, currentSpeed);
  analogWrite(IN2, 0);

  analogWrite(IN3, 0);
  analogWrite(IN4, currentSpeed);
}

void stopCar() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Function to sound passive buzzer horn

void soundHorn() {

  tone(BUZZER_PIN, 1000, 200);

  Serial.println("Horn Sounded!");
}
