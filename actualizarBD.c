#include "varios.h"

void actualizarBD(FILE * fp, int n_filas, int n_columnas, int **a){
  int i,j,i_aux;

  for(i=0;i<n_filas;i++){
    for(j=0;j<n_columnas;j++){
      i_aux = fprintf(fp,"%d ", a[i][j]);
      if(i_aux <= 0) errores(3);
    }
    fprintf(fp,"\n");
  }
  system("PAUSE");
}
