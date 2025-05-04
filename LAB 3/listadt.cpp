/*list ADT using array*/

#include <stdio.h>
#include <cstdlib>

class list
{
    public:
        int arr[5];
        int curr =-1;
        int isempty(void)
        {
            if (curr==-1)
            {
                printf("Empty Array \n");
                return 1;
            }
            else
            {return 0;}
        }
        void display_();
        int insertbeg(int data);
        int insertend(int data);
        int insertpos(int data,int pos);
        int deletebeg();
        int deleteend();
        int deletepos(int pos);
        int search(int data);
        void rotate(int k);
    
};




int main()
{

    list l;

    while(1)
    {
        printf("1   DISPLAY\n2   INSERT(Begginning)\n3   INSERT(end)\n4   INSERT(position)\n5   DELETE(Begginning)\n6   DELETE(end)\n7   DELETE(position)\n8   SEARCH \n9   ROTATE\n10  EXIT\n");
        printf("ENTER CHOICE:    ");
        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                l.display_();
                break;
            case 2:
                int data;

                printf("enter data to insert:   ");
                scanf("%d",&data);
                l.insertbeg(data);
                break;
            case 3:
                printf("enter data to insert:   ");
                scanf("%d",&data);
                l.insertend(data);
                break;                
            case 4:
                int pos;
                printf("enter data to insert:   ");
                scanf("%d",&data);
                printf("enter position to insert:   ");
                scanf("%d",&pos);         
                l.insertpos(data,pos);      
                break;
            case 5:
                if (l.isempty()) {
                    printf("List is empty, cannot delete.\n");
                } else {
                    l.deletebeg();
                }
                break;

            case 6:
                if(l.isempty()){break;}
                else
                {
                    l.deleteend();
                }
                break;
            case 7:
                if(l.isempty()){break;}
                else
                {
                    printf("enter position to delete:   ");
                    scanf("%d",&pos);         
                    l.deletepos(pos);                      
                    
                }
                break;
            case 8:
                printf("enter data to search:   ");
                scanf("%d",&data);
                l.search(data);
                break;
            case 9:
                printf("enter no of rotations:   ");
                scanf("%d",&data);
                l.rotate(data);
                break;
            case 10:
                break;

        }





    }





}




void list::display_()
        {
            for(int i=0; i <=curr ; i++)
            {
                printf("     %d     ",arr[i]);
            }
            printf("\n\n");
        }


int list::insertbeg(int data)
{
        if (curr>=5)
        {
            return 1;
        }
        else
        {
                curr++;
                for(int i=curr; i>0; i--)
                {
                    arr[i]=arr[i-1];
                }
                arr[0]=data;
                return 0;
        
        }
}


int list::insertend(int data)
        {
            if (curr<=4)
            {
                curr++;
                arr[curr]=data;

                return 0;
            
            }else
            {
    
                return 1;
                }

        }




int list::insertpos(int data,int pos)

        {
            if (curr>=5)
            {
                    return 1;
            }
            curr++;
            for(int i=curr; i>pos; i--)
            {
                arr[i]=arr[i-1];
            }
            arr[pos]=data;
            return 0;

        }


int list::deletebeg()
{

            for(int i=0; i<curr; i++)
            {
                arr[i]=arr[i+1];
            }
            curr=curr-1;
            return 0;

        }

int list::deleteend()
{

        curr--; 
        return 1;
}

int list::deletepos(int pos)
{

            for(int i=pos; i<curr; i++)
            {
                arr[i]=arr[i+1];
            }
            curr=curr-1;
            return 0;

        }


int list::search(int data)
{

            for(int i=0; i<=curr; i++)
            {
                if(arr[i]==data)
                {
                    printf("found at %d\n" , i);
                    return 0;
                }
            }
            printf("not found\n");
            return 1;


    }


    void list::rotate(int k)
    {
        int uhh=curr;
        for(int i=0 ; i <k ; i++)
        {

            insertbeg(arr[curr]);
            curr=uhh;
        }
        curr=uhh;
    }