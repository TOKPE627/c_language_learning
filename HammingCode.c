#include<stdio.h> 
void main() {
    int data[10],dataatrec[10],c1,c2,c3,i,p,c;
    int choice;
    
    printf("Press 1 to make Hamming Program for Odd Parity\n");  
    printf("Press 2 to make Hamming Program for Even Parity\n"); 

    printf("Enter your choice:\n"); 
    scanf("%d",&choice);

    switch(choice){
        case 1:
                printf(" Welcome in Hamming Program for Odd parity\n");
                printf(" Enter 4 bits of data one by one\n");
                scanf(" %d",&data[3]);
                scanf(" %d",&data[5]);
                scanf(" %d",&data[6]);
                scanf(" %d",&data[7]);

                //Calculation of Odd Parity

                data[1]=data[3]^data[5]^data[7];
                data[2]=data[3]^data[6]^data[7];
                data[4]=data[5]^data[6]^data[7];

                printf("\nEncoded data is\n");

                for(i=1;i<8;i++)
                    printf(" %d \t",data[i]);
                
                printf("\n\nEnter 7 bits of received data one by one\n");

                for(i=1;i<8;i++)
                    scanf("%d",&dataatrec[i]);

                c1=dataatrec[1]^dataatrec[3]^dataatrec[5]^dataatrec[7];
                c2=dataatrec[2]^dataatrec[3]^dataatrec[6]^dataatrec[7];
                c3=dataatrec[4]^dataatrec[5]^dataatrec[6]^dataatrec[7];
                
                p=c1*1+c2*2+c3*4;//conversion in decimal

            if(p==0) {
                    printf("\nNo error while transmission of data\n");
                }
                else {
                    printf("\nThere is Error on position %d",p);
                    
                    printf("\nData sent : ");
                    for(i=1;i<8;i++)
                        printf(" %d \t",data[i]);
                    
                    printf("\nData received : ");
                    for(i=1;i<8;i++)
                        printf("%d \t",dataatrec[i]);
                    
                    printf("\nCorrect message is\n");
            
                    //if errorneous bit is 0 we complement it else vice versa
                    if(dataatrec[p]==0)
                        dataatrec[p]=1;
                    else
                        dataatrec[p]=0;
                    
                    for (i=1;i<8;i++) {
                        printf("%d \t",dataatrec[i]);
                    }
                } 

              break;
        case 2:
                printf(" Welcome in Hamming Program for Even parity\n");
                printf("Enter 4 bits of data one by one\n");
                scanf("%d",&data[0]);
                scanf("%d",&data[1]);
                scanf("%d",&data[2]);
                scanf("%d",&data[4]);
            
                //Calculation of Even Parity
                data[6]=data[0]^data[2]^data[4];
                data[5]=data[0]^data[1]^data[4];
                data[3]=data[0]^data[1]^data[2];
            
                printf("\n\nEncoded data is\n");
                for(i=0;i<7;i++)
                    printf(" %d \t",data[i]);
                    
                    printf("\n\nEnter 7 bits of received data one by one\n");

                for(i=0;i<7;i++)
                    scanf("%d",&dataatrec[i]);
            
                c1=dataatrec[6]^dataatrec[4]^dataatrec[2]^dataatrec[0];
                c2=dataatrec[5]^dataatrec[4]^dataatrec[1]^dataatrec[0];
                c3=dataatrec[3]^dataatrec[2]^dataatrec[1]^dataatrec[0];
                c=c3*4+c2*2+c1 ;//Conversion of number to decimal
            
                if(c==0) {
                    printf("\nNo error while transmission of data\n");
                }
                else {
                    printf("\nError on position %d",c);
                    
                    printf("\nData sent : ");
                    for(i=0;i<7;i++)
                        printf(" %d \t",data[i]);
                    
                    printf("\nData received : ");
                    for(i=0;i<7;i++)
                        printf(" %d \t",dataatrec[i]);
                    
                    printf("\nCorrect message is\n");
            
                    //if errorneous bit is 0 we complement it else vice versa
                    if(dataatrec[7-c]==0)
                        dataatrec[7-c]=1;
                    else
                        dataatrec[7-c]=0;
                    
                    for (i=0;i<7;i++) {
                        printf(" %d \t",dataatrec[i]);
                    }
                } 
              break;
    }  
}