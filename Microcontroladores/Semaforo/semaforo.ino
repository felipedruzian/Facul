#define vermelho 13
#define amarelo 12
#define verde 11

void setup() 
{
	pinMode(vermelho, OUTPUT);
	pinMode(amarelo, OUTPUT);
	pinMode(verde, OUTPUT);
}

void loop()
{
	digitalWrite(vermelho, HIGH);
	digitalWrite(amarelo, LOW);
	digitalWrite(verde, LOW);
	delay(3000);
	digitalWrite(vermelho, LOW);
	digitalWrite(amarelo, HIGH);
	delay(2000);
	digitalWrite(amarelo, LOW);
	digitalWrite(verde, HIGH);
	delay(3000);
}