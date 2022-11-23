#define pinA 3  // de cima
#define pinB 2  // cima direita
#define pinC 7  // baixo direita
#define pinD 8  // de baixo
#define pinE 9  // baixo esquerda
#define pinF 4  // cima esquerda
#define pinG 5  // meio
#define pinDP 6 // bolinha

#define pin2A A3  // de cima
#define pin2B A2  // cima direita
#define pin2C A7  // baixo direita
#define pin2D A8  // de baixo
#define pin2E A9  // baixo esquerda
#define pin2F A4  // cima esquerda
#define pin2G A5  // meio
#define pin2DP A6 // bolinha

volatile int i = 0;
volatile int j = 0;

void forward1()
{
    switch (j)
    {
    case 0:
        turn0();
        j++;
        break;
    case 1:
        turn1();
        j++;
        break;
    case 2:
        turn2();
        j++;
        break;
    case 3:
        turn3();
        j++;
        break;
    case 4:
        turn4();
        j++;
        break;
    case 5:
        turn5();
        j++;
        break;
    case 6:
        turn6();
        j++;
        break;
    case 7:
        turn7();
        j++;
        break;
    case 8:
        turn8();
        j++;
        break;
    case 9:
        turn9();
        j=0;
        break;
    }
}

void forward2()
{
    switch (i)
    {
    case 0:
        turnn1();
        i++;
        break;
    case 1:
        turnn2();
        i++;
        break;
    case 2:
        turnn3();
        i++;
        break;
    case 3:
        turnn4();
        i++;
        break;
    case 4:
        turnn5();
        i++;
        break;
    case 5:
        turnn6();
        i++;
        break;
    case 6:
        turnn7();
        i++;
        break;
    case 7:
        turnn8();
        i++;
        break;
    case 8:
        turnn9();
        i++;
        break;
    case 9:
        turnn0();
        i=0;
        break;
    }
}

void turn0()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDP, HIGH);
}

void turn1()
{
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDP, HIGH);
}

void turn2()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
}

void turn3()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
}

void turn4()
{
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
}

void turn5()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
}

void turn6()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
}

void turn7()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDP, HIGH);
}

void turn8()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
}

void turn9()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
}

void turnn0()
{
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);
    digitalWrite(pin2C, LOW);
    digitalWrite(pin2D, LOW);
    digitalWrite(pin2E, LOW);
    digitalWrite(pin2F, LOW);
    digitalWrite(pin2G, HIGH);
    digitalWrite(pin2DP, HIGH);
}

void turnn1()
{
    digitalWrite(pin2A, HIGH);
    digitalWrite(pin2B, LOW);
    digitalWrite(pin2C, LOW);
    digitalWrite(pin2D, HIGH);
    digitalWrite(pin2E, HIGH);
    digitalWrite(pin2F, HIGH);
    digitalWrite(pin2G, HIGH);
    digitalWrite(pin2DP, HIGH);
}

void turnn2()
{
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);
    digitalWrite(pin2C, HIGH);
    digitalWrite(pin2D, LOW);
    digitalWrite(pin2E, LOW);
    digitalWrite(pin2F, HIGH);
    digitalWrite(pin2G, LOW);
    digitalWrite(pin2DP, HIGH);
}

void turnn3()
{
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);
    digitalWrite(pin2C, LOW);
    digitalWrite(pin2D, LOW);
    digitalWrite(pin2E, HIGH);
    digitalWrite(pin2F, HIGH);
    digitalWrite(pin2G, LOW);
    digitalWrite(pin2DP, HIGH);
}

void turnn4()
{
    digitalWrite(pin2A, HIGH);
    digitalWrite(pin2B, LOW);
    digitalWrite(pin2C, LOW);
    digitalWrite(pin2D, HIGH);
    digitalWrite(pin2E, HIGH);
    digitalWrite(pin2F, LOW);
    digitalWrite(pin2G, LOW);
    digitalWrite(pin2DP, HIGH);
}

void turnn5()
{
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, HIGH);
    digitalWrite(pin2C, LOW);
    digitalWrite(pin2D, LOW);
    digitalWrite(pin2E, HIGH);
    digitalWrite(pin2F, LOW);
    digitalWrite(pin2G, LOW);
    digitalWrite(pin2DP, HIGH);
}

void turnn6()
{
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, HIGH);
    digitalWrite(pin2C, LOW);
    digitalWrite(pin2D, LOW);
    digitalWrite(pin2E, LOW);
    digitalWrite(pin2F, LOW);
    digitalWrite(pin2G, LOW);
    digitalWrite(pin2DP, HIGH);
}

void turnn7()
{
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);
    digitalWrite(pin2C, LOW);
    digitalWrite(pin2D, HIGH);
    digitalWrite(pin2E, HIGH);
    digitalWrite(pin2F, HIGH);
    digitalWrite(pin2G, HIGH);
    digitalWrite(pin2DP, HIGH);
}

void turnn8()
{
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);
    digitalWrite(pin2C, LOW);
    digitalWrite(pin2D, LOW);
    digitalWrite(pin2E, LOW);
    digitalWrite(pin2F, LOW);
    digitalWrite(pin2G, LOW);
    digitalWrite(pin2DP, HIGH);
}

void turnn9()
{
    digitalWrite(pin2A, LOW);
    digitalWrite(pin2B, LOW);
    digitalWrite(pin2C, LOW);
    digitalWrite(pin2D, LOW);
    digitalWrite(pin2E, HIGH);
    digitalWrite(pin2F, LOW);
    digitalWrite(pin2G, LOW);
    digitalWrite(pin2DP, HIGH);
}

void InitialiseTimer1()
{
    cli();
    // Configuração do timer1 
    TCCR1A = 0;  //confira timer para operação normal pinos OC1A e OC1B desconectados
    TCCR1B = 0; //limpa registrador
    TIMSK1 |= (1 << TOIE1); // habilita a interrupção do TIMER1
    //--SEM PRESCALER--
    TCCR1B = 1; // modo normal sem prescaler
    TCNT1 = 0;
    //SEM PRESCALER
    // 65536 ciclos * 6.25e-08 (periodo do ciclo em s) =  0.004096 s
    // 0.004096 s = 4.09ms tempo para interrupcao
    // 10000 ms / 4.09 ms/interrupcao = +-245 
    // 245 ciclos teremos 1S  
    sei();
}

void InitialiseTimer2()
{
    cli();
    // Configuração do timer2 
    TCCR2A = 0; //confira timer para operação normal pinos OC2A e OC2B desconectados
    TCCR2B = 0; //limpa registrador
    TIMSK2 |= (1 << TOIE2); // habilita a interrupção do TIMER2
    //--SEM PRESCALER--
    TCCR2B = 1; // modo normal sem prescaler
    TCNT2 = 0; 
    sei();
}

volatile int counter = 0;
volatile int counter2 = 0;

ISR(TIMER1_OVF_vect) //interrupção do TIMER1 
{
    TCNT1 = 0;
    counter++;
}

ISR(TIMER2_OVF_vect) //interrupção do TIMER2 
{
    //--SEM PRESCALER--
    if(counter2 == 2695){ 
        forward2();
        counter2 = 0;
    }
    if(counter == 245){
        forward1(); //inverte estado do led
        counter2 = counter2 + counter;
        counter = 0;
    }
    TCNT2 = 0;
}


void setup()
{
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinDP, OUTPUT);
    pinMode(pin2A, OUTPUT);
    pinMode(pin2B, OUTPUT);
    pinMode(pin2C, OUTPUT);
    pinMode(pin2D, OUTPUT);
    pinMode(pin2E, OUTPUT);
    pinMode(pin2F, OUTPUT);
    pinMode(pin2G, OUTPUT);
    pinMode(pin2DP, OUTPUT);

    turn0();
    turnn0();

    InitialiseTimer1();
    InitialiseTimer2();

}

void loop()
{
    
}