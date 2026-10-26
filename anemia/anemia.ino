
/*
  PERCEPTRON PARA CLASIFICACION DE ANEMIA
  Placa: Arduino Uno

  Entradas:
  Edad, Energia, Frecuencia, Antecedentes

  Salida:
  0 = Clase sin anemia
  1 = Clase con anemia

  Modelo educativo, no diagnostico medico.
*/

// Sustituir por los valores obtenidos en Python
float pesoEdad = 0.0698074425;
float pesoEnergia = -0.7236328315;
float pesoFrecuencia = 0.1889137611;
float pesoAntecedentes = 4.0576252723;
float sesgo = -16.3606121718;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(3000);

  Serial.println("PERCEPTRON PARA ANEMIA");
  Serial.println("Introduce 4 valores separados por espacios:");
  Serial.println("Edad, Energia, Frecuencia Cardiaca, Antecedentes(0 o 1)");
  Serial.println("Ejemplo: 25 8 72 0");
}

void loop() {
  if (Serial.available() > 0) {

    float edad = Serial.parseFloat();
    float energia = Serial.parseFloat();
    float frecuencia = Serial.parseFloat();
    float antecedentes = Serial.parseFloat();

    // Limpiar los caracteres restantes
    while (Serial.available() > 0) {
      Serial.read();
    }

    if (edad > 0 && energia > 0 &&
        frecuencia > 0 &&
        (antecedentes == 0 || antecedentes == 1)) {

      // Calcular la suma ponderada
      float z =
          pesoEdad * edad
        + pesoEnergia * energia
        + pesoFrecuencia * frecuencia
        + pesoAntecedentes * antecedentes
        + sesgo;

      // Funcion de activacion escalon
      int resultado = (z >= 0) ? 1 : 0;

      Serial.println("-------------------------");

      Serial.print("Edad: ");
      Serial.println(edad);

      Serial.print("Energia: ");
      Serial.println(energia);

      Serial.print("Frecuencia: ");
      Serial.println(frecuencia);

      Serial.print("Antecedentes: ");
      Serial.println(antecedentes);

      Serial.print("Suma ponderada: ");
      Serial.println(z, 6);

      Serial.print("Clase predicha: ");
      Serial.println(resultado);

      if (resultado == 1) {
        Serial.println("Clase 1 - Anemia");
      } else {
        Serial.println("Clase 0 - Sin anemia");
      }

      Serial.println("-------------------------");

    } else {
      Serial.println("Entrada no valida.");
      Serial.println("Ejemplo: 25 8 72 0");
    }

    Serial.println("Ingresa los siguientes 4 valores:");
  }
}
