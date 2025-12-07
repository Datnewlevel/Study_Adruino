#include <DHT.h>

// Cấu hình chân kết nối
#define DHTPIN 2        // Chân DATA của DHT11 nối vào D2
#define DHTTYPE DHT11   // Loại cảm biến: DHT11

// Khởi tạo DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Khởi động Serial Monitor
  Serial.begin(9600);
  Serial.println("=================================");
  Serial.println("Test cam bien DHT11");
  Serial.println("=================================");
  Serial.println();
  
  // Khởi động cảm biến DHT11
  dht.begin();
  
  Serial.println("Cam bien da san sang!");
  Serial.println("Cho 2 giay de on dinh...");
  delay(2000);
  Serial.println();
}

void loop() {
  // Đọc độ ẩm (%)
  float humidity = dht.readHumidity();
  
  // Đọc nhiệt độ (°C)
  float temperature = dht.readTemperature();
  
  // Kiểm tra xem có đọc được dữ liệu không
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("❌ LOI: Khong doc duoc du lieu tu DHT11!");
    Serial.println("   Kiem tra lai ket noi day.");
    Serial.println();
    delay(2000);
    return;
  }
  
  // Tính Heat Index (chỉ số cảm giác nhiệt)
  float heatIndex = dht.computeHeatIndex(temperature, humidity, false);
  
  // Hiển thị kết quả
  Serial.println("--- Doc Du Lieu DHT11 ---");
  Serial.print("Do am: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  Serial.print("Nhiet do: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.print("Chi so cam giac nhiet: ");
  Serial.print(heatIndex);
  Serial.println(" °C");
  
  // Đánh giá môi trường
  Serial.print("Danh gia: ");
  if (temperature < 18) {
    Serial.println("Lanh");
  } else if (temperature < 25) {
    Serial.println("Mat me");
  } else if (temperature < 30) {
    Serial.println("Am ap");
  } else {
    Serial.println("Nong");
  }
  
  if (humidity < 30) {
    Serial.println("          Kho khan");
  } else if (humidity < 60) {
    Serial.println("          Do am vua phai");
  } else if (humidity < 80) {
    Serial.println("          Hoi am");
  } else {
    Serial.println("          Rat am");
  }
  
  Serial.println("========================");
  Serial.println();
  
  // Đợi 2 giây trước khi đọc lại
  // DHT11 cần ít nhất 1 giây giữa các lần đọc
  delay(2000);
}