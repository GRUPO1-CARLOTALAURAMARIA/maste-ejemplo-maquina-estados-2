#include "mbed.h"
 
/*
   Maquina sencilla de dos estados. Estado ledApagado y estado ledEncendido.
   El led se tiene que encender durante dos segundos cuando se pulse 
   El boton de la placa funciona por nivel bajo
*/
enum estados {apagado, encendido, esperando} estado;
 
Timer temporizador;
 
 
DigitalOut led(D5);
DigitalIn boton(D2);
 
void estadoApagado()
{
    if(boton==1) {
        temporizador.reset();
        led=1;
        estado=encendido;
        
        

        }
      
}

       
void estadoEncendido()
{
    if(temporizador.read()>2.0f) {
        if(boton==1){
            led=0;
            estado=esperando;
        }
        else{
            led=0;
            estado=apagado;
        }
       
     
    }

   
    
}
void estadoEsperando(){
        if(boton==0){
            led=0;
            estado=apagado;
        }
}

int main()
{
    led=0;
    estado=apagado;
    temporizador.reset();
    temporizador.start();
    while(1) {
        switch(estado) {
            case apagado:
                estadoApagado();
                break;
            case encendido:
                estadoEncendido();
                break;
            case esperando:
                estadoEsperando();
                break;
        }
 
    }
}