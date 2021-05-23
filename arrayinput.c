/*--------------------------------------------------------
* Program for how to create an array from user input in c
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,NoOfElements;
	int *arr;//array pointer

	//How many elements you want to store in array?
	printf("How many elements? Enter the size: ");
	//Store size into variable n
	scanf("%d",&NoOfElements);

	//allocate memory dynamically with of 
	//total size = NoOfElements* size of 1 integer i.e. sizeof(int)

	//malloc returns void pointer,means points to nothing
	//typecast it to int* as we want to store int values
	arr=(int*)malloc(NoOfElements*sizeof(int));


	//Check memory is allocated successfully
	//if fails return from the program.
	if(arr==NULL){
		printf("ERROR: MEMORY ALLOCATION FAIL\n");
		return 1;//memory allocation fails - return from here
	}

	//
	printf("Enter %d elements",NoOfElements);

	//fill the array with elements by
	//reading from console screen
	for (i=0; i<NoOfElements; ++i){
		scanf("%d",&arr[i]);
	}



	//display the array	
	printf("Array elements are:\n");
	for(i=0;i < NoOfElements;i++){
		printf("%d\n",arr[i]);

	}
	//free the memory
	free(arr);
	return 0;
}
