#define TRIG 8
#define ECHO 9
long duracao = 0;
int cm = 0; 

int motorA_PWM = 10; //Controle de velocidade do motor A (Esquerdo)
int motorB_PWM = 11; //Controle de velocidade do motor B (Direito)
int motorA_EN = 12; //Controle de direção do motor A (Esquerdo)
int motorB_EN = 13; //Controle de direção do motor B (Direito)
int velocidade = 60; //127   0 - 255

void setup()
{
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    pinMode (motorA_PWM, OUTPUT);
    pinMode (motorA_EN, OUTPUT);
    pinMode (motorB_PWM, OUTPUT);
    pinMode (motorB_EN, OUTPUT);

    //"DEBUG"
    Serial.begin(9600);
    Serial.println("Iniciando Serial...");
}

void loop()
{
    MotorSentidoHorario(); //anda pra frente

    digitalWrite(TRIG, LOW); //mede distancia
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    int duracao = pulseIn(ECHO, HIGH);
    cm = duracao*0.0345/2;

    if (cm >= 0){ //serial prints
        Serial.println("Cm: " + String(cm)); // Mostrando no Monitor Serial
        Serial.println("");
        delay(500);
    }else{
        Serial.println("Não há obstáculos na faixa de leitura do sensor"); // O sensor não captou obstáculos entre 2cm a 4m de distância
        Serial.println("");
        delay(500);
    }

    if (cm < 5) //10
    {
        newDirection();
    }
}

void newDirection()
{
    MotorStop();
    delay(500);
    Giro1();
    delay(500); //testar
    MotorStop();
    if (cm < 5)
    {
        Giro2();
        delay(1000);
        MotorStop();
    }
}


void MotorSentidoHorario() //testar pra frente e pra trás
{
    digitalWrite(motorA_EN, HIGH); //Motor A. HIGH = HORARIO
    digitalWrite(motorB_EN, HIGH); //Motor B. HIGH = HORARIO
    analogWrite(motorA_PWM, velocidade); //PWM do motor esquerdo 
    analogWrite(motorB_PWM, velocidade); //PWM do motor direito 
}

void MotorSentidoAntiHorario()
{ 
    digitalWrite(motorA_EN, LOW); //Motor A. LOW = ANTI-HORÁRIO
    digitalWrite(motorB_EN, LOW); //Motor B. LOW = ANTI-HORÁRIO
    analogWrite(motorA_PWM, velocidade); //PWM do motor esquerdo 
    analogWrite(motorB_PWM, velocidade); //PWM do motor direito 
}

void MotorStop()
{
    analogWrite(motorA_PWM, 0); //PWM do motor esquerdo 
    analogWrite(motorB_PWM, 0); //PWM do motor direito 
}

void Giro1() //testar sentido do giro esquerda ou direita
{
    digitalWrite(motorA_EN, LOW); //Motor A. LOW = ANTI-HORÁRIO
    digitalWrite(motorB_EN, HIGH); //Motor B. HIGH = HORARIO
    analogWrite(motorA_PWM, velocidade); //PWM do motor esquerdo 
    analogWrite(motorB_PWM, velocidade); //PWM do motor direito 
}

void Giro2()
{
    digitalWrite(motorA_EN, HIGH); //Motor A. LOW = ANTI-HORÁRIO
    digitalWrite(motorB_EN, LOW); //Motor B. HIGH = HORARIO
    analogWrite(motorA_PWM, velocidade); //PWM do motor esquerdo 
    analogWrite(motorB_PWM, velocidade); //PWM do motor direito 
}