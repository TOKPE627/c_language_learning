//This program is a c program to implement linear search
#include<stdio.h>
int main()
{
    int sizeArr=25;
    int arr[sizeArr],i,nElements,elementToSearch;
    printf("Please enter the number of elements: ");
    scanf("%d", &nElements);

    if(nElements > sizeArr)
    {
        printf("The size of the array must be less or equal to %d",sizeArr);
    }
    else
    {
        printf("Please enter the array elements:\n");

        //Loop of elements entered in the array
        for(i=0;i<nElements;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("Enter element you want to search:");
        scanf("%d",&elementToSearch);

        for(i=0;i<nElements;++i)
        {
            if(arr[i]==elementToSearch)
            break;
        }

        if(i<nElements)
        {
            printf("Element %d found at position %d", elementToSearch ,i);
        }
        else
        {
            printf("OOPS! Element %d not found at this position %d ", elementToSearch, i);       
        }
    } 
}