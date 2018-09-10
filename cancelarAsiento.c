#include "varios.h"

void cancelarAsiento(int **a){
  int fila, col;
 
  printf("Escriba la fila del asiento a cancelar: ");scanf("%d",&fila);
  printf("Escriba la columna del asiento a cancelar: ");scanf("%d",&col);

  if(a[fila][col]==LIBRE) 
    printf("Ese asiento no está ocupado\n");
  else {
    a[fila][col]=LIBRE;
    printf("Cancelación realizada\n");
  }
  system("PAUSE");
}
