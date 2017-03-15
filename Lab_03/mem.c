#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *)malloc(2 * sizeof(int));
	handle = &ptr;
	*ptr = num;
	ptr = &num;// memory leak happens here because the line before does the same thing 
	handle = (int **)malloc(1 * sizeof(int **));
}
