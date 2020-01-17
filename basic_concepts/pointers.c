#include <stdio.h>

int main (){

  /*int a;
  a = 1;

  //----------  pointers  -----------------------
  printf("----------  pointers  ----------------------- \n");

  int *pa;
  pa = &a;

  printf("value stored in a %i \n", *pa);
  printf("memory address of a %p  \n", pa);
  printf("memory address of pa %p  \n", &pa);

  /*
    p The argument shall be a pointer to void. The value of the 
    pointer is converted to a sequence of printing characters, 
    in an implementation-defined manner.


  // -------- moving through the memory address ---------
  printf("-------- moving through the memory address --------- \n");

  int b[3] = {1,2,3};

  printf("value in index 1 %i \n", *(b + 1));
  printf("memory address in index 1 %p\n", b + 1);

  // comparation with *(b + 1)
  printf("value in index 1 %i\n", b[1]);

  // -------- pointers to pointer ---------
  printf("-------- pointer to pointer --------- \n");
  // see https://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/
  int w = 3;
  int *pointerB1 = &w;
  int ** pointerToPointerB1 = &pointerB1;

  printf("variable w value %i \n", *pa);
  printf("memory address of pointerB1 %p  \n", pointerB1);
  printf("memory address of pa %p  \n", pointerToPointerB1); */

  int mi_arreglo[] = {1,23,17,4,-5,100};
  int *ptr;

  int i;
  ptr = &mi_arreglo[0]; /* apuntamos nuestro puntero
  al primer elemento del arreglo*/
  printf("\n\n");
  for (i = 0; i < 6; i++)
  {
    printf("mi_arreglo[%d] = %d ", i, mi_arreglo[i]); /*<-- A */
    printf("ptr + %d = %d\n", i, *(++ptr)); /*<-- B */
  }

  return 0;
}