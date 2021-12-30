int pinM=2;   
int pinR=19;   
int contador;
void setup()
{
    int i;
    pinMode(pinM,0);    //      PIN PARA EL MODO DE OPERACION   
    pinMode(pinR,0);    //      PIN PARA HACER EL RESET 
    for(i=5; i<13; i++)
        pinMode(i,1);       //  LEDS DE SALIDA
    int M=digitalRead(pinM);
    if(M == 0)
      contador=0;
    if(M == 1)
      contador=16;
}

void loop()
{
    int i;
    int M=digitalRead(pinM);    //  LEEMOS MODO DE OPERACION         M = 0 UP VAMOS DE IZQDA A DCHA     M = 1 VAMSOS DE DCHA A IZQDA    
    int R=digitalRead(pinR);    //  LEEMOS RESET
    int output[8];      //  LED DE SALIDA

    if( R == 1)
    {
        if( M == 0)
        {
            contador=1;       //  PONGO EL 00000000
        }
        if( M == 1)
        {
            contador=16;
        }

    }
    else
    {
        if(M == 0 && contador<16)
            contador++;
            
        if(M == 1 && contador>1)
            contador--;
    }


    decimal2double_ring(contador,output);

    for(i=5; i<13; i++)
        digitalWrite(i,output[i-5]);

    delay(200);

}

void decimal2double_ring(int decimal, int *output){
    int i;
    for(i=0;i<8;i++){
      output[i]=0;
    }
    if(decimal<=8){
      for(i=0;i<decimal;i++){
        output[i]=1;
      }
      for(i=decimal;i<8;i++){
        output[i]=0;
      }
    }
    if(decimal>8){
      decimal-=8;
      for(i=0;i<decimal;i++){
        output[i]=0;
      }
      for(i=decimal;i<8;i++){
        output[i]=1;
      }
    }
    
  
}
