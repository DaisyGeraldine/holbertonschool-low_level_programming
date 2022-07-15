# C - Singly linked lists
## ¿Qué es una estructura de datos?
Las estructuras de datos, como su término lo indica, son una forma de estructurar datos para almacenar, encontrar, usar y crear datos de manera eficiente, según la tarea en cuestión. Si los datos son un plato de comida, las estructuras de datos son sus utensilios (los algoritmos serían cómo usar efectivamente esos utensilios en esta analogía). De la misma manera que elegirá una cuchara para comer un plato de sopa en lugar de un cuchillo, con el tiempo aprenderá a seleccionar y utilizar correctamente estructuras de datos que se ajusten a la naturaleza de los datos con los que está trabajando. Cuando comience a aprender estructuras de datos básicas, como matrices y listas vinculadas, comenzará a conceptualizar cómo se almacenan, buscan y editan los datos, y qué contribuirán estas operaciones a la complejidad de espacio/tiempo de su programa en tiempo de ejecución (esto tendrá más sentido una vez que comience a aprender sobre la notación Big O). A medida que continúe aprendiendo estructuras de datos más complejas, puede notar que necesita pensar de manera más abstracta y deliberada para implementarlas correctamente. Pero con paciencia y práctica, comenzará a ver patrones que le permitirán ver intuitivamente qué situación requiere qué estructura de datos, tal como sabe tomar una cuchara cuando ve un plato de sopa.

## Linked lists
Las listas enlazadas son el mejor y más simple ejemplo de una estructura de datos dinámica que utiliza punteros para su implementación. Sin embargo, comprender los punteros es crucial para comprender cómo funcionan las listas vinculadas, por lo que si se ha saltado el tutorial de punteros, debe volver atrás y rehacerlo. También debe estar familiarizado con la asignación y las estructuras de memoria dinámica.

Esencialmente, las listas enlazadas funcionan como una matriz que puede crecer y reducirse según sea necesario, desde cualquier punto de la matriz.

Las listas enlazadas tienen algunas ventajas sobre las matrices:

 1. Los elementos se pueden agregar o eliminar del medio de la lista 
 2. No hay necesidad de definir un tamaño inicial

Sin embargo, las listas enlazadas también tienen algunas desventajas:
1. No hay acceso "aleatorio": es imposible llegar al enésimo elemento de la matriz sin iterar primero sobre todos los elementos hasta ese elemento.
2. Se requieren punteros y asignación de memoria dinámica, lo que complica el código y aumenta el riesgo de fugas de memoria y fallas de segmento.
3. Las listas vinculadas tienen una sobrecarga mucho mayor que las matrices, ya que los elementos de la lista vinculada se asignan dinámicamente (lo que es menos eficiente en el uso de la memoria) y cada elemento de la lista también debe almacenar un puntero adicional.
**¿Qué es una lista enlazada?**
Una lista enlazada es un conjunto de nodos asignados dinámicamente, dispuestos de tal manera que cada nodo contiene un valor y un puntero. El puntero siempre apunta al siguiente miembro de la lista. Si el puntero es NULL, entonces es el último nodo de la lista.
```c
    ------------------------------              ------------------------------
    |              |             |            \ |              |             |
    |     DATA     |     NEXT    |--------------|     DATA     |     NEXT    |
    |              |             |            / |              |             |
    ------------------------------              ------------------------------
```
Definamos un nodo de lista enlazada:
```c
typedef struct node {
    int val;
    struct node * next;
} node_t;
```
Tenga en cuenta que estamos definiendo la estructura de forma recursiva, lo cual es posible en C. Llamemos a nuestro tipo de nodo **node_t**.
Ahora podemos usar los nodos. Vamos a crear una variable local que apunte al primer elemento de la lista (llamado ***head***).
```c
node_t * head = NULL;
head = (node_t *) malloc(sizeof(node_t));
if (head == NULL) {
    return 1;
}

head->val = 1;
head->next = NULL;
```
Acabamos de crear la primera variable en la lista. Debemos establecer el valor y el siguiente elemento para que esté vacío, si queremos terminar de completar la lista. Tenga en cuenta que siempre debemos verificar si malloc devolvió un valor NULL o no.
Para agregar una variable al final de la lista, simplemente podemos continuar avanzando al siguiente puntero:
```c
node_t * head = NULL;
head = (node_t *) malloc(sizeof(node_t));
head->val = 1;
head->next = (node_t *) malloc(sizeof(node_t));
head->next->val = 2;
head->next->next = NULL;
```
Esto puede seguir y seguir, pero lo que deberíamos hacer es avanzar al último elemento de la lista, hasta que la siguiente variable sea NULL.
### Iterando sobre una lista
Construyamos una función que imprima todos los elementos de una lista. Para hacer esto, necesitamos usar un puntero actual que hará un seguimiento del nodo que estamos imprimiendo actualmente.

Después de imprimir el valor del nodo, establecemos el puntero actual en el siguiente nodo e imprimimos de nuevo, hasta llegar al final de la lista (el siguiente nodo es NULL).
```c
void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}
```
### Agregar un elemento al final de la lista
Para iterar sobre todos los miembros de la lista enlazada, usamos un puntero llamado ***current***. Lo configuramos para que comience desde el encabezado y luego, en cada paso, avanzamos el puntero al siguiente elemento de la lista, hasta llegar al último elemento.
```c
void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}
```
Los mejores casos de uso para las listas vinculadas son las **stack**(pilas) y las **queues**(colas), que ahora implementaremos:
### Agregar un elemento al principio de la lista (empujar a la lista)
```c
void push(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}
```
### Eliminar el primer elemento (saltar de la lista)
```c
int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}
```
### Eliminando el último elemento de la lista
```c
int remove_last(node_t * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;

}
```
### Eliminación de un elemento específico
```c
int remove_by_index(node_t ** head, int n) {
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    if (current->next == NULL) {
        return -1;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;

}
```
https://www.learn-c.org/en/Linked_lists