#include<stdio.h>
#include<conio.h>

int main(){  
   int arr[4][7], i,j;
   int sum = 0;
   int sumLast=0;
   int sumOneError=0;
   int sumThreeError=0;
	int arrparity;//array pointer
   int posDamaged;
   int parityBit;
   int k;
   int firstrow[8];
   int secondrow[8];
   int thirdrow[8];
   int fourthrow[8];
   int fifthrow[8];
   int datatransmitted[44],dataoneerror[44], datatwoerror[44],datathreeerror[44],datafourerror[44],index;
   
   printf("\n");

   printf("Enter the message bits: \n");
   for(i=0; i<4; i++) {
      for(j=0;j<7;j++) {
         scanf("%d ", &arr[i][j]);
      }
   }
   printf("\n The matrix[4][7] of the message is :\n\n");
   for(i=0; i<4; i++) {
      for(j=0;j<7;j++) {
         printf("%d ", arr[i][j]);
      }
      printf("\n\n");
   }
   //Calculation of parity
    for (i = 0; i < 4; ++i) 
    {
        for (j = 0; j < 7; ++j) 
        {
            sum = sum + arr[i][j] ;    
        }
        if(i==0){
           printf("Sum of the %d row is = %d\n\n", i, sum);
            if(sum % 2 == 1){
               firstrow[7]  = 1;
            }
            if(sum % 2 == 0){
               firstrow[7]  = 0;
            }
         }
        if(i==1){
                   printf("Sum of the %d row is = %d\n\n", i, sum);
            if(sum % 2 == 1){
               secondrow[7] = 1;         
            }
            if(sum % 2 == 0){
            
               secondrow[7] = 0;
            }
        }
       if(i==2){
            printf("Sum of the %d row is = %d\n\n", i, sum);
           if(sum % 2 == 1){
               thirdrow[7] = 1;         
            }
            if(sum % 2 == 0){
               thirdrow[7] = 0;
            }
        }
      
       if(i==3){
            printf("Sum of the %d row is = %d\n\n", i, sum);
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
      printf("Sum of the %d column is = %d\n\n", j, sum);
      if(sum % 2 == 1){
         fifthrow[j] = 1;    
      }
      if(sum % 2 == 0){
         fifthrow[j] = 0;
      }  
      sum = 0;
    }
    sum = 0;
   printf(" \n");

   for(k=0; k<7; k++)
   {
       firstrow[k]   = arr[0][k];
       secondrow[k]  = arr[1][k];
       thirdrow[k]   = arr[2][k];
       fourthrow[k]  = arr[3][k];   
   }
    printf("\n\n");
    printf("\nFirst row with parity bit is: \n\n ");
   index = 0;
   for(k=0; k<8; k++)
   {
      datatransmitted[index] = firstrow[k];
      printf(" %d\t", firstrow[k]);
      index++;
   }
   printf("\n");
   printf("\nSecond row with parity bit is: \n\n ");
   for(k=0; k<8; k++)
   {
      datatransmitted[index] = secondrow[k];
      printf(" %d\t", secondrow[k]);
      index++;
   }
   printf("\nThird row with parity bit is: \n\n ");
   for(k=0; k<8; k++)
   {
      datatransmitted[index] = thirdrow[k];
      printf(" %d\t", thirdrow[k]);
      index++;
   }
   printf("\nFourth row with parity bit is: \n\n ");
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
   printf("Sum of the column  8 is = %d\n\n", sumLast);
   if(sumLast % 2 == 1){
     fifthrow[7]=1;
   }else{
     fifthrow[7]=0;
   }
   printf("\nFifth row with parity bit is: \n\n ");
   for(k=0; k<8; k++)
   {
      datatransmitted[index] = fifthrow[k];
      printf(" %d\t", fifthrow[k]);
      index++;
   }
   printf("\n\n");
   printf(" Data transmitted to the receiver: \n\n");
   for(k=0; k<40; k++) {
      printf(" %d ", datatransmitted[k]);
   }
   printf("\n\n");
   printf(" Error Detection: \n\n");
   printf("Case 1 Bit at position row 2-column 3 is damaged \n\n");
   printf("Matrix 1: New matrix of  1 bit Error Detection: \n\n");
   for(k=0; k<7; k++)
   {
      dataoneerror[index] = firstrow[k];
      printf(" %d\t", firstrow[k]);
      index++;
   }
   printf("\n");
   secondrow[2]=0;//Bit damaged
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
      printf("\nMatrix 1:with Parity bits: \n\n ");
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
   if(sumOneError % 2 == 1){
     secondrow[7]=1;
   }else{
     secondrow[7]=0;
   }
   if(sumLast % 2 == 1){
     fifthrow[2]=1;
   }else{
     fifthrow[2]=0;
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
   for(k=0; k<7; k++) {
      sumOneError = sumOneError + fifthrow[k];
   }
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
   printf("\n\n");
   printf("Conclusion: One error has effected two parities \n");
   printf("\n");
   printf("Case 2: Bits at position row 2-column 3-column 5 are damaged \n\n");
   printf("Matrix 2: New matrix of  2 bits Errors Detection: \n\n");
   for(k=0; k<7; k++)
   {
      datatwoerror[index] = firstrow[k];
      printf(" %d\t", firstrow[k]);
      index++;
   }
   printf("\n");
   //Bits damaged
   secondrow[2]=0; 
   secondrow[4]=0;
   for(k=0; k<7; k++)
   {
      datatwoerror[index] = secondrow[k];
      printf(" %d\t", secondrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datatwoerror[index] = thirdrow[k];
      printf(" %d\t", thirdrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datatwoerror[index] = fourthrow[k];
      printf(" %d\t", fourthrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datatwoerror[index] = fifthrow[k];
      printf(" %d\t", fifthrow[k]);
      index++;
   }
   printf("\n");
   printf("\nMatrix 2:with Parity bits: \n\n ");
   index = 0;
   for(k=0; k<8; k++)
   {
      datatwoerror[index] = firstrow[k];
      printf(" %d\t", firstrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++) {
   sumOneError = sumOneError + secondrow[k];
   }
   if(sumOneError % 2 == 1){
      secondrow[7]=1;
   }else{
      secondrow[7]=0;
   }
   if(sumLast % 2 == 1){
      fifthrow[2]=1;
      fifthrow[4]=1;
   }else{
     fifthrow[2]=0;
     fifthrow[4]=0;
   }
   for(k=0; k<8; k++)
   {
      datatwoerror[index] = secondrow[k];
      printf(" %d\t", secondrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<8; k++)
   {
      datatwoerror[index] = thirdrow[k];
      printf(" %d\t", thirdrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<8; k++)
   {
      datatwoerror[index] = fourthrow[k];
      printf(" %d\t", fourthrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++) {
     sumOneError = sumOneError + fifthrow[k];
   }
   if(sumOneError % 2 == 1){
     fifthrow[7]=0;
   }else{
     fifthrow[7]=1;
   }
   for(k=0; k<8; k++)
   {
      datatwoerror[index] = fifthrow[k];
      printf(" %d\t", fifthrow[k]);
      index++;
   }
   printf("\n");
   printf("Conclusion: Two errors has effected two parities \n\n");   
   printf("Case 3: Bits at position row 1-column 2, row 2-column 4 and row 3-column 4 are damaged \n\n");
   printf("Matrix 3: New matrix of  3 bits Error Detection: \n\n");
   //Bits damaged
   firstrow[1]=0; 
   secondrow[3]=0; 
   thirdrow[3]=0;
   for(k=0; k<7; k++)
   {
      datathreeerror[index] = firstrow[k];
      printf(" %d\t", firstrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datathreeerror[index] = secondrow[k];
      printf(" %d\t", secondrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datathreeerror[index] = thirdrow[k];
      printf(" %d\t", thirdrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datathreeerror[index] = fourthrow[k];
      printf(" %d\t", fourthrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datathreeerror[index] = fifthrow[k];
      printf(" %d\t", fifthrow[k]);
      index++;
   }
   printf("\n");
   printf("\nMatrix 3:with Parity bits: \n\n ");
   index = 0;
   for (i = 0; i < 4; ++i) 
    {
        for (j = 0; j < 7; ++j) 
        {
            sumThreeError = sumThreeError + arr[i][j] ;    
        }
        if(i==0){
            firstrow[7]  = 0;
         }
        if(i==1){
            fifthrow[1] = 0;
            if(sumThreeError % 2 == 1){
               secondrow[7] = 0;         
            }
            if(sumThreeError % 2 == 0){
               secondrow[7] = 1;
            }
        }
       if(i==2){
           if(sumThreeError % 2 == 1){
               thirdrow[7] = 0;         
            }
            if(sumThreeError % 2 == 0){
               thirdrow[7] = 1;
            }
        }
       if(i==3){
            if(sumThreeError % 2 == 1){
               fourthrow[7] = 1;         
            }
            if(sumThreeError % 2 == 0){
               fourthrow[7] = 0;
            }
        }
        sumThreeError = 0;
    }
   for(k=0; k<8; k++)
   {
      datathreeerror[index] = firstrow[k];
      printf(" %d\t", firstrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<8; k++)
   {
      datathreeerror[index] = secondrow[k];
      printf(" %d\t", secondrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<8; k++)
   {
      datathreeerror[index] = thirdrow[k];
      printf(" %d\t", thirdrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<8; k++)
   {
      datathreeerror[index] = fourthrow[k];
      printf(" %d\t", fourthrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<8; k++)
   {
      datathreeerror[index] = fifthrow[k];
      printf(" %d\t", fifthrow[k]);
      index++;
   }
   printf("\n\n");
   printf("Conclusion: Three errors has effected four parities \n"); 
   printf("\n\n");
   printf("Case 4: Bits at position row 1-column 1, row 2-column 4,row 3-column 1-column 4 are damaged \n\n");
   printf("Matrix 4: New matrix of  4 bits Error Detection: \n\n");
   printf("\n\n");
     //Bits damaged
   secondrow[1]=0; 
   secondrow[4]=0;
   fourthrow[1]=1; 
   fourthrow[4]=1;
   for(k=0; k<7; k++)
   {
      datafourerror[index] = firstrow[k];
      printf(" %d\t", firstrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datafourerror[index] = secondrow[k];
      printf(" %d\t", secondrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datafourerror[index] = thirdrow[k];
      printf(" %d\t", thirdrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datafourerror[index] = fourthrow[k];
      printf(" %d\t", fourthrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<7; k++)
   {
      datafourerror[index] = fifthrow[k];
      printf(" %d\t", fifthrow[k]);
      index++;
   }
   printf("\n");
   printf("\nMatrix 4:with Parity bits: \n\n ");
   index = 0;
   for (i = 0; i < 4; ++i) 
    {
        for (j = 0; j < 7; ++j) 
        {
            sumThreeError = sumThreeError + arr[i][j] ;    
        }
        if(i==0){
            firstrow[7]  = 0;
         }
        if(i==1){
           
            if(sumThreeError % 2 == 1){
                fifthrow[1] = 1;
               secondrow[7] = 0;         
            }
            if(sumThreeError % 2 == 0){
                fifthrow[1] = 0;
               secondrow[7] = 1;
            }
        }
       if(i==2){
           if(sumThreeError % 2 == 1){
               thirdrow[7] = 1;         
            }
            if(sumThreeError % 2 == 0){
               thirdrow[7] = 0;
            }
        }
       if(i==3){
            if(sumThreeError % 2 == 1){
               fourthrow[7] = 1;         
            }
            if(sumThreeError % 2 == 0){
               fourthrow[7] = 0;
            }
        }
        sumThreeError = 0;
    }
   for(k=0; k<8; k++)
   {
      datafourerror[index] = firstrow[k];
      printf(" %d\t", firstrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<8; k++)
   {
      datafourerror[index] = secondrow[k];
      printf(" %d\t", secondrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<8; k++)
   {
      datafourerror[index] = thirdrow[k];
      printf(" %d\t", thirdrow[k]);
      index++;
   }
   printf("\n");
   for(k=0; k<8; k++)
   {
      datafourerror[index] = fourthrow[k];
      printf(" %d\t", fourthrow[k]);
      index++;
   }
   printf("\n");
   fifthrow[7] = 1;         
   for(k=0; k<8; k++)
   {
      datafourerror[index] = fifthrow[k];
      printf(" %d\t", fifthrow[k]);
      index++;
   }
   printf("\n\n");
   printf("Conclusion: Four errors can not be detected \n");
   printf("\n");
   getch();
}