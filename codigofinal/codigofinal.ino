// C++ code
//
#define BOTAO_VERDE 2
#define LED_VERDE 3
#define BOTAO_VERMELHO 4
#define LED_VERMELHO 5
#define BOTAO_AMARELO 6
#define LED_AMARELO 7
#define BOTAO_AZUL 8
#define LED_AZUL 9

#define INDEFINIDO -1

#define TAMANHO_SEQUENCIA 4

int rodada = 0;

int ledsRespondidos = 0;

enum Estados{
 PRONTO_PARA_PROXIMA_RODADA,
 USUARIO_RESPONDENDO,
 JOGO_FINALIZADO_COM_SUCESSO,
 JOGO_FINALIZADO_COM_FALHA
 };

int sequencia[TAMANHO_SEQUENCIA];


void iniciaPortas(){
  for(int i = 2; i < 10; i ++){
    if(i % 2 == 1){
      pinMode(i, OUTPUT);
    } else if(i % 2 == 0){
      pinMode(i, INPUT_PULLUP);
     }
    
  } 
}


int sorteiaCor(){
  int i = random(BOTAO_VERDE, LED_AZUL + 1);
  //enquanto o numero sorteado for o de um botão, o loop não para
  while(i % 2 == 0){
    i = random(BOTAO_VERDE, LED_AZUL + 1);
  }
  return(i);
}

int piscaLed(int porta){
  digitalWrite(porta, HIGH);
  delay(250);
  digitalWrite(porta, LOW);
  delay(250);
  return(porta);
}

void iniciaJogo(){
  int jogo = analogRead(0);
  randomSeed(jogo);
  for(int i = 0; i < TAMANHO_SEQUENCIA  ; i++){
    sequencia[i] = sorteiaCor();
  }

}


void setup()
{
  Serial.begin(9600);
  iniciaPortas();
  iniciaJogo();
  
}


void jogoFinalizadoComSucesso(){
  piscaLed(LED_AZUL);
  piscaLed(LED_AMARELO);
  piscaLed(LED_VERMELHO);
  piscaLed(LED_VERDE);
}

void jogoFinalizadoComFalha(){
  digitalWrite(LED_AZUL, HIGH);
  digitalWrite(LED_AMARELO, HIGH);
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  delay(1000);
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_VERDE, LOW);
}


void tocaLedsRodada(){
   for(int i = 0; i < rodada; i++){                                                              
    piscaLed(sequencia[i]);
  }
}


int estadoAtual(){
  if(rodada <= TAMANHO_SEQUENCIA){
    if(ledsRespondidos == rodada){
      return PRONTO_PARA_PROXIMA_RODADA;  
    } else {
     return USUARIO_RESPONDENDO;  
    }
       
  }else if(rodada == TAMANHO_SEQUENCIA + 1){
    return JOGO_FINALIZADO_COM_SUCESSO;
  } else {
    return JOGO_FINALIZADO_COM_FALHA;
  }
 
 }

void preparaNovaRodada(){
  rodada++;
  ledsRespondidos = 0;
  if(rodada <= TAMANHO_SEQUENCIA){
   tocaLedsRodada(); 
  }
}

int respostaUsuario(){
 if(digitalRead(BOTAO_VERDE) == LOW){
    return(piscaLed(LED_VERDE));
  }else if (digitalRead(BOTAO_VERMELHO) == LOW){
    return(piscaLed(LED_VERMELHO));
  }else if (digitalRead(BOTAO_AMARELO) == LOW){
    return(piscaLed(LED_AMARELO));
  }else if (digitalRead(BOTAO_AZUL) == LOW){
    return(piscaLed(LED_AZUL));
  }
  return INDEFINIDO;
}

void processaRespostaUsuario(){
  int resposta = respostaUsuario();
  if(resposta == INDEFINIDO){
    return;
  }
  
  if(resposta == sequencia[ledsRespondidos]){
    ledsRespondidos++;
  } else {
    Serial.println("resposta Errada");
    rodada = TAMANHO_SEQUENCIA + 2;
  }
}


void loop(){  
 switch(estadoAtual()){
  case PRONTO_PARA_PROXIMA_RODADA:
      Serial.println("pronto para a proxima rodada");
      preparaNovaRodada();
      break;
  case USUARIO_RESPONDENDO:
      Serial.println("esperando o usuario responder");
      processaRespostaUsuario();
      break;
  case JOGO_FINALIZADO_COM_SUCESSO:
      Serial.println("jogo finalizado com sucesso");
      jogoFinalizadoComSucesso();
      break;
  case JOGO_FINALIZADO_COM_FALHA:
      Serial.println("jogo finalizado com falha");
      jogoFinalizadoComFalha();
      break;
 }
}
