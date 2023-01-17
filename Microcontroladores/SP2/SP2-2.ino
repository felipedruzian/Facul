#define LED 3 // entrada int0 mega2560

#define TRIG 8
#define ECHO 9
long duracao = 0;
int cm = 0; 

int motorA_PWM = 10; //Controle de velocidade do motor A (Esquerdo)
int motorB_PWM = 11; //Controle de velocidade do motor B (Direito)
int motorA_EN = 12; //Controle de direção do motor A (Esquerdo)
int motorB_EN = 13; //Controle de direção do motor B (Direito)
int velocidade = 127; // 0 - 255

void InitialiseTimer1()
{
    cli();
    // Configuração do timer1 
    TCCR1A = 0;                        //confira timer para operação normal pinos OC1A e OC1B desconectados
    TCCR1B = 0;                        //limpa registrador
    TIMSK1 |= (1 << TOIE1);           // habilita a interrupção do TIMER1
    //---------------SEM PRESCALER--------------------------------------
    TCCR1B = 1;                   // modo normal sem prescaler
    TCNT1 = 0;
    //SEM PRESCALER
    // 65536 ciclos * 6.25e-08 (periodo do ciclo em s) =  0.004096 s
    // 0.004096 s = 4.09ms tempo para interrupcao
    // 10000 ms / 4.09 ms/interrupcao = +-245 
    // 245 ciclos teremos 1S  
    sei();
}

volatile int counter = 0;
const int seg = 5;

ISR(TIMER1_OVF_vect)   //interrupção do TIMER1 
{
    //------SEM PRESCALER
    if(counter == 245 * seg){
        //reseta o counter
        counter = 0 ;
    }
    TCNT1 = 0;
    counter++;
}

int IDelay(n)
{
    dif = counter;
    while(dif =! n)
    {
        dif - counter
    }
}

void newDirection()
{
    counter = 0;
    MotorStop();
    Giro1();
    MotorStop();
    if (cm < 5)
    {
        Giro2();
        MotorStop();
    }
    digitalWrite(LED, LOW);
}

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

    InitialiseTimer1();
    
    pinMode(21, INPUT); // entrada int0 mega2560
    attachInterrupt(digitalPinToInterrupt(21), newDirection, RISING);
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

    if (cm < 5)
    {
        digitalWrite(LED, HIGH);
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