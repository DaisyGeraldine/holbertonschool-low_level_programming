# C - Variadic functions

## stdarg.h
Es un encabezado en la biblioteca estándar C del lenguaje de programación C que permite que las funciones acepten un número indefinido de argumentos. Proporciona facilidades para recorrer una lista de argumentos de función de número y tipo desconocidos. C++ proporciona esta funcionalidad en el encabezado cstdarg.

El contenido de stdarg.h se usa normalmente en funciones variádicas, aunque se pueden usar en otras funciones (por ejemplo, vprintf) llamadas por funciones variádicas.

**Declarar funciones variádicas**
Las funciones variádicas son funciones que pueden tomar un número variable de argumentos y se declaran con puntos suspensivos en lugar del último parámetro. Un ejemplo de tal función es printf. Una declaración típica es:
```
int  check(int  a,  double  b,  ...);
```
Las funciones variádicas deben tener al menos un parámetro con nombre, por lo que, por ejemplo,
```
char  *wrong(...);
```
no está permitido en C. (En C++, tal declaración está permitida). En C, una coma debe preceder a los puntos suspensivos; en C++, es opcional.

**Definición de funciones variádicas**
La misma sintaxis se utiliza en una definición:
```
long  func(char,  double,  int,  ...);

long  func(char  a,  double  b,  int  c,  ...)
{
  /* ... */
}
```
Es posible que los puntos suspensivos no aparezcan en las definiciones de funciones de estilo antiguo.
## stdarg.h types
|    Name            |Description                          |Compatibility                         |
|----------------|-------------------------------|-----------------------------|
|`[va_list]`            |tipo para iterar argumentos            | C89


## stdarg.h macros

|    Name            |Description                          |Compatibility                         |
|----------------|-------------------------------|-----------------------------|
|[va_start](http://en.cppreference.com/w/cpp/utility/variadic/va_start)            |Comience a iterar argumentos con una va_list            | C89
|[va_arg](http://en.cppreference.com/w/cpp/utility/variadic/va_arg)          |recuperar un argumento          |C89            |
|[va_end](http://en.cppreference.com/w/cpp/utility/variadic/va_end)          |Liberar una va_list|C89|
|[va_copy](http://en.cppreference.com/w/cpp/utility/variadic/va_copy)          |Copie el contenido de un va_list a otro|C99|

**Acceder a los argumentos**

Para acceder a los argumentos sin nombre, se debe declarar una variable de tipo va_list en la función variádica. A continuación, se llama a la macro va_start con dos argumentos: 
El primero es la variable declarada del tipo va_list.
El segundo es el nombre del último parámetro nombrado de la función. Después de esto, cada invocación de la macro va_arg genera el siguiente argumento.
El primer argumento de va_arg es va_list y el segundo es el tipo del siguiente argumento pasado a la función.
Finalmente, la macro va_end debe llamarse en va_list antes de que la función regrese. (No es necesario leer todos los argumentos).
C99 provides tienen adicional macro, va_copy, que puede duplicar el estado de va_list. The macro invocation va_copy(va2, va1) copias va1 into va2.
No hay ningún mecanismo definido para determinar el número o los tipos de argumentos sin nombre pasados ​​a la función. La función simplemente se requiere para saber o determinar esto de alguna manera, cuyos medios varían. Las convenciones comunes incluyen:

* Uso de una cadena de formato similar a printf o scanf con especificadores incrustados que indican tipos de argumentos. 
* Un valor centinela al final de los argumentos variados. 
* Un argumento de recuento que indica el número de argumentos variádicos.

## varargs.h
Las versiones obsoletas de POSIX definían el encabezado heredado varargs.h, que data de antes de la estandarización de C y proporciona una funcionalidad similar a stdarg.h.

Este encabezado no forma parte ni de ISO C ni de POSIX. El archivo, como se define en la segunda versión de Single UNIX Specification, simplemente contiene toda la funcionalidad de C89 stdarg.h, con la excepción de que:

* No se puede usar en las definiciones estándar de estilo nuevo de C.
* El argumento dado puede omitirse (el estándar C requiere al menos un argumento).
```
La interfaz también es diferente. Para el ejemplo de printargs, en su lugar se escribiría:

#include  <stdio.h>
#include  <varargs.h>

/* There is no "void" type; use an implicit int return. */
printargs(arg1,  va_alist)
  va_dcl  /* no semicolon here! */
{
  va_list  ap;
  int  i;

  va_start(ap);  
  for  (i  =  arg1;  i  >=  0;  i  =  va_arg(ap,  int))
  printf("%d ",  i);
  va_end(ap);
  putchar('\n');
  return;
}
```
y se llama de la misma manera.
**varargs.h** requiere definiciones de función de estilo antiguo debido a la forma en que funciona la implementación. Por el contrario, no es posible mezclar definiciones de funciones de estilo antiguo con **stdarg.h**.