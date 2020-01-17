

## memory address
In computing, a memory address is a reference to a specific memory location used at various levels by software and hardware. Memory addresses are fixed-length sequences of digits conventionally displayed and manipulated as unsigned integers.

Types of memory addresses

- Physical addresses
- Logical addresses

all declared variables are stored in a memory location and this location has an address memory as indetificator, in c you can access to memory location with & operator 

Example

``` c
int a;
a = 3;
printf("value: %d Dir: %d", a, &a);

```
##  pointers
the pointer is a variable that can stored the address memory of others variable

-  The pointer can only have addresses of variable memory of the specified type
-  You can define pointers of any type

pointers declaration & assignment

  ```c
  // declaration
  int *a;
	float *pf; 
	char *pc;

	// declaration and assigment example
	int q = 3;
	a = &q; // with & operator I can get the memory address of that variable
  ```

A pointer has its own memory address

``` c
  int a = 1;
  int *pa = &a;

  *pa //content value in a
  pa // memory address of a
  &pa // memory address of pa

```
## moving through the memory address

to move to the next memory address position and get its value

``` c
// see full example in poitiners.c line 21 - 23
 printf(“%d”, *(punt+1));
```

``` c
// memory address in then next slot
 printf(“%d”, punt+1);
```


## pointer to pointer

[![Pointer to pointer schema](https://www.geeksforgeeks.org/wp-content/uploads/Double-Pointer-in-C.png "Pointer to pointer schema")](https://www.geeksforgeeks.org/wp-content/uploads/Double-Pointer-in-C.png "Pointer to pointer schema")

![how work](https://www.geeksforgeeks.org/wp-content/uploads/How-Pointer-Works-In-C.png "how work")


