// Programa: Operación lógica AND con dos entradas digitales
// Entradas: Pin 2 (p) y Pin 3 (q)
// Salida: Pin 13 (LED incrustado)

const int entrada1 = 2;   // Primer botón o señal digital
const int entrada2 = 3;   // Segundo botón o señal digital
const int salida   = 13;  // LED incrustado en la placa

void setup() {
  pinMode(entrada1, INPUT);   // Configura pin 2 como entrada
  pinMode(entrada2, INPUT);   // Configura pin 3 como entrada
  pinMode(salida, OUTPUT);    // Configura pin 13 como salida

  Serial.begin(9600);         // Inicializa comunicación serial
}

void loop() {
  int valor1 = digitalRead(entrada1);  // Lee estado de la primera entrada
  int valor2 = digitalRead(entrada2);  // Lee estado de la segunda entrada

  // Operación lógica AND
  Serial.print("La Multiplicacion es: ");
  if (valor1 && valor2 ) {
    digitalWrite(salida, HIGH);   // Enciende LED si ambas entradas están en HIGH
    Serial.println("1");
  } else {
    digitalWrite(salida, LOW);    // Apaga LED en cualquier otro caso
    Serial.println("0");
  }
}