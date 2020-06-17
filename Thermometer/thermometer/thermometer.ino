int powerpin = 8;
int readpin = A0; 
int R1 = 10000;
float Vin = 5.0; 
float Vout;
float R2;
float sf = (Vin/1024);

void setup() {
  pinMode(powerpin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(powerpin, HIGH);
}

void loop() {
  Vout = analogRead(readpin)*sf;
  R2 = (Vout*R1)/(Vin-Vout);
  Serial.print(Vout);
  Serial.print("V\n");
  Serial.print(R2);
  Serial.print("Ohms\n");
  delay(500);
}
