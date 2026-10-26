
// Programa: Lectura de tres entradas con pesos
// Entradas: Pin 2, Pin 3, Pin 4
// Salida: Pin 13 (LED incrustado en la placa)

const int entrada1 = 2;   // Primer botón o señal digital
const int entrada2 = 3;   // Segundo botón o señal digital
const int entrada3 = 4;   // Tercer botón o señal digital
const int salida   = 13;  // LED incrustado

// Pesos asignados a cada entrada
const float peso1 = -0.15268153;
const float peso2 = 1.1781778;
const float peso3 = 1.1316006;

void setup() {
  pinMode(entrada1, INPUT);
  pinMode(entrada2, INPUT);
  pinMode(entrada3, INPUT);
  pinMode(salida, OUTPUT);

  Serial.begin(9600); // Para monitorear el resultado
}

void loop() {
  int valor1 = digitalRead(entrada1);
  int valor2 = digitalRead(entrada2);
  int valor3 = digitalRead(entrada3);

  // Multiplicación por pesos
  int total = (valor1 * peso1) + (valor2 * peso2) + (valor3 * peso3);

  Serial.print("Suma ponderada: ");
  Serial.println(total);

  // Condición para encender el LED
  if (total > 1) {
    digitalWrite(salida, HIGH);
  } else {
    digitalWrite(salida, LOW);
  }

  delay(200); // Pequeña pausa para estabilidad
}