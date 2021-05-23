//This program is a C program to Error Detection using Cyclic Redundancy Check Algorithms.
#include <stdio.h>
#include<conio.h>
int main(){
    printf("Error Detection Program \n");

    int dsize, gsize,i,j,k,len;

    char dataword[100],generator[50],crc[50];

    //Copy dataword in crc

    //dataword and generator is stored in character array
    //i,j and k are int variables
    //dsize = dataword size
    //gsize = generator size

    //Scanning size of dataword and generator
    printf("Enter generator size\n");
    scanf("%d",&gsize);
start:     //jump location
     printf("Enter dataword size\n");
     scanf("%d",&dsize);

     if(dsize<gsize){
        printf("Dataword size is less than generator size \n. Enter correct size of dataword\n");
        goto start;  //if this condition satisfies then jump to the start
     }

     //Scanning dataword and generator
     printf("Enter dataword");
     scanf("%s",  dataword);
     printf("Enter generator");
     scanf("%s",  generator);
    
   /*So now we have to add additional zeros to the dataword the no of 
     zeros 
     we have to add are(dsize-1)*/
   //k=0;
   for(i=0;i<gsize-1;i++)  
    {/*loop executes from 0 to gsize-2 and we have to add these
       number of 0's at the end of dataword
       */
      /*if(dataword[i]=='0'){
        k++;
      }*/
      dataword[dsize+i]='0';      
    }
    
    dataword[dsize+gsize-1]='\0';

    //Now we have to do operation to find remainder when we divide
    //dataword by generator

    //So we take while loop
    do
    {
      //loop to divide
      for(i=0;i<gsize;i++){
        //Here the operation is such that 0+0=0, 1+1=0, 0+1=1, 1+0=1
        //Here we are updating immediately at dataword array
        if(dataword[i]==generator[i]){
          dataword[i]='0'; //same
        }
        else{
            dataword[i]='1';//not same
        }
      }
     //There may be a possibility of all the values in dataword are
     //zero then this do while loop be in infinite loop
     //for this we are checking one condition
     
     //if all elements are zero then we are breaking this loop
      k=0; // k is counter of 0's
      for(i=0;i<gsize+dsize-1;i++)
      {
        if(dataword[i] == '0')
        {
          k++;
        }
      }
      if(k==(dsize+gsize-1)) //i.e all values are 0
      break;                       // then break do while loop


      //So now we have to remove the first 0's produced
      //in dataword char array after divide operation
      //So we will left swap the all elements till dataword[0]='1'
       
       while(dataword[0]!='1'){
         for(i=0;i<dsize+gsize-1;i++){
           //dsize is dataword size and we have added gsize-1 0's to dataword 
           //so now dataword dsize=dsize+gsize-1
           dataword[i] = dataword[i+1];//left swap
         }
         //Here as we are left shifting the dataword, size will going to decrease
         dsize--;
       }

       //We have to iterate through this loop till len>gsize
       //because we can do operation till
       //len=gsize i.e 1011 and 1001(if dataword size less than)
      
      len = dsize+gsize-1;//length of dataword
      //we have to iterate through this loop till len>gsize-1
        //because we can do operation till len=gsize i.e 1011 and 1001(if dataword size less than)
    } while(len>gsize-1);

    dataword[len]='\0';   //marking end of char array
    
    //The output (remaining dataword) will be the remainder of crc code

    printf(" *** remainder is : %s  *** ", dataword);  

   //here user can change the dataword
  
    printf("Do you want to change remainder enter 0 else 1\n?");
    scanf("%d",&j);
    if(j==0)
    {
      crc[0]='\0'; //Set dataword to null
      printf("Enter new Dataword\n");
      scanf("%s",crc);
    }

    //Set length
    len = strlen(dataword);
    dsize=strlen(crc);
    //new addition 0's if remainder size is not equal to gsize to the of crc
    if(len != gsize-1)
    {
      for(i=0;i<gsize-1-len;i++) //iteration adds 0's to the crc
      {
        crc[dsize+i] = '0';  //additing after crc(dsize+i)
      }
    }
    crc[dsize+i]='\0'; //end of crc

    //Adding remainder to the end of CRC to calculate syndrome
    len = strlen(dataword);
    dsize = strlen(crc);

    for(i=0;i<len;i++) //adding
    {
       crc[dsize+i] = dataword[i];
    }
    crc[dsize+i] = '\0';
    
    //Now we have to calculate syndrome so the code for
    //generating syndrome is same as remainder(do while loop)
  //So we take while loop
    
    //We just have to copy crc in dataword
    
    dataword[0] = '\0';  //dataword as null
    strcpy(dataword,crc);

    do
    {
      //loop to divide
      for(i=0;i<gsize;i++){
        //Here the operation is such that 0+0=0, 1+1=0, 0+1=1, 1+0=1
        //Here we are updating immediately at dataword array
        if(dataword[i]==generator[i]){
          dataword[i]='0'; //same
        }
        else{
            dataword[i]='1';//not same
        }
      }
     //There may be a possibility of all the values in dataword are
     //zero then this do while loop be in infinite loop
     //for this we are checking one condition
     
     //if all elements are zero then we are breaking this loop
      k=0; // k is counter of 0's
      for(i=0;i<gsize+dsize-1;i++)
      {
        if(dataword[i] == '0')
        {
          k++;
        }
      }
      if(k==(dsize+gsize-1)) //i.e all values are 0
      break;                       // then break do while loop


      //So now we have to remove the first 0's produced
      //in dataword char array after divide operation
      //So we will left swap the all elements till dataword[0]='1'
       
       while(dataword[0]!='1'){
         for(i=0;i<dsize+gsize-1;i++){
           //dsize is dataword size and we have added gsize-1 0's to dataword 
           //so now dataword dsize=dsize+gsize-1
           dataword[i] = dataword[i+1];//left swap
         }
         //Here as we are left shifting the dataword, size will going to decrease
         dsize--;
       }

       //We have to iterate through this loop till len>gsize
       //because we can do operation till
       //len=gsize i.e 1011 and 1001(if dataword size less than)
      
      len = dsize+gsize-1;//length of dataword
      //we have to iterate through this loop till len>gsize-1
        //because we can do operation till len=gsize i.e 1011 and 1001(if dataword size less than)
    } while(len>gsize-1);
      dataword[len]='\0'; //working end of char array

    //The output (remaining dataword) will be the remainder of crc code
    printf(" *** Syndrome is: %s ****", dataword);

    //if syndrome is zero then no error else error

    /*now we print generator and dataword to check till now
     code is correct or not
    */
    /*printf("%s\n", dataword);
    printf("%s\n", generator);*/

     
     //do while loop explanation with example

     /*dataword  101111    101111  first add 3 (0's')  then 101111000                        new dataword 11000    1110
                                                          1011                                          1011     1011           
                                                          000011000  ans  after 1st loop     */            
    return 0;
    _getch();
}