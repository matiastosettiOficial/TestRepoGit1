// Pines de conexión
const int sensorPin = PB0; // Pin analógico para el sensor de humedad
const int bombaPin = PB1;   // Pin digital para el relé de la bomba
const int boton = PB2; // Pin digital para el botón
const int led1 = PB3; //pin digital para encender led 1
const int led2 = PB4; //pin digital para encender led 2
const int led3 = PB5; //pin digital para encender led 3

// Umbral de humedad (calibrar según sensor y tipo de suelo)
// Valores típicos: 0-300 seco, 300-600 húmedo, 600+ sumergido // ESTUDIAR CON CALIBRACIÓN //entre 0 y 1023, entre más cercano esté del 1023 el sensor está más seco, entre más cercano al 0 el sensor está más húmedo.
int umbralSeco = 400; 

void setup() {

  
  pinMode(bombaPin, OUTPUT);
  digitalWrite(bombaPin, LOW); // Iniciar bomba apagada (relevadores suelen activar con LOW)

 // Configuramos el pin del botón como ENTRADA
  pinMode(boton, INPUT);

  // Configuramos los pines de los LEDs como SALIDA
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);           // Para monitorear en pantalla y configurar
}

void loop() {
  int lectura = analogRead(sensorPin);
  Serial.print("Humedad: ");
  Serial.println(lectura);

  digitalWrite(led1,!digitalRead(led1)); //parpadeo de led para indicar que placa está procesando

  if (lectura > umbralSeco) {
    digitalWrite(bombaPin, HIGH); // Enciende la bomba
    Serial.println("Suelo seco: Riego activado");
  } else {
    digitalWrite(bombaPin, LOW); // Apaga la bomba
    Serial.println("Suelo húmedo: Riego desactivado");
  }

  if(boton){
    digitalWrite(bombaPin,!digitalRead(bombaPin));//alterna el funcionamiento bomba
    delay(1000); // Esperar 1 segundo para no solapar lecturas simultaneas de botón.
  }else{
    delay(1000); // Esperar 1 segundo antes de la próxima lectura de sensor
  }

  
  
}
