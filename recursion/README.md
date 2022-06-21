# Programación iterativa

La iteración en computación es la repetición de un bloque de declaraciones dentro de una computadora programa (usando un bucle).

**La recursividad** es un método en el que
la solución a un problema depende de las soluciones a los más pequeños instancias del mismo problema.
Una función recursiva es una función que se llama a sí misma.

**Iteration**
5! = 5 * 4  *3 * 2 * 1
5! = 5 * 4 * 3 * 2
5! = 5 * 4 * 6
5! = 5 * 24
5! = 120
```
#include<stdio.h>
int factorial(int n)
{
     int res;
     int i;
     res = 1;
     i = 1;

     while(i<=n)
    {
          res = res * i;
          i++;
     }
     return(res);
}
int main(void)
{
     int f;
     f = factorial(5);
     printf("5!=%d\n",f);
     return (0);
}
```
**Recursión**
5! = 5 * 4!
4! = 4 * 3!
3! = 3 * 2!
2! = 2 * 1!
1! = 1 * 0!
0! = 1
```
#include <stdio.h>
int factorial(int n)
{
    if (n == 0)
    {
      return (1);
    }
    return (n * factorial(n - 1));
}
int main(void)
{
    int f;
    f=factorial(5);
    printf("5!=%d\n",f);
    return(0);
}
```
**Iterative**
```
#include<unistd.h>
void print_char(char c)
{
  write(1,&c,1);
}
void print_alphabet(void)
{
  char c;
  c='a';
  while(c <= 'z')
  {
    print_char(c);
    c = c+1;
  }
}
int main(void)
{
  print_alphabet();
  print_char('\n');
  return(0);
}
```