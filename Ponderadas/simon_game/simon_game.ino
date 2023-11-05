//SIMON GAME
const int max  = 10; //Interações/Níveis máximo no jogo
int seq[max]; //Armazena as sequências de LED
int seq_jog[max]; //Armazena as sequência do jogador
int nivel = 1;

int velocidade = 1000; //Controla a velocidade do jogo

const int buzzer_pin = 12;

void iniciaBuzzer() {
  pinMode(buzzer_pin, OUTPUT);
  noTone(buzzer_pin); //Verifica se o buzzer está inicialmente desligado
}

void beep(int frequency, int duration) {
  tone(buzzer_pin, frequency, duration);
  delay(duration);
  noTone(buzzer_pin);
}

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  iniciaBuzzer(); //Inicia o buzzer

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void loop() {
  if (nivel == 1)
    gera_seq(); //Gera uma sequência;

  if (digitalRead(A4) == LOW || nivel != 1) // Se o botão de início for pressionado ou você estiver ganhando
  {
    print_seq(); //Mostra a sequência
    get_seq(); //Aguarda a sequência do jogador
  }
}

void print_seq() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  for (int i = 0; i < nivel; i++) {
    digitalWrite(seq[i], HIGH);
    beep(1000, 300); // Beep no buzzer a 1000 Hz por 300 ms
    digitalWrite(seq[i], LOW);
    delay(200);
  }
}

void get_seq() {
  int x = 0; //Indica se a sequência está correta

  for (int i = 0; i < nivel; i++) {
    x = 0;
    while (x == 0) {
      if (digitalRead(A0) == LOW) {
        digitalWrite(5, HIGH);
        seq_jog[i] = 5;
        x = 1;
        delay(200);
        if (seq_jog[i] != seq[i]) {
          seq_errada();
          return;
        }
        digitalWrite(5, LOW);
      }

      if (digitalRead(A1) == LOW) {
        digitalWrite(4, HIGH);
        seq_jog[i] = 4;
        x = 1;
        delay(200);
        if (seq_jog[i] != seq[i]) {
          seq_errada();
          return;
        }
        digitalWrite(4, LOW);
      }

      if (digitalRead(A2) == LOW) {
        digitalWrite(3, HIGH);
        seq_jog[i] = 3;
        x = 1;
        delay(200);
        if (seq_jog[i] != seq[i]) {
          seq_errada();
          return;
        }
        digitalWrite(3, LOW);
      }

      if (digitalRead(A3) == LOW) {
        digitalWrite(2, HIGH);
        seq_jog[i] = 2;
        x = 1;
        delay(200);
        if (seq_jog[i] != seq[i]) {
          seq_errada();
          return;
        }
        digitalWrite(2, LOW);
      }
    }
  }
  seq_certa();
}

void gera_seq() {
  randomSeed(millis()); // Dessa forma é realmente aleatório!!!

  for (int i = 0; i < max; i++) {
    seq[i] = random(2, 6);
  }
}

void seq_errada() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    beep(500, 250); // Beep no buzzer a 500 Hz por 250 ms
    delay(250);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(250);
  }
  nivel = 1;
  velocidade = 1000;
}

void seq_certa() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(250);

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  beep(1000, 500); // Beep no buzzer a 1000 Hz por 500 ms
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(500);

  if (nivel < max)
    nivel++;
}
