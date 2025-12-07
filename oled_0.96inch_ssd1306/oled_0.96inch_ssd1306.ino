#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Ball variables
int ballX = 64;
int ballY = 32;
int ballDX = 2;
int ballDY = 2;
int ballRadius = 3;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(4, 28);
  display.println("Welcome To Real Tech");
  display.display();
  delay(5000);  // Show greeting for 5 seconds
}

void loop() {
  display.clearDisplay();

  // Update ball position
  ballX += ballDX;
  ballY += ballDY;

  // Bounce off edges
  if (ballX <= ballRadius || ballX >= (SCREEN_WIDTH - ballRadius)) {
    ballDX = -ballDX;
  }
  if (ballY <= ballRadius || ballY >= (SCREEN_HEIGHT - ballRadius)) {
    ballDY = -ballDY;
  }

  // Draw ball
  display.fillCircle(ballX, ballY, ballRadius, SSD1306_WHITE);

  // Show dynamic message
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("X:");
  display.print(ballX);
  display.print(" Y:");
  display.print(ballY);

  display.display();
  delay(30);  // Controls speed
}