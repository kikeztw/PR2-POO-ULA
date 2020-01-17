//Clase de introduccion a C++ 			28/11/19
#include <iostream>
#include <ctime>
#include <cstdlib>

void printArray(int *array, size_t size){
	for (int i = 0; i < size; i++)
		std::cout<< array[i] << ' ';
	std::cout<<std::endl;
}

void fillArray(int *array,size_t size){
	srand(time(NULL));

	for (int i = 0; i < size; i++)
		array[i] = rand()%99;

}

bool smaller(int a, int b){
	return((a<b)? true : false);
}

bool greater(int a, int b){
	return((a>b)? true : false);
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int *array, size_t size, bool(*foo)(int,int))
{
	for (int i = 0; i < size-1; i++)
		for (int j = i+1; j < size; j++)
			if (foo(array[i],array[j]))
				swap(array[i],array[j]);

}

int main()
{
	int array1[15],array2[12]; //Se crean dos vectores para ejemplificar

	fillArray(array1,15);	//Se llena el vector
	std::cout<< "Arreglo 1" << std::endl;
	printArray(array1,15);	//Se muestra el orden original del vector

	fillArray(array2,12);
	std::cout<< "Arreglo 2" << std::endl;
	printArray(array2,12);

	bool (*increasingOrder)(int,int) = greater; 	//Se crea un apuntador a la función que me implica el orden a utilizar
	bool (*decreasingOrder)(int,int) = smaller;

	selectionSort(array1,15,increasingOrder);	//Llamo al procedimiento especificando en cual orden deseo el vector
	std::cout<< "Arreglo 1 ordenado" << std::endl;
	printArray(array1,15);	//Muestro el vector ordenado

	selectionSort(array2,12,decreasingOrder);
	std::cout<< "Arreglo 2 ordenado" << std::endl;
	printArray(array2,12);


	return 0;
}