// C++ code
//

#define LED_VERMELHO 2
#define BOTAO_VERMELHO 10
void setup()
{
  Serial.begin(9600);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BOTAO_VERMELHO, INPUT_PULLUP);
  digitalWrite(LED_VERMELHO, HIGH);
  delay(250);
  digitalWrite(LED_VERMELHO, LOW);
  
}

void loop()
{
  int estadoBotao = digitalRead(BOTAO_VERMELHO);
  Serial.println(estadoBotao);
  
  if(estadoBotao == 1){
  digitalWrite(LED_VERMELHO, HIGH);
  delay(500);
    
  }else if(estadoBotao == 0){
  digitalWrite(LED_VERMELHO, LOW);
  delay(500);
  }

}