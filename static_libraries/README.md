# ¿Qué es una biblioteca y para qué sirve?

Una biblioteca es una colección de rutinas de código (funciones, clases, variables, etc.). Eso se puede utilizar al construir nuestro programa, por lo que en lugar de escribirlo nosotros mismos, podemos ir y obtenerlo de algo que ya ha sido escrito y optimizado.
Básicamente, tenemos dos tipos de bibliotecas: 
* bibliotecas estáticas / (static libraries)
* bibliotecas compartidas (o dinámicas) / shared (or dynamic) libraries

*La principal razón para escribir una biblioteca es permitir la reutilización del código y, por lo tanto, ahorrar un tiempo de desarrollo considerable.*

## ¿Qué es una biblioteca estática y cómo funciona?

Una biblioteca estática es un archivo que contiene una colección de archivos de objetos (*.o) que se vinculan al programa durante la fase de vinculación de la compilación y no son relevantes durante el tiempo de ejecución.

[Imagen de referencia](https://res.cloudinary.com/practicaldev/image/fetch/s--m6UdcE24--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://dev-to-uploads.s3.amazonaws.com/i/l38vk6qbwisj20wzcbjz.PNG)

Como se muestra en el diagrama anterior, cuando se compila un programa, el compilador genera un archivo de objeto a partir de un archivo fuente. Después de generar el archivo de objeto, el compilador también invoca al Linker. La función del enlazador, en este caso, es copiar el código de la biblioteca a nuestro archivo objeto.

Básicamente, las bibliotecas estáticas son solo una colección de archivos de objetos que el enlazador fusiona con otro archivo de objetos para formar un ejecutable final.

Convencionalmente, comienzan con "lib" y terminan con ".a" o ".lib" (dependiendo de su plataforma).

**¿Cómo crear bibliotecas estáticas?**
Para crear una biblioteca estática, debemos especificarle al compilador, que es GCC en nuestro caso, que queremos compilar todos los códigos de la biblioteca (*.c) en archivos de objetos (*.o) sin vincular. Para hacer eso, vamos a usar el siguiente comando.

```
$ gcc -c -Wall -Werror -Wextra *.c
```
Descripción de las banderas: -c: compila y ensambla, pero no vincula. -Wall, -Werro y -Wextra: 
No son necesarios pero se recomiendan para generar mejor código.
Tenga en cuenta que "*.c" coincide con todos los archivos en el directorio de trabajo actual con la extensión ".c".
```
~/static_libs
→ls
add.c header.h mul.c
~/static_libs
→gcc -c -Wall-Wextra -Werror -pedantic*.c
~/static_libs
→ls
add.c add.o header.h mul.c mul.o
~/static_libs
→
```
Una vez que tengamos los archivos de objetos, ahora podemos agrupar todos los archivos de objetos en una biblioteca estática.

Para crear una biblioteca estática o agregar archivos de objetos adicionales a una biblioteca estática existente, debemos usar el programa GNU [ar](https://man7.org/linux/man-pages/man1/ar.1.html) (archivador). Podemos usar un comando como este:
```
$ ar -rc libname.a *.o
```
Este comando crea una biblioteca estática llamada "libname.a" y coloca copias de los archivos de objeto "add.o" y "mul.o" en ella. El indicador 'c' le dice a ar que cree la biblioteca si aún no existe. El indicador 'r' le dice que inserte archivos de objetos o reemplace los archivos de objetos existentes en la biblioteca, con los nuevos archivos de objetos.