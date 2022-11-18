#define pinA 3  // de cima
#define pinB 2  // cima direita
#define pinC 7  // baixo direita
#define pinD 8  // de baixo
#define pinE 9  // baixo esquerda
#define pinF 4  // cima esquerda
#define pinG 5  // meio
#define pinDP 6 // bolinha

volatile int j = 0;

void forward()
{
    switch (j)
    {
    case 0:
        turnH();
        j++;
        break;
    case 1:
        turnE();
        j++;
        break;
    case 2:
        turnL();
        j++;
        break;
    case 3:
        turnL();
        j++;
        break;
    case 4:
        turnO();
        j++;
        break;
    case 5:
        turnA();
        j++;
        break;
    case 6:
        turnT();
        j++;
        break;
    case 7:
        turn3();
        j++;
        break;
    case 8:
        turn2();
        j++;
        break;
    case 9:
        turn8();
        j++;
        break;
    case 10:
        turnP();
        j=0;
        break;
    }
}

void backward()
{
    switch (j)
    {
    case 0:
        turnH();
        j=10;
        break;
    case 1:
        turnE();
        j--;
        break;
    case 2:
        turnL();
        j--;
        break;
    case 3:
        turnL();
        j--;
        break;
    case 4:
        turnO();
        j--;
        break;
    case 5:
        turnA();
        j--;
        break;
    case 6:
        turnT();
        j--;
        break;
    case 7:
        turn3();
        j--;
        break;
    case 8:
        turn2();
        j--;
        break;
    case 9:
        turn8();
        j--;
        break;
    case 10:
        turnP();
        j--;
        break;
    }
}

void turnOn()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, LOW);
}

void turnOff()
{
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDP, HIGH);
}

void turnH()
{
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
}

void turnE()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
}

void turnL()
{
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDP, HIGH);
}

void turnO()
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

void turnA()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
}

void turnT()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDP, HIGH);
}

void turnP()
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDP, HIGH);
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

void InitialiseInterrupt(){
    cli();	// Desabilita interrupcoes  
    PCICR = 0;     //ou 0x01; Enable PCINT4 interrupt PINOS PCINT[7:0] (0) 
    PCMSK0 = 4; //Seta a mascara para PCINT4 ?(PCINT0|PCINT1|PCINT2)
    sei();		        // Habilita interrupcoes
}

ISR(PCINT4_vect) {  //pcint?01234?_vect
    // Interrupt service routine. Every single PCINT8..14 (=ADC0..5) change
    // will generate an interrupt: but this will always be the same interrupt routine
    turnH();
    j=1;
}

void setup()
{
    pinMode(21, INPUT); // entrada int0 mega2560
    pinMode(20, INPUT); // entrada int1 mega2560
    pinMode(10, INPUT); // entrada pcint4 mega2560
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinDP, OUTPUT);

    InitialiseInterrupt();    

    attachInterrupt(digitalPinToInterrupt(21), forward, RISING);
    attachInterrupt(digitalPinToInterrupt(20), backward, RISING);
}
// 1->0 FALLING
// 0->1 RISING
// 1->0 CHANGE
// 0->1 CHANGE

void loop()
{
}
