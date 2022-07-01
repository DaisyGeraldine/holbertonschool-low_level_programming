# C - Preprocessor
### Object-like Macros (Macros similares a objetos)
Una macro similar a un objeto es un identificador simple que será reemplazado por un fragmento de código. Se llama similar a un objeto porque parece un objeto de datos en el código que lo usa. Se utilizan más comúnmente para dar nombres simbólicos a constantes numéricas.

Las macros se crean con la directiva '#define'. '#define' es seguido por el nombre de la macro y luego la secuencia de tokens para la que debe ser una abreviatura, que se denomina de diversas formas como el cuerpo de la macro, la expansión o la lista de reemplazo. Por ejemplo,
```
 #define BUFFER_SIZE 1024
 ```
 define una macro llamada BUFFER_SIZE como una abreviatura del token 1024. Si en algún lugar después de esta directiva '#define' viene una instrucción C de la forma
 ```
 foo = (char *) malloc (BUFFER_SIZE);
  ```
entonces el preprocesador C reconocerá y expandirá la macro BUFFER_SIZE. El compilador de C verá los mismos tokens que vería si hubiera escrito
 ```
 foo = (char *) malloc (1024);
 ```
Por convención, los nombres de las macros se escriben en mayúsculas. Los programas son más fáciles de leer cuando es posible saber de un vistazo qué nombres son macros

El cuerpo de la macro termina al final de la línea '#define'. Puede continuar la definición en varias líneas, si es necesario, usando la barra invertida-nueva línea. Sin embargo, cuando se expande la macro, todo aparecerá en una sola línea. Por ejemplo,
 ```
  #define NUMBERS 1, \
                     2, \
                     3
     int x[] = { NUMBERS };
          ==> int x[] = { 1, 2, 3 };
 ```
La consecuencia visible más común de esto son los números de línea sorprendentes en los mensajes de error.

No hay restricciones sobre lo que puede ir en un cuerpo de macro, siempre que se descomponga en tokens de preprocesamiento válidos. Los paréntesis no necesitan balancearse, y el cuerpo no necesita parecerse a un código C válido. (Si no es así, es posible que reciba mensajes de error del compilador de C cuando utilice la macro).

**El preprocesador C** escanea su programa secuencialmente. Las definiciones de macro surten efecto en el lugar donde las escribe. Por lo tanto, la siguiente entrada al preprocesador C.
 ```
    foo = X;
     #define X 4
     bar = X;
 ```
produce
 ```
    foo = X;
    bar = 4;
```
 Cuando el preprocesador expande el nombre de una macro, la expansión de la macro reemplaza la invocación de la macro, luego se examina la expansión en busca de más macros para expandir. Por ejemplo, 
```
     #define TABLESIZE BUFSIZE
     #define BUFSIZE 1024
     TABLESIZE
          ==> BUFSIZE
          ==> 1024  
```

TABLESIZE se expande primero para producir BUFSIZE, luego esa macro se expande para producir el resultado final, 1024.
Tenga en cuenta que BUFSIZE no se definió cuando se definió TABLESIZE. El '#define' para TABLESIZE utiliza exactamente la expansión que especifique, en este caso, BUFSIZE y no comprueba si también contiene nombres de macros. Solo cuando usa TABLESIZE, el resultado de su expansión se escanea en busca de más nombres de macros.

Esto marca la diferencia si cambia la definición de BUFSIZE en algún punto del archivo fuente. TABLESIZE, definido como se muestra, siempre se expandirá usando la definición de BUFSIZE que está actualmente en vigor:
```
     #define BUFSIZE 1020
     #define TABLESIZE BUFSIZE
     #undef BUFSIZE
     #define BUFSIZE 37
```
Now `TABLESIZE` expands (in two stages) to `37`.

Si la expansión de una macro contiene su propio nombre, ya sea directamente o mediante macros intermedias, no se vuelve a expandir cuando se examina la expansión en busca de más macros. Esto evita la recursividad infinita. Ver [Self-Referential Macros](https://gcc.gnu.org/onlinedocs/gcc-5.1.0/cpp/Self-Referential-Macros.html#Self-Referential-Macros), para los detalles precisos.

### Argumentos macros
Las macros similares a funciones pueden tomar argumentos, al igual que las funciones verdaderas. Para definir una macro que usa argumentos. Inserte parámetros entre el par de paréntesis en la definición de macro que hacen que la macro funcione como. Los parámetros deben ser identificadores C válidos, separados por comas y, opcionalmente, espacios en blanco.

Para invocar una macro que toma argumentos, escribe el nombre de la macro seguido de una lista de argumentos reales entre paréntesis, separados por comas. La invocación de la macro no necesita estar restringida a una sola línea lógica puede cruzar tantas líneas en el archivo fuente como desee. La cantidad de argumentos que proporcione debe coincidir con la cantidad de parámetros en la definición de la macro. Cuando la macro se expande, cada uso de un parámetro en su cuerpo se reemplaza por los tokens del argumento correspondiente. (No necesita usar todos los parámetros en el cuerpo de la macro).

Como ejemplo, aquí hay una macro que calcula el mínimo de dos valores numéricos, como se define en muchos programas C, y algunos usos.
```
#define min(X, Y)  ((X) < (Y) ? (X) : (Y))
x = min(a, b);   ==>  x = ((a) < (b) ? (a) : (b));
y = min(1, 2);   ==>  y = ((1) < (2) ? (1) : (2));
z = min(a + 28, *p);==>  z = ((a + 28) < (*p) ? (a + 28) : (*p));
```
(En este pequeño ejemplo ya puedes ver varios de los peligros de los argumentos macro. Ver [Macro Pitfalls](https://gcc.gnu.org/onlinedocs/gcc-5.1.0/cpp/Macro-Pitfalls.html#Macro-Pitfalls), para obtener explicaciones detalladas).

Se eliminan los espacios en blanco iniciales y finales de cada argumento, y todos los espacios en blanco entre los tokens de un argumento se reducen a un solo espacio. Los paréntesis dentro de cada argumento deben equilibrarse; una coma entre paréntesis no termina el argumento. Sin embargo, no hay ningún requisito de equilibrio entre corchetes o llaves, y no impiden que una coma separe los argumentos. De este modo,
```
macro (array[x = y, x + 1])
```
pasa dos argumentos a macro: array[x = y y x + 1]. Si desea proporcionar array[x = y, x + 1] como argumento, puede escribirlo como array[(x = y, x + 1)], que es el código C equivalente.
Todos los argumentos de una macro se amplían completamente antes de sustituirlos en el cuerpo de la macro. Después de la sustitución, el texto completo se escanea nuevamente en busca de macros para expandir, incluidos los argumentos. Esta regla puede parecer extraña, pero está cuidadosamente diseñado para que no tenga que preocuparse de si alguna llamada de función es en realidad una invocación de macro. Sin embargo, puedes tener problemas si intentas ser demasiado inteligente. Ver [Argument Prescan](https://gcc.gnu.org/onlinedocs/gcc-5.1.0/cpp/Argument-Prescan.html#Argument-Prescan), para una discusión detallada.
```
For example,  `min (min (a, b), c)`  is first expanded to

  min (((a) < (b) ? (a) : (b)), (c))

and then to

   ((((a) < (b) ? (a) : (b))) < (c)
    ? (((a) < (b) ? (a) : (b)))
    : (c))
 ```
(Los saltos de línea que se muestran aquí para mayor claridad en realidad no se generarían).

Puede dejar los argumentos de macro vacíos; esto no es un error del preprocesador (pero muchas macros se expandirán a un código no válido). No puede dejar de lado los argumentos por completo; si una macro toma dos argumentos, debe haber exactamente una coma en el nivel superior de su lista de argumentos. Aquí hay algunos ejemplos tontos usando min:
 ```
     min(, b)        => ((   ) < (b) ? (   ) : (b))
     min(a, )       => ((a  ) < ( ) ? (a  ) : ( ))
     min(,)          => ((   ) < ( ) ? (   ) : ( ))
     min((,),)       => (((,)) < ( ) ? ((,)) : ( ))
     
     min()      error--> macro "min" requires 2 arguments, but only 1 given
     min(,,)    error--> macro "min" passed 3 arguments, but takes just 2
```
El espacio en blanco no es un token de preprocesamiento, por lo que si una macro foo toma un argumento, foo () y foo ( ) le proporcionan un argumento vacío.

Las implementaciones y la documentación previas del preprocesador GNU eran incorrectas en este punto, insistiendo en que una macro similar a una función que toma un solo argumento pasara un espacio si se requería un argumento vacío.

Los parámetros de macro que aparecen dentro de los literales de cadena no se reemplazan por sus argumentos reales correspondientes.
```
     #define foo(x) x, "x"
     foo(bar)        ==> bar, "x"
```

### 3.7.1 Macros estándar predefinidas

Las macros estándar predefinidas están especificadas por los estándares de lenguaje relevantes, por lo que están disponibles con todos los compiladores que implementan esos estándares. Es posible que los compiladores más antiguos no los proporcionen todos. Todos sus nombres comienzan con guiones bajos dobles.

`__ FILE __` Esta macro se expande al nombre del archivo de entrada actual, en forma de una constante de cadena C. Esta es la ruta por la que el preprocesador abrió el archivo, no el nombre abreviado especificado en '#include' o como argumento del nombre del archivo de entrada. Por ejemplo, "/usr/local/include/myheader.h" es una posible expansión de esta macro.

`__ LINE __` Esta macro se expande al número de línea de entrada actual, en forma de una constante entera decimal. Si bien lo llamamos macro predefinida, es una macro bastante extraña, ya que su "definición" cambia con cada nueva línea de código fuente.
`__FILE__` y `__LINE__` son útiles para generar un mensaje de error para informar una inconsistencia detectada por el programa; el mensaje puede indicar la línea de origen en la que se detectó la incoherencia. Por ejemplo.
```
fprintf (stderr, "Internal error: "
                   "negative string length "
                   "%d at %s, line %d.",
              length, __FILE__, __LINE__);
```
Saber mas sobre : [Standard Predefined Macros](
https://gcc.gnu.org/onlinedocs/gcc-5.1.0/cpp/Standard-Predefined-Macros.html#Standard-Predefined-Macros)

### 3.7.2 Macros predefinidas comunes
Las macros predefinidas comunes son extensiones GNU C. Están disponibles con los mismos significados independientemente de la máquina o el sistema operativo en el que esté utilizando GNU C o GNU Fortran. Todos sus nombres comienzan con guiones bajos dobles.

`__ COUNTER __`
Esta macro se expande a valores integrales secuenciales a partir de 0. Junto con el operador ##, esto proporciona un medio conveniente para generar identificadores únicos.  Se debe tener cuidado para garantizar que __ COUNTER __ no se expanda antes de la inclusión de encabezados precompilados que lo utilizan. De lo contrario, no se utilizarán los encabezados precompilados.

`__GFORTRAN__` El compilador GNU Fortran define esto.
`__GNUC__`

`__GNUC_MINOR__`

`__GNUC_PATCHLEVEL__`

Saber mas sobre : [Common Predefined Macros](https://gcc.gnu.org/onlinedocs/gcc-5.1.0/cpp/Common-Predefined-Macros.html#Common-Predefined-Macros)

## El preprocesador C
El preprocesador C modifica un archivo de código fuente antes de entregarlo al compilador. Lo más probable es que esté acostumbrado a usar el preprocesador para incluir archivos directamente en otros archivos, o #define constantes, pero el preprocesador también se puede usar para crear código "en línea" usando macros expandidas en tiempo de compilación y para evitar que el código se compile dos veces.

Hay esencialmente tres usos del preprocesador: directivas, constantes y macros. Las directivas son comandos que le dicen al preprocesador que omita parte de un archivo, incluya otro archivo o defina una constante o macro. Las directivas siempre comienzan con un signo nítido (#) y para facilitar la lectura deben colocarse al ras a la izquierda de la página. Todos los demás usos del preprocesador implican el procesamiento de macros o constantes #definidas. Por lo general, las constantes y las macros se escriben TODO EN MAYÚSCULAS para indicar que son especiales (como veremos).

### Header Files (Archivos de encabezado)
La directiva #include le dice al preprocesador que tome el texto de un archivo y lo coloque directamente en el archivo actual. Por lo general, tales declaraciones se colocan en la parte superior de un programa, de ahí el nombre de "archivo de encabezado" para los archivos así incluidos.

### Constants
si escribimos
`#define [identifier name] [value]`
`#define PI_PLUS_ONE (3.14 + 1)`
`x = PI_PLUS_ONE * 5;`
`x = 3.14 + 1 * 5;`
`#define [identifier name]`

### Conditional Compilation (compilación condicional)
Hay un conjunto completo de opciones que se pueden usar para determinar si el preprocesador eliminará líneas de código antes de entregar el archivo al compilador. Incluyen #if, #elif, #else, #ifdef y #ifndef. Un bloque #if o #if/#elif/#else o un bloque #ifdef o #ifndef debe terminar con un #endif de cierre.
La directiva #if toma un argumento numérico que se evalúa como verdadero si es distinto de cero. Si su argumento es falso, se excluirá el código hasta el cierre #else, #elif, de #endif.
**Comentando el código**
La compilación condicional es una forma particularmente útil de comentar un bloque de código que contiene comentarios de varias líneas (que no se pueden anidar).
```
#if 0
/* comment ...
*/
// code
/* comment */
#endif
```
### Include Guards (Incluir guardias)
Otro problema común es que se requiere un archivo de encabezado en muchos otros archivos de encabezado que luego se incluyen en un archivo de código fuente, con el resultado a menudo de que las variables, estructuras, clases o funciones parecen estar definidas varias veces (una vez por cada vez que se incluya el archivo de cabecera). Esto puede resultar en muchos dolores de cabeza en tiempo de compilación. Afortunadamente, el preprocesador proporciona una técnica sencilla para garantizar que cualquier archivo determinado se incluya una sola vez.

Al usar la directiva #ifndef, puede incluir un bloque de texto solo si una expresión en particular no está definida; luego, dentro del archivo de encabezado, puede definir la expresión.
```
#ifndef _FILE_NAME_H_
#define _FILE_NAME_H_
/* code */
#endif // #ifndef _FILE_NAME_H
```
Tenga en cuenta que no es necesario dar un valor a la expresión _FILE_NAME_H_. Es suficiente incluir la línea "#define _FILE_NAME_H_" para que sea "definido". (Tenga en cuenta que hay una n en #ifndef, que significa "si no está definido").
Se puede usar una táctica similar para definir constantes específicas, como NULL:
```
#ifndef NULL
#define NULL (void *)0
#endif // #ifndef NULL
```
Tenga en cuenta que es útil comentar qué declaración condicional termina un #endif en particular. Esto es particularmente cierto porque las directivas del preprocesador rara vez tienen sangría, por lo que puede ser difícil seguir el flujo de ejecución.

En muchos compiladores, el [#pragma once](https://www.cprogramming.com/reference/preprocessor/pragma.html) La directiva se puede usar en lugar de include guards.

## Macros
El otro uso principal del preprocesador es definir macros. La ventaja de una macro es que puede ser de tipo neutral (esto también puede ser una desventaja, por supuesto) y está insertado directamente en el código, por lo que no hay ninguna sobrecarga de llamada de función. (Tenga en cuenta que en C++, es posible solucionar ambos problemas con funciones con plantilla y la palabra clave en línea).

Una definición de macro suele tener la siguiente forma:
```
#define MACRO_NAME(arg1, arg2, ...) [code to expand to]
```
Por ejemplo, una macro de incremento simple podría verse así:
```
#define MULT(x, y) (x) * (y)
```
otro ejemplo
```
#define ADD_FIVE(a) ((a) + 5)
```
Por otro lado, si tiene una macro de varias líneas que está utilizando para sus efectos secundarios, en lugar de calcular un valor, probablemente desee envolverla entre llaves para que no tenga problemas al usarla después de una instrucción if. .
```
// We use a trick involving exclusive-or to swap two variables
#define SWAP(a, b) a ^= b; b ^= a; a ^= b;
int x = 10;
int y = 5;
/ works OK
SWAP(x, y);
// What happens now?
if (x < 0)
SWAP(x, y);
```
### More Gotchas (Más problemas)
A estas alturas, probablemente te hayas dado cuenta de por qué a la gente no le gusta usar macros. Son peligrosos, son exigentes y simplemente no son tan seguros. Quizás el problema más irritante con las macros es que no desea pasar argumentos con "efectos secundarios" a las macros. Por efectos secundarios, me refiero a cualquier expresión que haga algo además de evaluar un valor. Por ejemplo, ++x se evalúa como x+1, pero también incrementa x. Esta operación de incremento es un efecto secundario.

El problema con los efectos secundarios es que las macros no evalúan sus argumentos; simplemente los pegan en el texto de la macro al realizar la sustitución. Entonces algo como
```
#define MAX(a, b) ((a) < (b) ? (b) : (a))
int x = 5, y = 10;
int z = MAX(x++, y++);
```
terminará luciendo así:
```
int  z = (x++ < y++ ? y++ : x++)
```
¡El problema aquí es que y++ termina siendo evaluado dos veces! La desagradable consecuencia es que después de esta expresión, y tendrá un valor de 12 en lugar del esperado 11. ¡Esto puede ser un verdadero dolor de cabeza!

## Multiline macros (Macros multilínea)

Hasta ahora, solo hemos visto macros cortas de una línea (posiblemente aprovechando el punto y coma para poner varias declaraciones en una línea). Resulta que al usar "\" para indicar una continuación de línea, podemos escribir nuestras macros en varias líneas para que sean un poco más legibles.
Por ejemplo, podríamos reescribir swap como
```
#define SWAP(a, b) { \
a ^= b; \
b ^= a; \
a ^= b; \
```
¡Observe que no necesita una barra oblicua al final de la última línea! La barra inclinada le dice al preprocesador que la macro continúa en la línea siguiente, no que la línea es una continuación de una línea anterior.

Aparte de la legibilidad, escribir macros de varias líneas puede hacer que sea más obvio que necesita usar llaves para rodear el cuerpo porque es más claro que se están produciendo múltiples efectos a la vez.

## Advanced Macro Tricks (Trucos avanzados de macros)
Además de la sustitución simple, el preprocesador también puede realizar un poco de trabajo adicional en argumentos de macro, como convertirlos en cadenas o pegarlos.

### Pasting Tokens (Pegar fichas)
Cada argumento que se pasa a una macro es un token y, a veces, puede ser conveniente pegar los argumentos para formar un nuevo token. Esto podría ser útil si tiene una estructura complicada y desea depurar su programa imprimiendo diferentes campos. En lugar de escribir toda la estructura cada vez, puede usar una macro para pasar el campo de la estructura para imprimir.
Para pegar tokens en una macro, use ## entre las dos cosas para pegarlas.

Por ejemplo
```
#define BUILD_FIELD(name) my_struct.inner_struct.union_a.field_##name
```
Ahora, cuando se usa con un nombre de campo en particular, se expandirá a algo como
```
my_struct.inner_struct.union_a.field_field1
```
Las fichas están literalmente pegadas.
### String-izing Tokens (Tokens de cadenas)
Otra opción de macro potencialmente útil es convertir un token en una cadena que contenga el texto literal del token. Esto podría ser útil para imprimir el token. La sintaxis es simple: simplemente prefije el token con un signo de libra (#).
```
#define PRINT_TOKEN(token) printf(#token " is %d", token)
```
Por ejemplo, PRINT_TOKEN(foo) se expandiría a
```
printf``(``"<foo>"`  `" is %d"`  `<foo>)
```
(Tenga en cuenta que en C, los literales de cadena uno al lado del otro están concatenados, por lo que algo como "token" "is" "this" se convertirá efectivamente en "token is this". Esto puede ser útil para formatear declaraciones printf).

Por ejemplo, puede usarlo para imprimir el valor de una expresión, así como la expresión en sí (para fines de depuración).
```
PRINT_TOKEN(x + y);
```
**Otra pagina include guard**
https://en.wikipedia.org/wiki/Include_guard