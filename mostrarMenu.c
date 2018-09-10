#include "varios.h"

/* Función que muestra el menú del programa y retorna
el número de menú elegido por el usuario */ 
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
