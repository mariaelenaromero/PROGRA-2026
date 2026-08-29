#include <stdio.h>
#include <stdint.h>

struct alumno
{
  int legajo;
  char nombre[20];
  float nota;
};

void guardar(struct alumno a, FILE *fp);
float leer(FILE *fp);
void mejorProm(float a1, float a2, float a3);

int main(void)
{
  struct alumno a1 = {
      .legajo = 1111,
      .nombre = "Maru",
      .nota = 7};

  struct alumno a2 = {1112, "Joaco", 9};

  struct alumno a3 = {1113, "Pia", 3};

  FILE *fp;
  fp = fopen("estudiantes.dat", "wb");
  if (fp == NULL)
  {
    printf("No se pudo abrir el archivo\n");
    return 0;
  }

  guardar(a1, fp);
  guardar(a2, fp);
  guardar(a3, fp);

  fclose(fp);

  fp = fopen("estudiantes.dat", "rb");

  float al1 = leer(fp);
  float al2 = leer(fp);
  float al3 = leer(fp);

  fclose(fp);

  mejorProm(al1, al2, al3);

  return 0;
}

void guardar(struct alumno a, FILE *fp)
{
  fwrite(&a.legajo, sizeof(int), 1, fp);
  fwrite(a.nombre, sizeof(char), 20, fp);
  fwrite(&a.nota, sizeof(float), 1, fp);
}

float leer(FILE *fp)
{
  struct alumno a;
  fread(&a.legajo, sizeof(int), 1, fp);
  fread(a.nombre, sizeof(char), 20, fp);
  fread(&a.nota, sizeof(float), 1, fp);

  /*
    printf("legajo: %d\n", a.legajo);
    printf("nombre: %s\n", a.nombre);
    printf("nota: %.2f\n\n", a.nota);
    */

  return a.nota;
}

void mejorProm(float a1, float a2, float a3)
{
  float max = a1;
  if (max < a2)
  {
    max = a2;
  }
  if (max < a3)
  {
    max = a3;
  }
  printf("\nEl mejor promedio fue %.2f\n\n", max);
  return;
}
