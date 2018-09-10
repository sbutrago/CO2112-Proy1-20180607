void entero2caracter(int num, char * ss)
{
   int temp, rem, i, len_s2;
   char s1[1], s2[20];
   
   // convertir num a cadena de caracteres s2, esta invertida
   temp = num;
   rem = temp%10;
   sprintf(s1,"%c",rem+48);
   strcpy(s2,s1);
   temp/=10;
   while(temp!=0){
     rem = temp%10;
     sprintf(s1,"%c",rem+48);
     strcat(s2,s1);
     temp/=10;
   }
   // se invierte la cadena s2
   len_s2 = strlen(s2);
   for(i=0; i<len_s2; i++){
     ss[i] = s2[len_s2-i-1];
   }
   ss[len_s2] = '\0';
}
