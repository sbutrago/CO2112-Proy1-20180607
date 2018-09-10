#include "varios.h"

void mostrarOcupacion(int n_filas, int n_columnas, int **a){
  int i,j;

  for(i=0;i<n_filas;i++){
    printf("fila %2d: ",i);
    for(j=0;j<n_columnas;j++){
      printf("%d-",j);
      if(a[i][j]==LIBRE) printf("Libre   ");
      else printf("Ocupado ");
    }
    printf("\n");
  }
  system("PAUSE");
}
