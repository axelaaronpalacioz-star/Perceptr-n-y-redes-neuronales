
// Programa: Lectura de tres entradas con pesos
// Entradas: Pin 2, Pin 3, Pin 4
// Salida: Pin 13 (LED incrustado en la placa)

const float entrada1 = 2;   // Primer botón o señal digital
const float entrada2 = 3;   // Segundo botón o señal digital
const float entrada3 = 4;   // Tercer botón o señal digital
const float salida   = 13;  // LED incrustado

// Pesos asignados a cada entrada
const float peso1 = 0.21;
const float peso2 = -0.10;
const float peso3 = -0.20;

void setup() {
  pinMode(entrada1, INPUT);
  pinMode(entrada2, INPUT);
  pinMode(entrada3, INPUT);
  pinMode(salida, OUTPUT);

  Serial.begin(9600); // Para monitorear el resultado
}

void loop() {
  float valor1 = digitalRead(entrada1);
  float valor2 = digitalRead(entrada2);
  float valor3 = digitalRead(entrada3);

  // Multiplicación por pesos
  float total = (valor1 * peso1) + (valor2 * peso2) + (valor3 * peso3);

  Serial.print("Suma ponderada: ");
  Serial.println(total);

  // Condición para encender el LED
  if (total > 0) {
    digitalWrite(salida, HIGH);
  } else {
    digitalWrite(salida, LOW);
  }

  delay(200); // Pequeña pausa para estabilidad
}