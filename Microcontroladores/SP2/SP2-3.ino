#define AIB 10 //AI-B - Controle de velocidade do motor A (Esquerdo)
#define BIB 11 //BI-B - Controle de velocidade do motor B (Direito)
#define AIA 12 //AI-A - Controle de direção do motor A (Esquerdo)
#define BIA 13 //BI-A - Controle de direção do motor B (Direito)
#define velocidade 255 //127   0 - 255

void setup()
{
    pinMode(AIB, OUTPUT);
    pinMode(AIA, OUTPUT);
    pinMode(BIB, OUTPUT);
    pinMode(BIA, OUTPUT);
}

void loop()
{
    analogWrite(AIA, velocidade);
    analogWrite(AIB, 0);
    analogWrite(BIA, 0);
    analogWrite(BIB, velocidade);
}
