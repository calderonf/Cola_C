# Cola_C
 implementacion simple de cola en C
 
 El uso de esta cola es simple:
 
 
 # include "cola.h"
 void main (){
 eCola cola1;
 eCola cola2;
 
 
 while(1){
  if (tam_cola(&cola1)>(0)){
   // Hay datos en la cola1
   //desocupe la cola
   funcionAtencionDatoCola( cola_get(&cola1));
  }
  if(tam_cola(&cola2)>(0) && SerialPuedeEnviar()){// supongamos que es una cola de ENVIO SERIAL
  // hay datos en la cola2
  EnviarPorSerial( cola_get(&cola2));
  }
 }
}
