void errores(int num)
{
   static char *err[] = {
      "\nNo se puede abrir el archivo para lectura.\n", //caso 0
      "\nNo se puede abrir el archivo para escritura.\n", // caso 1
      "\nError: no hay memoria.\n", // caso 2
      "\nproblemas con la escritura en actualizar BD.\n" // caso 3
   };
   printf(" %s ",err[num]);
   system("PAUSE"); 
   exit(1);
}
