#include <stdio.h>
#include <stdint.h>

/* Escriba un programa que se encargue de manejar el inicio de sesión de una computadora. Este debe constar de 4 opciones:
1.Crear usuario: pida al usuario un nombre y contraseña y los guarde en un archivo credenciales.bin .
2. Iniciar sesion: pida al usuario un nombre y contraseña y los compare con los guardados.
3. Cambiar nombre.
4. Cambiar contraseña.*/

void pedirPass(void);
void comprobarData(void);

int main(void)
{
  FILE *fp;
  pedirPass();
  comprobarData();

  return 0;
}

void pedirPass(void)
{
  printf("Cree su nombre de usuario y contrasena\n");
  char pass[6], user[6];
  fgets(pass, sizeof(pass), stdin);
  fgets(user, sizeof(user), stdin);

  FILE *fp = fopen("credenciales.bin", "wb");

  if (fp == NULL)
  {
    printf("No se pudo abrir el archivo\n");
    return;
  }

  fwrite(pass, sizeof(char), 6, fp);
  fwrite(user, sizeof(char), 6, fp);
  fclose(fp);
}

void comprobarData(void)
{
  printf("Ingrese su nombre de usuario y contrasena\n");
  char pass[6], user[6], passGuardada[6], userGuardado[6];
  fgets(pass, sizeof(pass), stdin);
  fgets(user, sizeof(user), stdin);
  FILE *fp = fopen("credenciales.bin", "rb");

  fread(passGuardada, sizeof(char), 6, fp);
  fread(userGuardado, sizeof(char), 6, fp);

  int passIgual = 1;
  int userIgual = 1;

  for (int i = 0; i < 6; i++)
  {
    if (pass[i] != passGuardada[i])
    {
      passIgual = 0;
      break;
    }
  }

  for (int i = 0; i < 6; i++)
  {
    if (user[i] != userGuardado[i])
    {
      userIgual = 0;
      break;
    }
  }

  if (passIgual == 1 && userIgual == 1)
  {
    printf("Inicio de sesion correcto\n");
  }
  else
  {
    printf("Usuario o contrasena incorrectos\n");
  }

  fclose(fp);
}