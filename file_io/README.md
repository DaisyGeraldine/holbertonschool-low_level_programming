# File descriptor
En los sistemas operativos de computadora Unix y similares a Unix, un descriptor de archivo **(file descriptor)** (**FD**, con menos frecuencia **fildes**) es un identificador único (manejador) para un archivo u otro recurso de entrada/salida, como una tubería o un conector de red.

Los descriptores de archivo suelen tener valores enteros no negativos, y los valores negativos se reservan para indicar "sin valor" o condiciones de error.

Los descriptores de archivos son parte de la **API POSIX.** Cada proceso de Unix (excepto quizás los demonios) debe tener tres descriptores de archivo POSIX estándar, correspondientes a los tres flujos estándar:

| Integer value |Name    |<[unistd.h](https://en.wikipedia.org/wiki/Unistd.h "Unistd.h")> symbolic constant[[](https://en.wikipedia.org/wiki/File_descriptor#cite_note-1)    | <[stdio.h](https://en.wikipedia.org/wiki/Stdio.h "Stdio.h")> file stream[[2]](https://en.wikipedia.org/wiki/File_descriptor#cite_note-2) |
|----------------|-------------------------------|-----------------------------|--------|
|0|[Standard input](https://en.wikipedia.org/wiki/Stdin "Stdin")            |STDIN_FILENO |stdin|
|1|[Standard output](https://en.wikipedia.org/wiki/Stdout "Stdout")            |STDOUT_FILENO | stdout|
|2 |[Standard error](https://en.wikipedia.org/wiki/Stderr "Stderr")|STDERR_FILENO|stderr |

The **Portable Operating System Interface** (**POSIX**)

## dprintf()
Escribir la salida en un archivo asociado con un descriptor de archivo

**Synopsis:**
```c
#include <stdio.h>
int dprintf( int filedes, 
             const char* format, 
             ... );
```
### Argumentos:

***filedes***
Un descriptor de archivo que está asociado con el archivo al que desea enviar la salida.

***format***
Una cadena que especifica el formato de la salida. La cadena de formato determina qué argumentos adicionales debe proporcionar. Para obtener más información, consulte [printf()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/p/printf.html "Write formatted output to stdout").

### Library:
***libc***
Utilice la opción -l c de qcc para enlazar con esta biblioteca. Esta biblioteca suele incluirse automáticamente.

***Description***
La función dprintf() escribe la salida en el archivo asociado con el descriptor de archivo filedes, bajo el control del especificador de formato.

***Returns***
El número de caracteres escritos, o un valor negativo si se produjo un error de salida (se establece [errno](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/e/errno.html "Thread-local error variable")).
***Classification***
[POSIX 2008](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/summary.html#summary__CLASSIFICATION)
|      Safety |ASCII    |
|-------------|---------|
|Cancellation point|Yes |
|Interrupt handler |No |
|Signal handler |Yes|
|Thread |Yes|


## open(),  open64()
abrir un archivo
**Synopsis:**
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open( const char * path,
          int oflag, 
          ... );

int open64( const char * path, 
            int oflag, 
            ... );
```
### Arguments:

***path***
El nombre de ruta del archivo que desea abrir.

***oflag***
Indicadores que especifican el estado y los modos de acceso del archivo; vea abajo.

Si establece O_CREAT en oflag, también debe especificar el siguiente argumento:

***mode_t  mode***
Un objeto de tipo mode_t que especifica el modo de acceso que desea usar para un archivo recién creado. Para obtener más información, consulte la entrada de  [struct stat](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/s/stat_struct.html "Data structure for information about a file or directory"), y la descripción de [O_CREAT](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/o/open.html#open__O_CREAT), abajo.

### Library:

***libc***

Utilice la opción -l c de qcc para enlazar con esta biblioteca. Esta biblioteca suele incluirse automáticamente.

### Description:

Las funciones open() y open64() abren el archivo nombrado por ruta, creando una descripción de archivo abierto que hace referencia al archivo y un descriptor de archivo que hace referencia a la descripción del archivo. La función open64() es una versión compatible con archivos grandes de open(). Si el tamaño del archivo es mayor que el valor máximo que se puede representar correctamente en un off_t, debe usar open64().

El descriptor de archivo abierto creado es nuevo y, por lo tanto, no se comparte con ningún otro proceso del sistema.
Los indicadores de estado del archivo y los modos de acceso al archivo de la descripción del archivo abierto se establecen de acuerdo con el valor de oflag. Construya el valor de oflag mediante valores OR bit a bit de la siguiente lista, definida en el archivo de encabezado <fcntl.h>. Debe especificar exactamente uno de los siguientes modos de acceso a archivos en el valor de oflag:

**O_RDONLY**  Abierto solo para lectura.
**O_RDWR** Abierto para leer y escribir. No se admite la apertura de FIFO para lectura y escritura.
**O_WRONLY** Abierto solo para escribir.
También puede especificar cualquier combinación de las banderas restantes en el valor de oflag:
**O_APPEND** Si se establece, el desplazamiento del archivo se establece al final del archivo antes de cada escritura.
**O_ASYNC** (Extensión QNX Neutrino) No compatible actualmente.
**O_CLOEXEC** Cierre el descriptor de archivo si el programa llama a una de las funciones exec*(), posix_spawn*() o spawn*(). Esta bandera es un atajo que equivale a llamar a fcntl() con F_SETFD y FD_CLOEXEC después de abrir el archivo.
**O_CREAT** Esta opción requiere un tercer argumento, modo, que es de tipo modo_t. Si el archivo existe, esta bandera no tiene efecto, excepto en combinación con O_EXCL como se indica a continuación.

*Las funciones open() y open64() son **funciones** **varargs**. Si especifica O_CREAT pero no proporciona un argumento de modo, usan lo que esté en la pila como modo*

### Returns:

Un entero no negativo que representa el descriptor de archivo no utilizado con el número más bajo. En un archivo capaz de buscar, el desplazamiento del archivo se establece al principio del archivo. De lo contrario, se devuelve -1 ([errno](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/e/errno.html "Thread-local error variable")  está establecido).

[*Open(2) — Linux manual page* ](https://man7.org/linux/man-pages/man2/open.2.html)
[*Fuente - más informacion* ](https://www.qnx.com/developers/docs/7.1/index.html#com.qnx.doc.neutrino.lib_ref/topic/o/open.html)

### Examples:
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main( void )
  {
    int fd;

    /* open a file for output              */
    /* replace existing file if it exists  */
    /* with read/write perms for owner     */

    fd = open( "myfile.dat",
        O_WRONLY | O_CREAT | O_TRUNC,
        S_IRUSR | S_IWUSR );

    /* read a file that is assumed to exist */

    fd = open( "myfile.dat", O_RDONLY );

    /* append to the end of an existing file  */
    /* write a new file if file doesn't exist */
    /* with full read/write permissions       */

    fd = open( "myfile.dat",
        O_WRONLY | O_CREAT | O_APPEND,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP
        | S_IROTH | S_IWOTH );
    return EXIT_SUCCESS;
  }
  ```

## write()
Escribir bytes en un archivo
### Synopsis:
```c
#include <unistd.h>

ssize_t write( int filedes,
               const void* buf,
               size_t nbytes );
```
### Arguments:

***filedes***
El descriptor de archivo para el archivo que desea escribir.

***buf***
Un puntero a un búfer que contiene los datos que desea escribir.

***nbytes***
El número de bytes a escribir. Si nbytes es cero, write() devuelve cero y no tiene ningún otro efecto. Si nbytes es mayor que SSIZE_MAX - sizeof(io_write_t) (consulte <limits.h>), write() devuelve -1 y establece errno en EOVERFLOW.

### Library:

***libc***
Utilice la opción -l c de qcc para enlazar con esta biblioteca. Esta biblioteca suele incluirse automáticamente.

### Description:

La función **write()** intenta escribir nbytes bytes en el archivo asociado con el descriptor de archivo abierto, filedes, desde el búfer al que apunta buf.

En un archivo regular u otro archivo capaz de buscar, y si O_APPEND no está configurado, write() comienza en una posición en el archivo dada por el desplazamiento del archivo asociado con los archivos. Si se establece O_APPEND, el desplazamiento del archivo se establece al final del archivo antes de cada operación de escritura. Antes de regresar con éxito de write(), el desplazamiento del archivo se incrementa por el número de bytes realmente escritos. En un archivo normal, si este desplazamiento de archivo incrementado es mayor que la longitud del archivo, la longitud del archivo se establece en este desplazamiento de archivo.

> Tenga en cuenta que la llamada **write()** ignora los bloqueos de aviso que puede haber establecido la función fcntl().

### Returns:
El número de bytes escritos, o -1 si ocurrió un error ([errno](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/e/errno.html "Thread-local error variable")  está establecido).

[Más información ](https://www.qnx.com/developers/docs/7.1/index.html#com.qnx.doc.neutrino.lib_ref/topic/w/write.html)
[write(2) — Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html)

### Examples:
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

char buffer[] = { "A text record to be written" };

int main( void )
{
    int  fd;
    int  size_written;

    /* open a file for output          */
    /* replace existing file if it exists */
    fd = creat( "myfile.dat", S_IRUSR | S_IWUSR );

    /* write the text              */
    size_written = write( fd, buffer,
              sizeof( buffer ) );

    /* test for error              */
    if( size_written != sizeof( buffer ) ) {
        perror( "Error writing myfile.dat" );
        return EXIT_FAILURE;
    }

    /* close the file              */
    close( fd );

    return EXIT_SUCCESS;
}
```

## read()
Leer bytes de un archivo
## Synopsis:
```c
#include <unistd.h>

ssize_t read( int filedes,
              void* buf,
              size_t nbytes );
```
### Arguments:

***filedes***
El descriptor del archivo del que desea leer.

***buf***
Un puntero a un búfer donde la función puede almacenar los datos que lee.

***nbytes***
El número de bytes que desea leer. Si nbytes es cero, read() devuelve cero y no tiene ningún otro efecto. Si nbytes es mayor que SSIZE_MAX (consulte <limits.h>), la función devuelve -1 y establece errno en EOVERFLOW. Biblioteca:

### Library:

***libc***
use la opción -l c de qcc para enlazar con esta biblioteca. Esta biblioteca suele incluirse automáticamente.

### Description
La función read() intenta leer nbytes bytes del archivo asociado con el descriptor de archivo abierto, filedes, en el búfer al que apunta buf.
En un archivo regular u otro archivo capaz de buscar, read() comienza en una posición en el archivo dada por el desplazamiento del archivo asociado con filedes. Antes de regresar con éxito de read(), el desplazamiento del archivo se incrementa por el número de bytes realmente leídos.

> La llamada **read()** ignora los bloqueos de aviso que puede haber establecido con [fcntl()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/f/fcntl.html "Provide control over an open file").

### Returns:

El número de bytes realmente leídos, o -1 ([errno](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/e/errno.html "Thread-local error variable")  está establecido).
```c
### Examples:
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main( void )
{
    int fd;
    int size_read;
    char buffer[80];

    /* Open a file for input */
    fd = open( "myfile.dat", O_RDONLY );

    /* Read the text */
    size_read = read( fd, buffer,
                      sizeof( buffer ) );

    /* Test for error */
    if( size_read == -1 ) {
        perror( "Error reading myfile.dat" );
        return EXIT_FAILURE;
    }

    /* Close the file */
    close( fd );
    
    return EXIT_SUCCESS;
}
```

[Más información](https://www.qnx.com/developers/docs/7.1/index.html#com.qnx.doc.neutrino.lib_ref/topic/r/read.html)
[read(2) — Linux manual page](https://man7.org/linux/man-pages/man2/read.2.html)

# close()
cerrar un archivo
### Synopsis:
```c
#include <unistd.h>

int close( int filedes );
```
### Arguments:

***filedes***
El descriptor de archivo del archivo que desea cerrar. Este puede ser un descriptor de archivo devuelto por una llamada exitosa a  [accept()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/a/accept.html "Accept a connection on a socket"),  [creat()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/c/creat.html "Create and open a file (low-level)"),  [dup()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/d/dup.html "Duplicate a file descriptor"),  [dup2()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/d/dup2.html "Duplicate a file descriptor, specifying the new descriptor"),  [fcntl()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/f/fcntl.html "Provide control over an open file"),  [modem_open()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/m/modem_open.html "Open a serial port"),  [open()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/o/open.html "Open a file"),  [shm_open()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/s/shm_open.html "Open a shared memory object based on a pathname"),  [socket()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/s/socket.html "Create an endpoint for communication")  or  [sopen()](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/s/sopen.html "Open a file for shared access").

### Library:

***libc***
Utilice la opción -l c de qcc para enlazar con esta biblioteca. Esta biblioteca suele incluirse automáticamente.

### Description:

La función close() cierra el archivo especificado por el descriptor de archivo dado.

### Returns:

Cero para éxito, o -1 si ocurre un error ([errno](https://www.qnx.com/developers/docs/7.1/com.qnx.doc.neutrino.lib_ref/topic/e/errno.html "Thread-local error variable")  está establecido).

### Errors:

**EBADF** Descriptor de archivo no válido.

**EINTR** La llamada close() fue interrumpida por una señal. En la implementación de QNX Neutrino, el descriptor de archivo permanece abierto

**EIO** Se produjo un error de E/S al actualizar la información del directorio.

**ENOSPC** Una llamada de escritura almacenada en búfer anterior ha fallado.

**ENOSYS** La función close() no está implementada para el sistema de archivos especificado por filedes..

[close(2) — Linux manual page](https://man7.org/linux/man-pages/man2/close.2.html)

### Examples:
```c
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main( void )
{
    int filedes;

    filedes = open( "file", O_RDONLY );
    if( filedes != -1 ) {
        /* process file */
        close( filedes );

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
```