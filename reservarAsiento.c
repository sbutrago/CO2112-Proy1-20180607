#include "varios.h"

void reservarAsiento(int **a){
  int fila, col;
 
  printf("Escriba la fila del asiento a reservar: ");scanf("%d",&fila);
  printf("Escriba la columna del asiento a reservar: ");scanf("%d",&col);

  if(a[fila][col]==OCUPADO) 
    printf("Ese asiento ya está reservado\n");
  else {
    a[fila][col]=OCUPADO;
    printf("Reserva realizada\n");
  }
  system("PAUSE");
}
