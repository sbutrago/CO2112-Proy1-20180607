#include "varios.h"

/* Funci�n que muestra el men� del programa y retorna
el n�mero de men� elegido por el usuario */ 
int mostrarMenu(){
  int resp;
  printf("\n\n");
  printf("1) Reservar Asiento\n");
  printf("2) Cancelar Asiento\n");
  printf("3) Mostrar Ocupacion\n");
  printf("4) Actualizar BD\n");
  printf("5) Salir\n");
  scanf("%d",&resp);
  return resp;
}
