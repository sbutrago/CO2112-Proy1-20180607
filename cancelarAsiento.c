#include "varios.h"

void cancelarAsiento(int **a){
  int fila, col;
 
  printf("Escriba la fila del asiento a cancelar: ");scanf("%d",&fila);
  printf("Escriba la columna del asiento a cancelar: ");scanf("%d",&col);

  if(a[fila][col]==LIBRE) 
    printf("Ese asiento no est� ocupado\n");
  else {
    a[fila][col]=LIBRE;
    printf("Cancelaci�n realizada\n");
  }
  system("PAUSE");
}
