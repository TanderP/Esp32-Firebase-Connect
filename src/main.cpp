#include <WiFi.h>
#include <FirebaseESP32.h>

// Firebase database credentials
#define FIREBASE_HOST "link of your firebase" // https://firebasename.region.firebasedatabase.app
#define FIREBASE_AUTH "Secret key" // random string of characters from the secret key


// Wi-Fi credentials
#define WIFI_SSID "Your wifi name"
#define WIFI_PASSWORD "Your wifi password"

// Create an instance of the FirebaseESP32 class
FirebaseData firebaseData;

// Create an instance of the FirebaseESP32 class
FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);
  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");

  // Initialize Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Read data from the "example" node in Firebase
 if (Firebase.getInt(firebaseData, "/Data1")) {
    if (firebaseData.dataType() == "int") {
      Serial.print("Value: ");
      Serial.println(firebaseData.intData());
    } else {
      Serial.println("Invalid data type");
    }
  } else {
    Serial.println("Not Connected to Firebase");
  }
    // Send data to the "DataInt" node in Firebase
  int valueToSend = 42;
  if (Firebase.setInt(firebaseData, "/Data111'", valueToSend)) {
    Serial.println("Data1 sent successfully");
  } else {
    Serial.println("Failed to send data");
  }
// send data to the "DataInt" node in Firebase
   if (Firebase.getString(firebaseData, "/DataSTr")) {
    if (firebaseData.dataType() == "string") {
      Serial.print("Data String: ");
      Serial.println(firebaseData.stringData());
    } else {
      Serial.println("Invalid data type");
    }
  } else {
    Serial.println("Not Connected to Firebase");
  }
  // to send data to the "DataString" node in Firebase
    String DataString = "TDRTDR";
  if (Firebase.set(firebaseData, "/DataString'", DataString)) {
    Serial.println("DataString sent successfully");
  } else {
    Serial.println("Failed to send dataStr1");
  }
  // to send data to the Data inside a node in Firebase
    String DataFile1 = "TDRTDR212";
   if (Firebase.set(firebaseData, "/DataString/DataFile1'", DataFile1)) {
    Serial.println("DataString sent successfully");
  } else {
    Serial.println("Failed to send dataStr2");
  } 
    // Wait for 1 second before reading data again
  delay(1000);
}
