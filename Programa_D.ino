int pinM=2;   
int pinR=19;  
int clk=7; //PIN del reloj para la salida en paralelo
int decimal_count; 
void setup()
{
    int i;
    pinMode(pinM,0);    //      Pin para el modo de operación   
    pinMode(pinR,0);    //      Pin para hacer el reset
    pinMode(6,1);       //      Pin de salida de reloj carga de datos
    pinMode(clk,1);     //  Para el reloj de salida de datos
    pinMode(5,1);       //  Pin de salida en serie
    int M=digitalRead(pinM);
    if(M == 0)
      decimal_count=0;
    if(M == 1)
      decimal_count=255;
}

void loop()
{
    int i;
    int M=digitalRead(pinM);    //  LEEMOS MODO DE OPERACION        M = 1 DOWN      M = 0 UP
    int R=digitalRead(pinR);    //  LEEMOS RESET
    int binary_count[8];


    if( R == 1)
    {
        if( M == 0)
            decimal_count=0;
        if( M == 1)
            decimal_count=255;

    }
    else
    {
        if(M == 0 && decimal_count<255)
            decimal_count++;
        if(M == 1 && decimal_count>0)
            decimal_count--;
    }

    digitalWrite(6,0);
    shiftOut(5,6,LSBFIRST,decimal_count); //sintaxis: shiftOut(dataPin, clockPin, bitOrder,value)
    digitalWrite(clk,1);
    delay(10);
    digitalWrite(clk,0);
    

    delay(40);
}
