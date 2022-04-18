// C++ code
//


//leds e botoes
#define LED_VERMELHO 2
#define BOTAO_VERMELHO 3
#define LED_VERDE 4
#define BOTAO_VERDE 5
#define LED_AMARELO 6
#define BOTAO_AMARELO 7
#define LED_AZUL 8
#define BOTAO_AZUL 9

#define INDEFINIDO -1

//tempo
#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500

//sequencia
int sequencia[] = {LED_VERMELHO, LED_VERDE,
                   LED_AMARELO, LED_AZUL};

void iniciaPortas(){
  for(int i = 2; i < 10; i ++){
    if(i % 2 == 0){
    	pinMode(i, OUTPUT);
    }else if(i % 2 == 1){
    	pinMode(i++, INPUT_PULLUP);
    } 
  } 
}

void testeBotao(){
    for(int i = 2; i < 9; i += 2){
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
}


void setup()
{
  Serial.begin(9600);
  iniciaPortas();
  testeBotao();
}

int piscaLed(int porta){
	digitalWrite(porta, HIGH);
	delay(50);
  	digitalWrite(porta, LOW);
  	return(porta);
}

int estadoBotao(){
  int estadoVermelho = digitalRead(BOTAO_VERMELHO);
  if(estadoVermelho == LOW){
    return(piscaLed(LED_VERMELHO));
  }
  
  int estadoVerde = digitalRead(BOTAO_VERDE);
  if(estadoVerde == LOW){
    return(piscaLed(LED_VERDE));
  }
  
  int estadoAmarelo = digitalRead(BOTAO_AMARELO);
  if(estadoAmarelo == LOW){
  	return(piscaLed(LED_AMARELO));
  }
  
  int estadoAzul = digitalRead(BOTAO_AZUL);
  if(estadoAzul == LOW){
  	return(piscaLed(LED_AZUL));
  } else {
    return(INDEFINIDO);
  }
}


void loop()
{
  /*
  for(int i = 0;i < 4; i++){
    piscaLed(sequencia[i]);
  }
  */
  estadoBotao();
}