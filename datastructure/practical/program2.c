//This program is a c program to implement binary search
#include <stdio.h>

int main()
{
    int sizeArr=100;
    int arr[sizeArr], nElements, i, elementSearch;
    int first,last,middle;

    printf("Please enter number of elements: ");
    scanf("%d", &nElements);

    if(nElements > sizeArr) 
    {
        printf("Please the size of the array must not be greater than %d", sizeArr);
    }
    else
    {
        //Loop on entered elements
        printf("Please enter the array elements\n");
        for(i=0;i<nElements;i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("Enter the element you want to search: ");
        scanf("%d", &elementSearch);
        //Binary Research
        
        first=0;
        last=nElements-1;
        middle=(first+last)/2;
        while (first<=last)
        {
            if(arr[middle] < elementSearch)
            {
                first = middle+1;
            }
            else if(arr[middle] == elementSearch)
            {
                printf("%d found at location %d.\n", elementSearch, middle+1);
                break;
            }
            else 
            {
                last=middle-1;
            }
            
            middle=(first + last)/2;
        }

        if(first > last)
        {
            printf("Element %d is not present in the list", elementSearch);
        }        

        return 0;

    }
}

