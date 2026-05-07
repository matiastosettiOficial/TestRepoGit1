const int ledRojo = 3; // conexión del LED
const int trigPin = 1; // conexión del pin Trig del Sonar
const int echoPin = 0; // conexión del pin Echo del Sonar

long duracion = 0;
long cm = 0;

void setup() {
// inicia pines

pinMode(ledRojo, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop()
{
// Inicia el sonar y envia un pin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);

// lee el tiempo en milisegundos hasta que el eco vuelve.
duracion = pulseIn(echoPin, HIGH);

cm= duracion/58; // paso a cm el tiempo dividiendo por el doble de la velocidad del sonido

if(cm <= 1 && cm > 0) // si la distancia es menor a 10 cm (salvo que sea 0, es decir TimeOut)
{
digitalWrite(ledRojo, HIGH); // enciendo el LED
} else {
digitalWrite(ledRojo, LOW); // apago el LED
}

delay(5000);
}
