
//List ADT using a doubly linked list with a tail pointer

#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>

class list
{
    private:
        struct node
        {
            int data;
            struct node*next;
            struct node*prev;
        };

        node*head;
        node*tail;
    public:
        list();
        ~list();
        int insertbeg(int);
        int insertend(int);
        int insertpos(int ,int);
        void deletebeg();
        void deletepos(int);
        void deleteend();
        int search(int);
        void display(int dir=0);

};
















int main()
{
    int data;
    int choice;
    int pos;
    int dirn;
    list l;
    while(1)
    {
        
        printf("1 - Insert(beginning)\n");
        printf("2 - Insert(end)\n");
        printf("3 - Insert(position)\n");
        printf("4 - Delete(beginning)\n");
        printf("5 - Delete(end)\n");
        printf("6 - Delete(position)\n");
        printf("7 - Search\n");
        printf("8 - Display\n");
        printf("9 - Exit\n");
        printf("Enter Choice:   ");
        scanf("%d" , &choice);

        switch (choice)
        {
            

            case 1:
                printf("Enter data to insert: ");
                scanf("%d" , &data);
                l.insertbeg(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d" , &data);
                l.insertend(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d" , &data);
                printf("Enter position to insert: ");
                scanf("%d" , &pos);
                l.insertpos(data,pos);
                break;
            case 4:
                l.deletebeg();
                break;
            case 5:
                l.deleteend();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d" , &pos);
                l.deletepos(pos);
                break;
            case 7:
                printf("Enter data to search:  ");
                scanf("%d",&data);    
                if (l.search(data)!=-1)
                {
                    printf("Data found at position %d\n\n" , l.search(data));
                }
                else{
                    printf("Data not found\n\n");
                }
                break;
                break;
            case 8:
                printf("Enter direction (0 / 1): ");
                scanf("%d" , &dirn);
                l.display(dirn);
                break;
            case 9:
                printf("Exiting The Program\n");
                return 0;
                break;

        }





    }

}

list::list()
{
    head=NULL;
    tail=NULL;

}

//Inserts an element into the beginning of a doubly linked list
int list::insertbeg(int data)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->prev=NULL;
    if (head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        tail=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    return 0;


}



//Inserts an element into the end of a doubly linked list

int list::insertend(int data)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if (tail==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
        tail=newnode;
    }
    else
    {
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;

    }
    return 0;



}




//Inserts an element into a given position of a doubly linked list

int list::insertpos(int data ,int pos)
{

    if (pos == 0)
    {
        insertbeg(data);
        return 0;
    }
    
    node *temp = head;
    for (int i = 0; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    
    if (temp == NULL)  // Position is beyond list length
    {
        insertend(data);
        return 0;
    }
    
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    
    newnode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newnode;  // Fix the backward link
    
    temp->next = newnode;
    newnode->prev = temp;
    
    return 0;
    



}









//deletes the first element of the doubly linked list
void list::deletebeg()
{
    if (head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }

    node* temp = head;
    
    if (head->next == NULL)  // Only one node in the list
    {
        free(head);
        head = NULL;
        tail = NULL;  // Update tail to NULL
        return;
    }

    head = head->next;
    head->prev = NULL;
    
    free(temp);
}


//deletes the last element of the doubly linked list
void list::deleteend()
{
    if (head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }

    node* temp = tail;
    
    if (tail->prev == NULL)  // Only one node in the list
    {
        free(head);
        head = NULL;
        tail = NULL;  // Update tail to NULL
        return;
    }

    tail = tail->prev;
    tail->next = NULL;
    
    free(temp);
}



//deletes a given position from the doubly linked list
void list::deletepos(int pos)
{

    if (pos == 0)
    {
        deletebeg();
        return ;
    }
    
    node *temp = head;
    for (int i = 0; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    
    if (temp == NULL)  // Position is beyond list length
    {
        deleteend();
        return ;
    }
    
    node * temp2=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp2->prev;
    free(temp2);
    
    return ;
    



}


















//searches for a given element in the doubly linked list
int list::search(int data)
{
        if (head !=NULL)
        {            
            node*temp=head;
            int flg=0;
            int pos=0;
            while(temp->next!=NULL)
            {
                if (temp->data == data)
                {
                    flg=1;
                    break;
                }
                temp=temp->next;
                pos++;
            }
            if (flg==1)
            {
                return pos;
                }
            else
            {
                if(temp->data==data)
                {
                    return pos;
                }
                else
                {
                    return -1;
                }
            }

        }
        else
        {
            return -1;
        }
}

list::~list()
{
    node* temp = head;
    while (temp != NULL)
    {
        node* next = temp->next; // Store the next node
        free(temp);              // Free the current node
        temp = next;             // Move to the next node
    }
    head = NULL;
    tail = NULL;
}

//displays the doubly linked list based on the direction given by the user
//0-forward
//1-reverse
void list::display(int dir)
{   
        if (head !=NULL || tail!=NULL)
        {            
            
            if (dir==0)
            {
                node*temp=head;
                while(temp->next!=NULL)
                {
                    printf("%d",temp->data);
                    printf("\t");
                    temp=temp->next;
                }
                printf("%d",temp->data);
                printf("\t");
                printf("\n");
            }
            else
            {
                node*temp=tail;
                while(temp->prev!=NULL)
                {
                    printf("%d",temp->data);
                    printf("\t");
                    temp=temp->prev;
                }
                printf("%d",temp->data);
                printf("\t");
                printf("\n");
            }
            }
        else{
            printf("Empty List.");
        }
}

