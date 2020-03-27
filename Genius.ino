// Definindo as notas utilizadas no buzzer. Consiste nas frequências das notas Dó, Mi, Sol e Lá na quarta oitava musical.

#define C4  264
#define E4  332.6
#define G4  395.5
#define A4  444
   
// Criando as variáveis utilizadas no programa e os arrays para os 4 sons, LEDs e botões, que estão relacionados entre si

int tons[4] = {C4, E4, G4, A4};
int LEDS[4] = {8, 9, 10, 11};
int BOTOES[4] = {2, 3, 4, 5};
int buzzer = 6;
int sequencia[100] = {}; // Sequência de até 100 itens vai começar vazia
int rodada_atual = 0;  // Indica a rodada atual que o jogo se encontra.
int passo_atual_na_sequencia = 0; // Indica o passo atual dentro da sequência, é usado enquanto a sequência está sendo reproduzida.
int botao_pressionado = 0; // Indica se um botão foi pressionado durante o loop principal.
int game_over = false; // Flag indicando se o jogo acabou.

void setup() {

  pinMode(buzzer, OUTPUT);
  for (int i = 0; i <= 3; i++) {
    pinMode(LEDS[i], OUTPUT);
    pinMode(BOTOES[i], INPUT);
  }
  randomSeed(analogRead(0)); // Inicializando o random através de uma leitura da porta analógica. Esta leitura gera um valor variável entre 0 e 1023.
} 
 
void loop() {
  
  if (game_over) { // Se perdeu o jogo reinicializamos todas as variáveis.
    int sequencia[100] = {};
    rodada_atual = 0;
    passo_atual_na_sequencia = 0;
    game_over = false;
  }
  
  if (rodada_atual == 0) { // Toca um som de início para anúnicar que o jogo está começando quando é a primeira rodada.  
    tocarSomDeInicio();
    delay(500);
  }
    
  proximaRodada(); // Chama a função que inicializa a próxima rodada.
  reproduzirSequencia(); // Reproduz a sequência atual.
  aguardarJogador();  // Aguarda os botões serem pressionados pelo jogador
  delay(1000); // Aguarda 1 segundo entre cada jogada.
}

void proximaRodada() { // Sorteia um novo item e adiciona na sequência.
  int numero_sorteado = random(0, 4);
  sequencia[rodada_atual++] = numero_sorteado;
}

void reproduzirSequencia() { // Reproduz a sequência para ser memorizada.
  for (int i = 0; i < rodada_atual; i++) {

    tone(buzzer, tons[sequencia[i]]);
    digitalWrite(LEDS[sequencia[i]], HIGH);
    delay(500);
    noTone(buzzer);
    digitalWrite(LEDS[sequencia[i]], LOW);
    delay(100);
  }
  noTone(buzzer);
}
void aguardarJogador() { // Aguarda o jogador iniciar sua jogada.

  for (int i = 0; i < rodada_atual; i++) {
    aguardarJogada();

    verificarJogada();

 
    if (game_over) {

      break;
    }

    passo_atual_na_sequencia++;

  }

 
  passo_atual_na_sequencia = 0;  // Redefine a variável para 0.
}

 
void aguardarJogada() {

  boolean jogada_efetuada = false;

  while (!jogada_efetuada) {

    for (int i = 0; i <= 3; i++) {

      if (digitalRead(BOTOES[i]) == HIGH) {
        botao_pressionado = i; // Dizendo qual foi o botao pressionado.
        tone(buzzer, tons[i]);
        digitalWrite(LEDS[i], HIGH);
        delay(300);
        digitalWrite(LEDS[i], LOW);
        noTone(buzzer);
        jogada_efetuada = true;
      }
    }
    delay(10);
  }
}

 
void verificarJogada() {
  if (sequencia[passo_atual_na_sequencia] != botao_pressionado) {  // GAME OVER.
    for (int i = 0; i <= 3; i++) {
      tone(buzzer, tons[i]);
      digitalWrite(LEDS[i], HIGH);
      delay(200);
      digitalWrite(LEDS[i], LOW);
      noTone(buzzer);
    }

    tone(buzzer, tons[3]);

    for (int i = 0; i <= 3; i++) {
      digitalWrite(LEDS[0], HIGH);
      digitalWrite(LEDS[1], HIGH);
      digitalWrite(LEDS[2], HIGH);
      digitalWrite(LEDS[3], HIGH);
      delay(100);
      digitalWrite(LEDS[0], LOW);
      digitalWrite(LEDS[1], LOW);
      digitalWrite(LEDS[2], LOW);
      digitalWrite(LEDS[3], LOW);
      delay(100);
    }
    noTone(buzzer);
    game_over = true;
  }
}
 
void tocarSomDeInicio() {
  tone(buzzer, tons[0]);
  digitalWrite(LEDS[0], HIGH);
  digitalWrite(LEDS[1], HIGH);
  digitalWrite(LEDS[2], HIGH);
  digitalWrite(LEDS[3], HIGH);
  delay(500);
  digitalWrite(LEDS[0], LOW);
  digitalWrite(LEDS[1], LOW);
  digitalWrite(LEDS[2], LOW);
  digitalWrite(LEDS[3], LOW);  
  delay(500);
  noTone(buzzer);
}
