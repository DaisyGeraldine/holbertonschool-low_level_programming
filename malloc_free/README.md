# -   What is the difference between automatic and dynamic allocation

La función **malloc** se utiliza para asignar una cierta cantidad de memoria durante la ejecución de un programa. Solicitará un bloque de memoria del montón. Si se concede la solicitud, el sistema operativo reservará la cantidad de memoria solicitada y **malloc** devolverá un puntero al espacio reservado.
Cuando ya no se necesita la cantidad de memoria, debe devolverla al sistema operativo llamando a la función **free**.

**Asignación automática**

Cuando declara variables o cuando usa cadenas entre comillas dobles, el programa se encarga de toda la asignación de memoria. No tienes que pensar en ello.

### Dynamic allocation

#### Malloc
La función malloc asigna un número específico de bytes en la memoria y devuelve un puntero a la memoria asignada. Esta memoria tendrá permisos de lectura y escritura.

* Prototipo: void *malloc(size_t size);
* donde void * significa que es un puntero al tipo de su elección
* y el *size* es la cantidad de bytes que necesita asignar
```
julien@ubuntu:~/c/malloc$ cat malloc_example.c 
#include <stdio.h>
#include <stdlib.h>

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    char *str;

    str = malloc(sizeof(char) * 3);
    str[0] = 'O';
    str[1] = 'K';
    str[2] = '\0';
    printf("%s\n", str);
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc malloc_example.c -o m
julien@ubuntu:~/c/malloc$ ./m
OK
julien@ubuntu:~/c/malloc$ 
```

**memory**
Al contrario de las variables locales y los parámetros de la función, la memoria que se asigna con malloc no se libera automáticamente cuando la función regresa.

**La memoria no está inicializada.**
Al igual que con la asignación automática, la memoria asignada por malloc no se inicializa.

#### Free
Cuando usa malloc, tiene que manejar la memoria usted mismo. Esto significa que:
* Debe realizar un seguimiento de todas las direcciones de la memoria asignada (en una variable de tipo puntero)
* Tienes que desasignar cada espacio de memoria que te hayas asignado previamente. Si no hace esto, su programa puede quedarse sin memoria. Su sistema operativo podría incluso matar su programa mientras se está ejecutando.

```
julien@ubuntu:~/c/malloc$ cat while_malloc.c 
#include <stdio.h>
#include <stdlib.h>

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    while (1)
    {
        malloc(sizeof(char) * 1024);
    }
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc while_malloc.c -o killme
julien@ubuntu:~/c/malloc$ ./killme 
Killed
julien@ubuntu:~/c/malloc$ 

```
La función **free** libera el espacio de memoria que ha sido asignado por una llamada anterior a **malloc** (o **calloc**, o **realloc**).
-   Prototype:  `void free(void *ptr);`
-   Donde **ptr** es la dirección del espacio de memoria previamente asignado y devuelto por una llamada a malloc.

Example:

```
julien@ubuntu:~/c/malloc$ cat free_mem.c
#include <stdio.h>
#include <stdlib.h>

/**
 * m - stores 3 int in a new allocated space in memory and prints the sum
 * @n0: integer to store and print
 * @n1: integer to store and print
 * @n2: integer to store and print
 *
 * Return: nothing
 */
void m(int n0, int n1, int n2)
{
    int *t;
    int sum;

    t = malloc(sizeof(*t) * 3);
    t[0] = n0;
    t[1] = n1;
    t[2] = n2;
    sum = t[0] + t[1] + t[2];
    printf("%d + %d + %d = %d\n", t[0], t[1], t[2], sum);
    free(t);
}

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    m(98, 402, -1024);
    return (0);
}
```
En el ejemplo anterior, la memoria asignada por malloc se libera con una llamada a la función **free**.

#### Valgrind
Al escribir programas grandes y complejos, no siempre es fácil realizar un seguimiento de toda la memoria asignada y desasignada. Podemos usar el programa **Valgrind** para asegurarnos de que estamos liberando toda la memoria asignada. Es una herramienta de programación para la depuración de memoria, la detección de fugas de memoria y la creación de perfiles.

```
julien@ubuntu:~/c/malloc$ cat malloc_mem.c
#include <stdio.h>
#include <stdlib.h>

/**
 * m - stores 3 int in a new allocated space in memory and prints the sum
 * @n0: integer to store and print
 * @n1: integer to store and print
 * @n2: integer to store and print
 *
 * Return: nothing
 */
void m(int n0, int n1, int n2)
{
    int *t;
    int sum;

    t = malloc(sizeof(*t) * 3);
    t[0] = n0;
    t[1] = n1;
    t[2] = n2;
    sum = t[0] + t[1] + t[2];
    printf("%d + %d + %d = %d\n", t[0], t[1], t[2], sum);
}

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    m(98, 402, -1024);
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc malloc_mem.c -o m
julien@ubuntu:~/c/malloc$ valgrind ./m
==3749== Memcheck, a memory error detector
==3749== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3749== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3749== Command: ./m
==3749== 
98 + 402 + -1024 = -524
==3749== 
==3749== HEAP SUMMARY:
==3749==     in use at exit: 12 bytes in 1 blocks
==3749==   total heap usage: 2 allocs, 1 frees, 1,036 bytes allocated
==3749== 
==3749== LEAK SUMMARY:
==3749==    definitely lost: 12 bytes in 1 blocks
==3749==    indirectly lost: 0 bytes in 0 blocks
==3749==      possibly lost: 0 bytes in 0 blocks
==3749==    still reachable: 0 bytes in 0 blocks
==3749==         suppressed: 0 bytes in 0 blocks
==3749== Rerun with --leak-check=full to see details of leaked memory
==3749== 
==3749== For counts of detected and suppressed errors, rerun with: -v
==3749== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
julien@ubuntu:~/c/malloc$ 
```
#### Don’t trust anyone (no confíes en nadie)
En caso de error, **malloc** devuelve **NULL**. En cuanto a cualquier otra función de la biblioteca C, siempre debe verificar el valor de retorno de malloc antes de usarla. Si no lo hace, se encontrará con fallas de segmento.