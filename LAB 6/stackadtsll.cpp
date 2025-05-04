//Menu Based Program to implement stack ADT using a charectar array

#include <stdio.h>
#include <cstdlib>
#include <iostream>

class stack
{
    private:
        struct node
        {
            char data;
            struct node*next;
        };
        node *head;

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
                printf("data pushed into the stack successfully\n\n");

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




//Constructor Function That initializes head pointer to NULL
stack::stack()
{
    head=NULL;
}



//Function to push a given charectar to the top of the stack
int stack::push(char data)
{
        node*newnode=(node*)malloc(sizeof(node));
        newnode->data=data;
        newnode->next=head;
        head=newnode;
        return 0;



}


//Function to pop out the data at the top of the stack
char stack::pop()
{
        if (head==NULL)
            {
                printf("Empty List");
                return '\\';
            }
        
        else
        {
            node*temp=head;
            int r=temp->data;
            head=temp->next;
            free(temp);
            return r;
        }

}

char stack::peek()
{
    if (head==NULL)
    {
        return '\\';
    }
    return head->data;

}