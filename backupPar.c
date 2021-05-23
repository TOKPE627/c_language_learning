#include<stdio.h>
#include<conio.h>

int main(){
   /* 2D array declaration*/

  
   int arr[4][7], i,j;
   int sum = 0;
   int sumLast=0;
   int sumOneError=0;
	int arrparity;//array pointer
   int posDamaged;
   int parityBit;
   int k,choice;
   int firstrow[8];
   int secondrow[8];
   int thirdrow[8];
   int fourthrow[8];
   int fifthrow[8];
   //int firstcol[8],secondcol[8], thirdcol[8],fourthcol[8];

   int datatransmitted[44],dataoneerror[44], matrixOneError[4][7],index;
   	
   //32 bits
   printf("Enter the elements of the matrix: ");

   /*Counter variables for the loop*/
   //scanf("input %d ", &input);


   for(i=0; i<4; i++) {
      for(j=0;j<7;j++) {
         scanf("%d ", &arr[i][j]);
      }
   }

   for(i=0; i<4; i++) {
      for(j=0;j<7;j++) {
         printf("%d ", arr[i][j]);
      }
      printf("\n");

   }

   //Calculation of parity
    for (i = 0; i < 4; ++i) 
    {
        for (j = 0; j < 7; ++j) 
        {
            sum = sum + arr[i][j] ;    
        }
          
  //   printf("Sum of the %d row is = %d\n", j, sum);
        if(i==0){
           printf("Sum of the %d row is = %d\n", i, sum);
            if(sum % 2 == 1){
               firstrow[7]  = 1;
            }
            if(sum % 2 == 0){
               firstrow[7]  = 0;
            }
         }

        if(i==1){
                   printf("Sum of the %d row is = %d\n", i, sum);
            if(sum % 2 == 1){
               secondrow[7] = 1;         
            }
            if(sum % 2 == 0){
            
               secondrow[7] = 0;
      
            }
        }
       if(i==2){
            printf("Sum of the %d row is = %d\n", i, sum);
           if(sum % 2 == 1){
               thirdrow[7] = 1;         
            }
            if(sum % 2 == 0){
               thirdrow[7] = 0;
            }
        }
      
       if(i==3){
            printf("Sum of the %d row is = %d\n", i, sum);
            if(sum % 2 == 1){
               fourthrow[7] = 1;         
            }
            if(sum % 2 == 0){
               fourthrow[7] = 0;
            }
        }
   
        sum = 0;
    }

   for (j = 0; j < 7; ++j) 
   {
      for (i = 0; i < 4; ++i)
      {
         sum = sum + arr[i][j];
      }
         
      printf("Sum of the %d column is = %d\n", j, sum);
      if(sum % 2 == 1){
         fifthrow[j] = 1;    
      }
      if(sum % 2 == 0){
         fifthrow[j] = 0;
      }  
      sum = 0;
    }
        sum = 0;

    for(i=0; i<4; i++) {
      for(j=0;j<7;j++) {
         printf("%d ", arr[i][j]);
      }
      printf("\n");
    }

   // printf(" pb pb %d ", &pB);
   printf(" \n");

   for(k=0; k<7; k++)
   {
       firstrow[k]   = arr[0][k];
       secondrow[k]  = arr[1][k];
       thirdrow[k]   = arr[2][k];
       fourthrow[k]  = arr[3][k];
       
   }


    /*printf("\n.Elements of dest array are : ");
       
    for(k=0; k<8; k++)
    {
        printf("%d\t", firstrow[k]);
    }*/

   printf("\n");
   
    printf("\nFirst row with parity bit is: \n ");
   index = 0;
   for(k=0; k<8; k++)
   {
      datatransmitted[index] = firstrow[k];
      printf(" %d\t", firstrow[k]);
      index++;
   }
   
   printf("\n");
   
   printf("\nSecond row with parity bit is: \n ");

   for(k=0; k<8; k++)
   {
      datatransmitted[index] = secondrow[k];
      printf(" %d\t", secondrow[k]);
      index++;
   }

   printf("\nThird row with parity bit is: \n ");

   for(k=0; k<8; k++)
   {
      datatransmitted[index] = thirdrow[k];
      printf(" %d\t", thirdrow[k]);
      index++;
   }

      printf("\nFourth row with parity bit is: \n ");

   for(k=0; k<8; k++)
   {
      datatransmitted[index] = fourthrow[k];
      printf(" %d\t", fourthrow[k]);
      index++;
   }

   printf("\n");
    //printf(" Last row : \n");
   for(k=0; k<7; k++) {
     sumLast = sumLast + fifthrow[k];
   }
   printf("Sum of the column  8 is = %d\n", sumLast);
   if(sumLast % 2 == 1){
     fifthrow[7]=1;
   }else{
     fifthrow[7]=0;
   }

   printf("\nFifth row with parity bit is: \n ");

   for(k=0; k<8; k++)
   {
      datatransmitted[index] = fifthrow[k];
      printf(" %d\t", fifthrow[k]);
      index++;
   }

   printf("\n");
   
   printf(" Data transmitted to the receiver: \n");
   
   for(k=0; k<40; k++) {
      printf(" %d ", datatransmitted[k]);
   }
 
 //Error Detection
   printf(" Error Detection: \n");
 
   /*printf("Press 1 to choose One Error Detection Program\n");  
   printf("Press 2 to choose Two Errors Detection Program \n"); 
   printf("Press 3 to choose Three Errors Detection Program \n"); 
   printf("Press 4 to choose Four Errors Detection Program \n"); 

 
    printf("Enter your choice:\n"); 
    scanf("%d",&choice);*/

   
          printf(" Bit at position row 2-column 3 is damaged \n");
   
         printf("Matrix 1: New matrix of  1 bit Error Detection: \n");

         for(k=0; k<7; k++)
         {
            dataoneerror[index] = firstrow[k];
            printf(" %d\t", firstrow[k]);
            index++;
         }

         printf("\n");

         secondrow[posDamaged]=0;//Bit damaged

         for(k=0; k<7; k++)
         {
            dataoneerror[index] = secondrow[k];
            printf(" %d\t", secondrow[k]);
            index++;
         }

         printf("\n");

         for(k=0; k<7; k++)
         {
            dataoneerror[index] = thirdrow[k];
            printf(" %d\t", thirdrow[k]);
            index++;
         }
         
         printf("\n");

         for(k=0; k<7; k++)
         {
            dataoneerror[index] = fourthrow[k];
            printf(" %d\t", fourthrow[k]);
            index++;
         }
         
         printf("\n");

         for(k=0; k<7; k++)
         {
            dataoneerror[index] = fifthrow[k];
            printf(" %d\t", fifthrow[k]);
            index++;
         }

         printf("\n");
            printf("\nMatrix 1:with Parity bits: \n ");

         index = 0;

         for(k=0; k<8; k++)
         {
            dataoneerror[index] = firstrow[k];
            printf(" %d\t", firstrow[k]);
            index++;
         }
         
         printf("\n");
      

         for(k=0; k<7; k++) {
         sumOneError = sumOneError + secondrow[k];
         }
         //printf("Sum of the column  8 is = %d\n", sumLast);
         if(sumOneError % 2 == 1){
         secondrow[7]=1;
         }else{
         secondrow[7]=0;
         }

         if(sumLast % 2 == 1){
         fifthrow[posDamaged]=1;
         }else{
         fifthrow[posDamaged]=0;
         }
         for(k=0; k<8; k++)
         {
            dataoneerror[index] = secondrow[k];
            printf(" %d\t", secondrow[k]);
            index++;
         }

         printf("\n");
         
         for(k=0; k<8; k++)
         {
            dataoneerror[index] = thirdrow[k];
            printf(" %d\t", thirdrow[k]);
            index++;
         }

         printf("\n");
         
         for(k=0; k<8; k++)
         {
            dataoneerror[index] = fourthrow[k];
            printf(" %d\t", fourthrow[k]);
            index++;
         }

         printf("\n");
         //printf(" Last row : \n");
         for(k=0; k<7; k++) {
         sumOneError = sumOneError + fifthrow[k];
         }
         //printf("Sum of the column  8 is = %d\n", sumLast);
         if(sumOneError % 2 == 1){
         fifthrow[7]=1;
         }else{
         fifthrow[7]=0;
         }

         for(k=0; k<8; k++)
         {
            dataoneerror[index] = fifthrow[k];
            printf(" %d\t", fifthrow[k]);
            index++;
         }

          printf("\n");
         printf("Conclusion: One error has effected two parities \n");

       //    break;
     // case 2: 
            printf("Case 2: Bits at position row 2-column 3-column 5 are damaged \n");
            printf("\n");
            printf("Conclusion: Two errors has effected two parities \n");    
         //  break;
      //case 3: 
            printf("Case 3: Bits at position row 1-column 2, row 2-column 4 and row 3-column 4 are damaged \n");
             printf("\n");
            printf("Conclusion: Three errors has effected four parities \n"); 
        //   break;
      //case 4: 
            printf("Case 4: Bits at position row 1-column 4 -column 5, row 3-column 4 -column 5 are damaged \n");
             printf("\n");
            printf("Conclusion: Four errors can not be detected \n"); 
        //   break;
   

   
   /////
   /* printf(" First row of the matrix: ");
   for(k=0; k<8; k++) {
   
      printf(" %d ", arr[0][k]);
   }

    printf("\n: ");*/

 
    /*
     * Print all elements of dest array
     */

    


/*
   printf(" Second row of the matrix: ");
   for(k=0; k<8; k++) {
      printf(" %d ", arr[1][k]);
   }

   printf(" %d \n");  
   
   printf(" Third row of the matrix: ");
   for(k=0; k<8; k++) {
      printf(" %d ", arr[2][k]);
   }

   printf(" %d \n");   
   printf(" Fourth row of the matrix: ");
   for(k=0; k<8; k++) {
      printf(" %d ", arr[3][k]);
   }*/

   getch();
}