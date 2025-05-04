#include <stdio.h>
#include <cstdlib>

class shape
{
    public :

        int squarearea(int length)
        {
            return (length*length);
        }


        int cubearea(int side)
        {
            return (6*side*side);
        }


        int rectanglearea(int length , int breadth)
        {
            return (length*breadth);
        }


        int cuboidarea(int length , int breadth , int height)
        {
            return (2*(length*breadth + breadth*height + length*height));
        }

};






int main(void)
{
    shape Shape;
    int length;        
    int breadth;
    int height;
    int side;

    while(1)
    {
        printf("1   SQUARE \n2   CUBE\n3   RECTANGLE\n4   CUBOID\n5   EXIT\n");
        int choice;
        printf("enter choice    ");
        scanf("%d" , &choice) ;    

        switch (choice){
            case 1:
                
                printf("Enter Length:   ");
                scanf("%d",&length);
                printf("AREA OF SQUARE =  %d\n",Shape.squarearea(length));
                break;
            case 2:
                int side;
                printf("Enter SideLength:   ");
                scanf("%d",&side);    
                printf("AREA OF CUBE =  %d \n",Shape.cubearea(side));

                break;
            case 3:
                
                printf("Enter Length:   ");
                scanf("%d",&length);

                
                printf("Enter breadth:   ");
                scanf("%d",&breadth);


                printf("AREA OF RECTANGLE =  %d \n",Shape.rectanglearea(length , breadth));

                break;

            

            case 4:
                
                printf("Enter Length:   ");
                scanf("%d",&length);

                
                printf("Enter breadth:   ");
                scanf("%d",&breadth);

                printf("Enter height:   ");
                scanf("%d",&height);
                printf("AREA OF CUBOID =  %d \n",Shape.cuboidarea(length , breadth , height));

                break;


            case 5:
                puts("exiting goodbye!");
                return 0;
                break;
        }
    }
        
}