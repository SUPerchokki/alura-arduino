// C++ code
//
#define LED_VERDE 2
#define LED_VERMELHO 3
#define LED_AMARELO 4
#define LED_AZUL 5
#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500


int sequenciaLuzes[4];

void iniciaPortas(){
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
}

void setup()
{
  iniciaPortas();
  int x = 2;
  sequenciaLuzes[0] = LED_VERDE; 
  sequenciaLuzes[1] = LED_VERMELHO; 
  sequenciaLuzes[2] = LED_AMARELO;
  sequenciaLuzes[3] = LED_AZUL;

}

void pisca(int porta){
	digitalWrite(porta, HIGH);
  	delay(UM_SEGUNDO);
  	digitalWrite(porta, LOW);
  	delay(MEIO_SEGUNDO);
}

void piscaSequencia(){
  for(int i = 0; i < 4; i++){
      pisca(sequenciaLuzes[i]);
  }
  delay(MEIO_SEGUNDO);
  
}

void piscaTodas(){
  	digitalWrite(LED_VERDE, HIGH);
  	digitalWrite(LED_VERMELHO, HIGH);
  	digitalWrite(LED_AMARELO, HIGH);
  	digitalWrite(LED_AZUL, HIGH);
  	delay(UM_SEGUNDO);
  	digitalWrite(LED_VERDE, LOW);
  	digitalWrite(LED_VERMELHO, LOW);
  	digitalWrite(LED_AMARELO, LOW);
  	digitalWrite(LED_AZUL, LOW);
}


void loop()
{
	piscaSequencia();
  	piscaTodas();
  	delay(MEIO_SEGUNDO);
}