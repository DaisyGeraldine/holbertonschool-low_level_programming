# Arguments to main ()

Para aquellos que escriben programas que se ejecutarán en un entorno alojado, los argumentos de main brindan una oportunidad útil para dar parámetros a los programas.
Por lo general, esta función se utiliza para dirigir la forma en que el programa realiza su tarea. **Es particularmente común proporcionar nombres de archivo** a un programa a través de sus argumentos.

The declaration of main looks like this:
```
int main(int argc, char *argv[]);
```
Hay al menos dos argumentos para main: argc y argv.
* El primero de ellos es un recuento de los argumentos proporcionados al programa.
* El segundo es una matriz de punteros a las cadenas que son esos argumentos: su tipo es **(almost)** 'matriz de puntero a char'.
```
char *argv[]
```
Recuerde también que cuando se pasa a una función, el nombre de una matriz se convierte en la dirección de su primer elemento. Esto significa que también podemos declarar argv como char **argv; las dos declaraciones son equivalentes en este contexto.

De hecho, a menudo verá la declaración de *main* expresada en estos términos. Esta declaración es exactamente equivalente a la que se muestra arriba:
```
int main(int argc, char **argv);
```
Cuando se inicia un programa, los argumentos de main se habrán inicializado para cumplir las siguientes condiciones:
* argc es mayor que cero. 
* argv[argc] es un puntero nulo.
* argv[0] hasta argv[argc-1] son ​​punteros a cadenas cuyo significado será determinado por el programa.
* argv[0] será una cadena que contenga el nombre del programa o una cadena nula si no está disponible. Los elementos restantes de argv representan los argumentos suministrados al programa
* En los casos en los que solo haya soporte para caracteres de mayúsculas y minúsculas, el contenido de estas cadenas se proporcionará al programa en minúsculas.

```
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        while(argc--)
                printf("%s\n", *argv++);
        exit(EXIT_SUCCESS);
}
```
**Ejemplos de ejecución:**
```
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char * argv[])
[
   int i, sum = 0;
   printf("argc = %d\n",argc);
   printf("Let'see what is in argv[]\n");
   if(argc>1)
   {
        for(i = 1; i < argc; i++)
	    {
	        printf("argv[%d]=%s\n", i, argv[i]);
            sum+=atoi(argv[i]);
	    }
            printf("Total=%d\n",sum);
   }
   return 0;
}
```
**Resultado**
```
PaulProgramming: gcc args.c -o add
PaulProgramming: ./add
argc = 1
Let's see what is in argv[]
PaulProgramming: ./add 3 2 5
argc = 4
Let's see what is in argv[]
argv[1] = 3
argv[2] = 2
argv[3] = 5
Total = 10
PaulProgramming: ./add 3 -2 5
argc = 4
Let's see what is in argv[]
argv[1] = 3
argv[2] = -2
argv[3] = 5
Total = 6
PaulProgramming:
```