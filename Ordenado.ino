int emissor = 45;
int sorteio = 0;
int cont = -1;
int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0;
int estadoBotao = 0;
int guarda_estado = LOW;
unsigned long tempomedio = 0, tempofinal = 0, tempototal = 0, tempoinicial = 0, tempoparcial = 0;
int chave = 0;
int parada = 1;

int Sinal1 = A1;
int Sinal2 = A2;
int Sinal3 = A3;
int Sinal4 = A4;
int Sinal5 = A5;
int Sinal6 = A6;
int Sinal7 = A7;
int Sinal8 = A8;
int Sinal9 = A9;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;

int botao = 35;
int LedContador = 22;

void setup() {

  pinMode(emissor, OUTPUT);

  pinMode(botao, INPUT);
  pinMode(LedContador, OUTPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);

  pinMode(Sinal1, INPUT);
  pinMode(Sinal2, INPUT);
  pinMode(Sinal3, INPUT);
  pinMode(Sinal4, INPUT);
  pinMode(Sinal5, INPUT);
  pinMode(Sinal6, INPUT);
  pinMode(Sinal7, INPUT);
  pinMode(Sinal8, INPUT);
  pinMode(Sinal9, INPUT);

  Serial.begin(9600);  
}

void loop() {
  
  a = analogRead(Sinal1);
  b = analogRead(Sinal2);
  c = analogRead(Sinal3);
  d = analogRead(Sinal4);
  e = analogRead(Sinal5);
  f = analogRead(Sinal6);
  g = analogRead(Sinal7);
  h = analogRead(Sinal8);
  i = analogRead(Sinal9);
  
  digitalWrite(emissor, HIGH);

 estadoBotao = digitalRead(botao);
 
if (estadoBotao == HIGH) {
guarda_estado = !guarda_estado;
delay(500);
}

if (guarda_estado == HIGH) {
digitalWrite(LedContador, HIGH);  
}
if (guarda_estado == HIGH && parada == 1){
  tempoinicial = millis();
   cont = 0;
    parada=0;
}
if (guarda_estado == LOW && parada == 0){
digitalWrite(LedContador, LOW);
  tempoparcial = millis();
  tempototal = tempoparcial - tempoinicial;
  tempomedio = (tempototal/cont);
  Serial.print("Tempo médio de reação do paciente: ");
   Serial.println(tempomedio);
    parada = 1;

}
  

 if(a <= 800){
    digitalWrite(led1, LOW);
  }else{
    digitalWrite(led1, HIGH);  
            cont = cont + 1;

  }
    if(b <= 800){
    digitalWrite(led2, LOW);
  }else{
    digitalWrite(led2, HIGH);  
            cont = cont + 1;

  }  
  if(c <= 800){
    digitalWrite(led3, LOW);
  }else{
    digitalWrite(led3, HIGH);  
            cont = cont + 1;

  }  
  if(d <= 800){
    digitalWrite(led4, LOW);
  }else{
    digitalWrite(led4, HIGH);  
            cont = cont + 1;

  } 
  if(e <= 800){
    digitalWrite(led5, LOW);
  }else{
    digitalWrite(led5, HIGH);  
            cont = cont + 1;

  }  
  if(f <= 800){
    digitalWrite(led6, LOW);
  }else{
    digitalWrite(led6, HIGH);
            cont = cont + 1;
  
  }
    if(g <= 800){
    digitalWrite(led7, LOW);
  }else{
    digitalWrite(led7, HIGH);  
            cont = cont + 1;

  }  if(h <= 800){
    digitalWrite(led8, LOW);
  }else{
    digitalWrite(led8, HIGH);  
            cont = cont + 1;

  }
    if(i <= 800){
    digitalWrite(led9, LOW);
  }else{
    digitalWrite(led9, HIGH);  
            cont = cont + 1;

  }
}
