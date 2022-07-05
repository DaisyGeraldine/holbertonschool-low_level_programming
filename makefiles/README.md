## ¿Qué es un Makefile y cómo funciona?
Ejecute y compile sus programas de manera más eficiente con esta práctica herramienta de automatización.
Si desea ejecutar o actualizar una tarea cuando se actualizan ciertos archivos, la utilidad de creación puede ser útil. La utilidad make requiere un archivo, Makefile (o makefile), que define el conjunto de tareas a ejecutar. Es posible que haya utilizado make para compilar un programa a partir del código fuente. La mayoría de los proyectos de código abierto usan make para compilar un binario ejecutable final, que luego se puede instalar usando make install.

**Ejemplos básicos**
Empecemos imprimiendo el clásico "Hello World" en el terminal. Cree un directorio vacío myproject que contenga un archivo Makefile con este contenido:
```
say_hello:  
echo  "Hello World"
```
Ahora ejecute el archivo escribiendo make dentro del directorio myproject. La salida será:
```
$ make  
echo  "Hello World"  
Hello World
```

En el ejemplo anterior, say_hello se comporta como un nombre de función, como en cualquier lenguaje de programación. Esto se llama el *target*. Los requisitos previos o las dependencias siguen al destino. Por el bien de la simplicidad, no hemos definido ningún requisito previo en este ejemplo. El comando echo "Hello World" se llama la *recipe*. La *recipe* utiliza requisitos previos para hacer un *target*. El *target*, los requisitos previos y las recipes forman una regla.