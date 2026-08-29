#include <stdio.h>
#include <stdint.h>

/*Implemente un código que pida nombres y los guarde en un archivo nombres.bin , hasta que el usuario ingrese “Fin”.
Implemente un código que lea e imprima en pantalla, todos los datos contenidos en el archivo nombres.bin .
Repita los puntos 1 y 2 para un archivo nombres.dat
Implemente un código que lea un archivo de texto y cuente cuántas líneas tiene.
Implemente un código que pida al usuario una palabra y busque cuántas veces aparece esa palabra en un archivo de texto.*/

int main(void)
{
  FILE *fp;
  /*char nombre1[10] = "juana";
  char nombre2[10] = "pepo";
  char nombre3[10] = "maru";
  char nombre4[10] = "joaqui";
  char nombre5[10] = "mel";

  fp = fopen("nombres.bin", "wb");
  fprintf(fp, "%s \n", nombre1);
  fprintf(fp, "%s \n", nombre2);
  fprintf(fp, "%s \n", nombre3);
  fprintf(fp, "%s \n", nombre4);
  fprintf(fp, "%s \n", nombre5);
  fclose(fp);

  fp = fopen("nombres.bin", "rb");
  fgets(nombre2, 10, fp);
  fgets(nombre3, 10, fp);
  fgets(nombre4, 10, fp);
  fgets(nombre5, 10, fp);
  fgets(nombre1, 10, fp);
  fclose(fp);

  printf("%s \n", nombre1);
  printf("%s \n", nombre2);
  printf("%s \n", nombre3);
  printf("%s \n", nombre4);
  printf("%s \n", nombre5);

  char nombre1[10] = "juana";
  char nombre2[10] = "pepo";
  char nombre3[10] = "maru";
  char nombre4[10] = "joaqui";
  char nombre5[10] = "mel";

  fp = fopen("nombres.dat", "wb");
  fwrite(nombre1, sizeof(char), 10, fp);
  fwrite(nombre2, sizeof(char), 10, fp);
  fwrite(nombre3, sizeof(char), 10, fp);
  fwrite(nombre4, sizeof(char), 10, fp);
  fwrite(nombre5, sizeof(char), 10, fp);
  fclose(fp);

  fp = fopen("nombres.dat", "rb");
  fread(nombre5, sizeof(char), 10, fp);
  fread(nombre4, sizeof(char), 10, fp);
  fread(nombre3, sizeof(char), 10, fp);
  fread(nombre2, sizeof(char), 10, fp);
  fread(nombre1, sizeof(char), 10, fp);
  fclose(fp);

  printf("%s \n", nombre1);
  printf("%s \n", nombre2);
  printf("%s \n", nombre3);
  printf("%s \n", nombre4);
  printf("%s \n", nombre5);

  fp = fopen("nombres.dat", "r");
  if (fp == NULL)
  {
    printf("No se pudo abrir el archivo\n");
    return 1;
  }

  int lineas = 0;
  char c;

  while ((c = fgetc(fp)) != EOF)
  {
    if (c == '\n')
    {
      lineas++;
    }
  }

  fclose(fp);
  printf("El archivo tiene %d lineas\n", lineas); */

  return 0;
}
