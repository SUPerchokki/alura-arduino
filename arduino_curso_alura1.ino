// C++ code
//
#define LED 2
#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500

void setup()
{
  pinMode(LED, OUTPUT);
}


void piscar(){
 digitalWrite(LED, HIGH);
 delay(UM_SEGUNDO);
 digitalWrite(LED,LOW);
 delay(MEIO_SEGUNDO);
}

void loop()
{
	piscar();

}