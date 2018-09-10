/*Crear un programa que mediante un menú admita reservar o cancelar 
asientos de un avión, así como mostrar qué asientos están ocupados 
y libres actualmente.*/
/* Saul Buitrago - junio 2018 */

#include "varios.h"

int mostrarMenu();
void reservarAsiento(int **); 
void cancelarAsiento(int **);
void mostrarOcupacion(int, int, int **);
void actualizarBD(FILE *,int, int, int **);
void errores(int);
void entero2caracter(int , char *);

int main(){
  int resp, num;
  FILE * fp;
  int n_filas,n_columnas,n,bd=1,i,j;
  int ** asiento;
  char nombre[50], numero[50];
  
  system("cls");
  printf("1) crear una nueva base de datos\n");
  printf("2) abrir una base de datos existente\n");
  scanf("%d",&bd);
  switch(bd){
    case 1:
      // crear una nueva base de datos
      printf("Nueva BD, introduzca el numero de filas y asientos por fila: ");
      scanf("%d %d",&n_filas,&n_columnas); // m filas y n columnas
      // construccion del nombre del archivo
      strcpy(nombre,"BD_");
      entero2caracter(n_filas,numero);
      strcat(nombre,numero);
      strcat(nombre,"x");
      entero2caracter(n_columnas, numero);
      strcat(nombre,numero);
      strcat(nombre,".txt");
      printf("nombre del archivo de salida: %s\n",nombre);
      if ((fp = fopen(nombre,"w"))==NULL) errores(0);
      printf("\nSon %d filas y %d columnas\n",n_filas,n_columnas);
      fprintf(fp,"%d %d\n",n_filas,n_columnas);
      break;
    case 2:
      // abrir BD existente
      printf("nombre del archivo con la BD (max 50 caracteres sin espacios en blanco):\n");
      scanf("%s",nombre);
      if ((fp = fopen(nombre,"r"))==NULL) errores(1);
      fscanf(fp,"%d %d", &n_filas,&n_columnas); // m filas y n columnas
      break;
  }

  // reserva de memoria para la matriz asientos
  asiento = (int **) malloc (n_filas*sizeof(int *));
  if (asiento == NULL) errores(2);
  for (n = 0; n < n_filas; n++)
    { asiento[n] = (int *) malloc(n_columnas*sizeof(int));
      if (asiento[n] == NULL) errores(2);
    }
  for(i=0;i<n_filas;i++)
    for(j=0;j<n_columnas;j++)
      asiento[i][j] = 0; // Los asientos inicialmente están libres
      
  if(bd == 2){
    for(i=0;i<n_filas;i++){
      for(j=0;j<n_columnas;j++){
        fscanf(fp,"%d ", &asiento[i][j]);
      } } 
      fclose(fp);}
  
  resp=mostrarMenu();

  while(resp!=5){
    switch(resp){
     case 1:
      reservarAsiento(asiento);
      break;
     case 2:
      cancelarAsiento(asiento);
      break;
     case 3:
      mostrarOcupacion(n_filas,n_columnas,asiento);
      break;
     case 4:
      if(bd == 2){
        if ((fp = fopen(nombre,"w"))==NULL) errores(1);
        fprintf(fp,"%d %d\n",n_filas,n_columnas);}
      actualizarBD(fp,n_filas,n_columnas,asiento);
      break;
    }
    system("cls");
    printf("Son %d filas y %d columnas",n_filas,n_columnas);
    resp=mostrarMenu();
  } 
  //getch();
  fclose(fp);
  /* liberacion de memoria para la matriz asiento*/
  for(n=0; n < n_filas; n++)
     free(asiento[n]);
  free(asiento);
  system("PAUSE");
}
