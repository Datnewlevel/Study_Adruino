#define TRIG_PIN 2    // Chân TRIG nối vào D2
#define ECHO_PIN 3    // Chân ECHO nối vào D3

// Biến lưu khoảng cách
long duration;
float distanceCm;
float distanceInch;

void setup() {
  // Khởi động Serial Monitor
  Serial.begin(9600);
  Serial.println("========================================");
  Serial.println("   Test cam bien sieu am HC-SR04");
  Serial.println("========================================");
  Serial.println();
  
  // Cấu hình chân
  pinMode(TRIG_PIN, OUTPUT);  // TRIG là OUTPUT (phát tín hiệu)
  pinMode(ECHO_PIN, INPUT);   // ECHO là INPUT (nhận tín hiệu)
  
  Serial.println("Cam bien da san sang!");
  Serial.println("Dat vat can truoc cam bien de do khoang cach");
  Serial.println();
  delay(1000);
}

void loop() {
  // Đọc khoảng cách
  distanceCm = readDistance();
  distanceInch = distanceCm / 2.54;
  
  // Kiểm tra khoảng cách hợp lệ
  if (distanceCm > 0 && distanceCm < 400) {
    // Hiển thị kết quả
    Serial.println("--- Do Khoang Cach ---");
    Serial.print("Khoang cach: ");
    Serial.print(distanceCm);
    Serial.print(" cm  |  ");
    Serial.print(distanceInch);
    Serial.println(" inch");
    
    // Đánh giá khoảng cách
    Serial.print("Danh gia: ");
    if (distanceCm < 5) {
      Serial.println("RAT GAN!");
    } else if (distanceCm < 20) {
      Serial.println("Gan");
    } else if (distanceCm < 50) {
      Serial.println("Trung binh");
    } else if (distanceCm < 100) {
      Serial.println("Xa");
    } else {
      Serial.println("Rat xa");
    }
    
    // Hiển thị thanh bar
    printBar(distanceCm);
    
  } else {
    Serial.println("❌ Ngoai tam do (2-400cm)");
    Serial.println("   Kiem tra: ");
    Serial.println("   - Vat can co o trong tam?");
    Serial.println("   - Ket noi day dung chua?");
  }
  
  Serial.println("========================");
  Serial.println();
  
  // Đợi trước khi đo lại
  delay(500);
}

// Hàm đọc khoảng cách
float readDistance() {
  // Xóa chân TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Phát xung 10μs qua chân TRIG
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Đọc thời gian xung HIGH từ chân ECHO
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Tính khoảng cách (cm)
  // Công thức: khoảng cách = (thời gian × tốc độ âm thanh) / 2
  // Tốc độ âm thanh = 343 m/s = 0.0343 cm/μs
  // distanceCm = (duration × 0.0343) / 2
  float distance = duration * 0.0343 / 2;
  
  return distance;
}

// Hàm hiển thị thanh bar cho khoảng cách
void printBar(float dist) {
  Serial.print("Bar: [");
  
  // Giới hạn 0-100cm cho thanh bar
  int barLength = map(constrain(dist, 0, 100), 0, 100, 0, 30);
  
  for (int i = 0; i < 30; i++) {
    if (i < barLength) {
      Serial.print("=");
    } else {
      Serial.print(" ");
    }
  }
  
  Serial.println("]");
}