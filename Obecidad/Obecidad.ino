
float pesoEdad = 0.1434123231;
float pesoSexo = 0.0000000000;
float pesoIMC = 0.3768306166;
float pesoActividad = -0.5679373487;
float pesoCalorias = 0.0030230872;
float pesoAntecedentes = 4.0076783280;
float sesgo = -23.5807385032;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(3000);

  Serial.println("PERCEPTRON PARA OBESIDAD");
  Serial.println("Introduce 6 valores separados por espacios:");
  Serial.println("Edad Sexo IMC Actividad Calorias Antecedentes");
  Serial.println("Ejemplo: 25 0 22.5 5 2200 0");
}

void loop() {
  if (Serial.available() > 0) {

    float edad = Serial.parseFloat();
    float sexo = Serial.parseFloat();
    float imc = Serial.parseFloat();
    float actividad = Serial.parseFloat();
    float calorias = Serial.parseFloat();
    float antecedentes = Serial.parseFloat();

    // Limpiar caracteres restantes
    while (Serial.available() > 0) {
      Serial.read();
    }

    bool valido =
      edad > 0 &&
      (sexo == 0 || sexo == 1) &&
      imc > 0 &&
      actividad >= 0 &&
      calorias > 0 &&
      (antecedentes == 0 || antecedentes == 1);

    if (valido) {

      float z =
          pesoEdad * edad
        + pesoSexo * sexo
        + pesoIMC * imc
        + pesoActividad * actividad
        + pesoCalorias * calorias
        + pesoAntecedentes * antecedentes
        + sesgo;

      int resultado = (z >= 0) ? 1 : 0;

      Serial.println("-------------------------");

      Serial.print("Suma ponderada: ");
      Serial.println(z, 6);

      Serial.print("Clase predicha: ");
      Serial.println(resultado);

      if (resultado == 1) {
        Serial.println("Clase 1 - Obesidad");
      } else {
        Serial.println("Clase 0 - Sin obesidad");
      }

      Serial.println("-------------------------");

    } else {
      Serial.println("Entrada no valida.");
      Serial.println("Ejemplo: 25 0 22.5 5 2200 0");
    }

    Serial.println("Introduce los siguientes 6 valores:");
  }
}
