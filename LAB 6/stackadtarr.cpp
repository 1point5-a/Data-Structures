//Menu Based Program to implement stack ADT using a charectar array

#include <stdio.h>
#include <cstdlib>
#include <iostream>

class stack
{
    private:
        int curr;
        char stk[5];

    public:
        stack();
        int push(char);
        char pop();
        char peek();



};



int main()
{
    printf("***    Stack Operations    ***\n");
    int choice;
    char data;
    stack s;
    char popped;
    char peeked;
    int status;
    while(1)
    {

        printf("1   to  Push\n");
        printf("2   to  Pop\n");
        printf("3   to  Peek\n");
        printf("4   to  Exit\n");
        printf("\n");
        printf("Enter Choice: ");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Data To Push: ");
                scanf(" %c",&data);
                status=s.push(data);
                if (status==0)
                {
                    printf("data pushed into the stack successfully\n\n");
                }
                else
                {
                    printf("Stack Full , unable to push data\n");
                }
                break;

            case 2:
                popped=s.pop();
                if (popped!='\\')
                {
                    printf("data popped out of the stack successfully\n");
                    printf("data popped = %c\n\n" , popped);
                }
                else
                {
                    printf("Stack Empty , unable to pop data\n\n");
                }
                break;


            case 3:
                peeked=s.peek();
                if (peeked!='\\')
                {
                    printf("data peeked from the top of the stack successfully\n");
                    printf("data peeked = %c\n\n" , peeked);
                }
                else
                {
                    printf("Stack Empty , unable to peek data\n\n");
                }
                break;


    
            case 4:
                printf("Exiting the Program...\n");
                return 0;
                break;
            default:
                printf("Enter valid choice...\n\n");
                break;
        }
    }




}




//Constructor Function That initializes current variable to -1
stack::stack()
{
    curr=-1;
}



//Function to push a given charectar to the top of the stack
int stack::push(char data)
{
    if (curr==4)
    {
        return -1; //array full 'stack overflow??'
    }

    curr++;
    stk[curr]=data;
    return 0;

}

char stack::pop()
{
    if (curr==-1)
    {
        return '\\'; //empty stack 'underflow'
    }
    curr--;
    return stk[curr+1];

}

char stack::peek()
{
    if (curr==-1)
    {
        return '\\'; //empty stack 'underflow'
    }

    return stk[curr];

}