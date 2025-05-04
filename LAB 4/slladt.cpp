
/*
Program to implement list ADT using a Singly Linked List
*/


#include <cstdio>
#include <stdlib.h>

class list
{
    private:
        struct node
        {
            int data;
            struct node*next;
        };
        node *head;

    public:
        list();
        ~list();
        int insertbeg(int);
        int insertend(int);
        int insertpos(int ,int);
        int deletebeg();
        int deleteend();
        int deletepos(int);
        int search(int);
        void dispreversehelper(node*);
        void dispreverse();
        int reverse();
        void display();
};








int main()
{
    list l;
    while (1)
    {
        printf(" 1 - Insert (Beginning)\n");
        printf(" 2 - Insert (end)\n");
        printf(" 3 - Insert (position)\n");
        printf(" 4 - Delete (beginning) \n");
        printf(" 5 - Delete (end) \n");
        printf(" 6 - Delete (position) \n");
        printf(" 7 - Search \n");
        printf(" 8 - Reverse (display) \n");
        printf(" 9 - Reverse(link) \n");
        printf("10 - Display \n");
        printf("11 - Exit \n");
        printf("Enter choice:   ");
        int choice;
        scanf("%d",&choice);
        int data;
        int pos;


        switch(choice)
        {
            case 1:
            printf("Enter data to insert:  ");
            scanf("%d",&data);
                l.insertbeg(data);
                break;

            case 2:
                printf("Enter data to insert:  ");
                scanf("%d",&data);
                l.insertend(data);
                break;
            case 3:
                printf("Enter data to insert:  ");
                scanf("%d",&data);
                printf("Enter position to insert:  ");
                scanf("%d",&pos);
                l.insertpos(data,pos);
                break;

            case 4:
                l.deletebeg();
                break;
            case 5:
                l.deleteend();
                break;

            case 6:
                printf("Enter position to delete:  ");
                scanf("%d",&pos);
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

            case 8:
                l.dispreverse();
                printf("\n");
                break;
            case 9:
                l.reverse();
                break;
            case 10:
                l.display();
                break;

            case 11:
                return 0;
                break;
        }
    }



}

list::~list()
{
    node*temp;
    while (head!=NULL)
    {
        temp=head;
        head->next=temp;
        free(temp);

    }

}



list::list()
{
    head=NULL;
}





//Inserts given data into the beginning of the list
int list::insertbeg(int data)
{
    node*newnode=(node*)malloc(sizeof(node));
    if (newnode==NULL)
    {
        return  1;
    }
    else
    {
        newnode->data=data;
        newnode->next=head;
        head=newnode;
        return 0;
    }
}



//Inserts given data into the end of the list
int list::insertend(int data)
{
    node*newnode=(node*)malloc(sizeof(node));
    if (newnode==NULL)
    {
        return  1;
    }
    else
    {
        newnode->data=data;
        if (head==NULL)
        {
            newnode->next=head;
            head=newnode;}
        
        else
        {
            node*temp=head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=NULL;

        }
        return 0;


    }
}

//Inserts data into the position(index) given by the user
int list::insertpos(int data , int pos)
{
    node*newnode=(node*)malloc(sizeof(node));
    if (newnode==NULL)
    {
        return  1;
    }
    else
    {
        if (head==NULL or pos==0)
        {
            insertbeg(data);
            return 0;
        }
        node*temp=head;

        for(int i=0; i<pos-1 && temp->next !=NULL ; i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->data=data;
        return 0;
    }

}



//Deletes element from the beginning of the list
int list::deletebeg()
{

        if (head==NULL)
            {
                printf("Empty List");
                return -1;
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

//Deletes element from the end of the list
int list::deleteend()
{
    {
        if (head==NULL)
            {
                printf("Empty List");
                return -1;
            }
        
        else
        {
            node*temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            node*temp2=temp->next;
            int r=temp2->data;
            temp->next=NULL;
            free(temp2);
            return r;


        }
    }
}

//Deletes element from the end of the list
int list::deletepos(int pos)
{
    {
        if (head==NULL || pos<0)
            {
                return -1;
            }
        
        else
        {
            node*temp=head;
            int i=0;
            if (pos==0)
            {
                return deletebeg();
                
            }
            while(i<pos-1 && temp->next->next!=NULL)
            {
                temp=temp->next;
                i++;
            }
            node*temp2=temp->next;
            int r=temp2->data;
            temp->next=temp->next->next;
            free(temp2);
            return r;


        }
    }
}

//Searches through the list contents and tries to find "data"
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




void list::dispreversehelper(node*a)
{
    if (a==NULL)
    {
        return;
    }
    dispreversehelper(a->next);
    printf("%d",a->data);
    printf("\t");

}


void list::dispreverse()
{
    dispreversehelper(head);
}

    
int list::reverse()
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return -1;
    }

    node* curr=head;
    node*prev=NULL;
    node * next=head->next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return 0;
}




//displays the contents of the singly linked list
void list::display()
{   
        if (head !=NULL)
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
        else{
            printf("Empty List.");
        }
}