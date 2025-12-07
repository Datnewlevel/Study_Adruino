#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Khởi tạo LCD với địa chỉ I2C 0x27, 16 cột và 2 hàng
// Nếu không hiển thị, thử đổi địa chỉ thành 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Đang khởi động LCD I2C...");
  
  // Khởi tạo LCD
  lcd.init();
  
  // Bật đèn nền
  lcd.backlight();
  
  // Hiển thị thông báo khởi động
  lcd.setCursor(0, 0);
  lcd.print("LCD I2C Test");
  lcd.setCursor(0, 1);
  lcd.print("Arduino Uno R3");
  
  Serial.println("LCD đã sẵn sàng!");
  delay(2000);
}

void loop() {
  // Test 1: Hiển thị text đơn giản
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello World!");
  lcd.setCursor(0, 1);
  lcd.print("Test LCD I2C");
  delay(2000);
  
  // Test 2: Đếm số
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dem so: ");
  for(int i = 0; i <= 10; i++) {
    lcd.setCursor(8, 0);
    lcd.print(i);
    lcd.print("  ");
    delay(500);
  }
  delay(1000);
  
  // Test 3: Hiển thị ký tự đặc biệt
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ky tu dac biet:");
  lcd.setCursor(0, 1);
  lcd.print("!@#$%^&*()+-=");
  delay(2000);
  
  // Test 4: Test đèn nền
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Test backlight");
  for(int i = 0; i < 3; i++) {
    lcd.noBacklight();
    delay(500);
    lcd.backlight();
    delay(500);
  }
  delay(1000);
  
  // Test 5: Cuộn text
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cuon text");
  delay(1000);
  
  String message = "   Arduino Uno R3 - LCD I2C Test   ";
  for(int i = 0; i < message.length() - 15; i++) {
    lcd.setCursor(0, 1);
    lcd.print(message.substring(i, i + 16));
    delay(300);
  }
  delay(1000);
}