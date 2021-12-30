int pinM=2;   
int pinR=19;  
int decimal_count; 
void setup()
{
    int i;
    pinMode(pinM,0);    //      PIN PARA EL MODO DE OPERACION   
    pinMode(pinR,0);    //      PIN PARA HACER EL RESET 
    for(i=5; i<13; i++)
        pinMode(i,1);       //  LEDS DE SALIDA 
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


    decimal2binary(decimal_count,binary_count);

    for(i=5; i<13; i++)
        digitalWrite(i,binary_count[i-5]);

    delay(50);

}


void decimal2binary(int decimalnumber, int *binarynumber)
{
    int i=0;
    for(i=0;i<8;i++){
      binarynumber[i]=0;
    }
    i=0;
    while(decimalnumber>0)
    {
        binarynumber[i++]=decimalnumber%2;
        decimalnumber/=2;
    }


}
