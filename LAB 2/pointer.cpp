/*pointers*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
int palindrom(int*arr , int *siz);
int pow(int * a , int*n);


int no_digits(int* a)
{
    int*c;
    *c=0;
    while (*a!=0)
    {
        *c=(*c)+1;
        *a = (*a)/10;
    }
    return *c;


}




int main()
{
    int *dataptr=(int *)malloc(sizeof(int));
    int* tempdataptr= (int *)malloc(sizeof(int)) ;
    int* tempdataptr2= (int *)malloc(sizeof(int)) ;

    printf("Enter data: ");
    scanf("%d" , dataptr);

    *tempdataptr=*dataptr;
    *tempdataptr2=*dataptr;


    int*c = (int *)malloc(sizeof(int)) ;
    *c=0;
    int nd= no_digits(tempdataptr);
    
    int * arr = (int * )malloc(sizeof(int)*nd);
    while (*tempdataptr2!=0)
        {
            *(arr + *c)   = *tempdataptr2 %10;
            *tempdataptr2 = (*tempdataptr2)/10;
            *c = (*c) + 1;
        }

    for ( int i=0 ; i <nd ; i++)
        {
            printf("%d  ",*(arr+i));
        }
    printf("\n");



    while(1){
        printf("\n\n1   Palindromic Number \n2  Armstrong Number\n3 Perfect Number\n4   Exit");
        int *choice =(int *)malloc(sizeof(int)) ;
        printf("\nEnter choice: ");
        scanf("%d" , choice);
        int * armstsum= (int*)(malloc(sizeof(int)));
        int * iter = (int * )malloc(sizeof(int));
        *iter=0;
        int * persum = (int * )malloc(sizeof(int));
        

        switch (*choice)
        {
            case 1:
                printf("Checking if %d is a palindromic number: \n\n",*dataptr);
                palindrom(arr , &nd);

                break;
            case 2:
                printf("Checking if %d is a armstrong number: \n\n\n",*dataptr);
                *armstsum=0;
                for(int i=0; i < nd ; i++)
                {   
                    *armstsum= *armstsum + pow(&(arr[i]) , &nd);
                }
                if (*armstsum == *dataptr)
                {
                    printf("it is an armstrong number \n");
                }
                else
                {
                    printf("it is not an armstrong number\n");
                }
                break;
            case 3:
                printf("Checking if %d is a perfect number: \n\n\n",*dataptr);
                *persum=0;
                *iter=1;
                while ( *iter <=(int)(*dataptr)/2 )
                {
                    if (*dataptr % (*iter) ==0)
                    {   
                        *persum=*persum + *iter;
                    }
                    (*iter)++;
                }

                if (*persum == *dataptr)
                {
                    printf("is a perfect number\n\n");
                }

                else{
                    printf("not a perfect number\n\n");
                }

                break;
            case 4:
                printf("exiting!! \n\n");
                return 0;
                break;
        }
    }






}




int palindrom(int*arr , int *siz)
{
    int flg=0;
    for (int i =0 ; i< *siz ; i++)
    {
        if (*(arr+i)!=*(arr+ (*siz)-i-1))
        {
                flg=1;
                break;
        }


    }
    if (flg==0)
    {
        printf("it is a palindromic number \n");
        return 0;
    }
    else
    {
    printf("not a palindromic number \n");
    return 1;
    }


}


int pow(int * a , int*n)
{
    int *b= (int *)(malloc(sizeof(int)));
    *b=*a;
    for (int i=0 ; i < (*n)-1 ; i++)
    {
        *b=(*b) * (*a);
    }
    return *b;

}