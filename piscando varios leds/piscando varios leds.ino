// C++ code
//
#define LED_VERDE 2
#define LED_VERMELHO 3
#define LED_AMARELO 4
#define LED_AZUL 5
#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500
void setup()
{
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
}

void pisca(int porta){
	digitalWrite(porta, HIGH);
  	delay(UM_SEGUNDO);
  	digitalWrite(porta, LOW);
  	delay(MEIO_SEGUNDO);
}



void loop()
{
  pisca(LED_VERDE);
  pisca(LED_VERMELHO);
  pisca(LED_AMARELO);
  pisca(LED_AZUL);
  delay(MEIO_SEGUNDO);
  
}