
float pesoIMC = 0.26259071;
float pesoGlucosa = 0.03247171;
float sesgo = -10.09961257;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(3000);

  Serial.println("PERCEPTRON PARA CLASIFICAR DIABETES");
  Serial.println("Escribe IMC y glucosa separados por espacio.");
  Serial.println("Ejemplo: 24 90");
}

void loop() {
  if (Serial.available() > 0) {

    // Leer el IMC
    float imc = Serial.parseFloat();

    // Leer la glucosa
    float glucosa = Serial.parseFloat();

    // Limpiar caracteres restantes de la entrada
    while (Serial.available() > 0) {
      Serial.read();
    }

    if (imc > 0 && glucosa > 0) {

      float z = pesoIMC * imc
              + pesoGlucosa * glucosa
              + sesgo;

      int resultado = (z >= 0) ? 1 : 0;

      Serial.println("----------------------");
      Serial.print("IMC: ");
      Serial.println(imc, 2);

      Serial.print("Glucosa: ");
      Serial.println(glucosa, 2);

      Serial.print("Suma ponderada: ");
      Serial.println(z, 4);

      Serial.print("Clase predicha: ");
      Serial.println(resultado);

      if (resultado == 1) {
        Serial.println("Clase 1 - Diabetes");
      } else {
        Serial.println("Clase 0 - No diabetes");
      }

      Serial.println("----------------------");

    } else {
      Serial.println("Error: introduce dos valores positivos.");
    }

    Serial.println("Ingresa otros valores, por ejemplo: 24 90");
  }
}
