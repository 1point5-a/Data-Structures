//program to solve the nene's game problem

#include <iostream>
#include <algorithm>
using namespace std;

int soln();


int main()
{
    int t;
    cout<<"Enter number of testcases: ";
    cin>>t;

    for (int i=0 ; i<t ; i++)
    {
        cout<<"******"<<" Testcase "<<i+1 <<"******"<<endl;
        int state=soln();
        if (state==1)
        {
            cout<<"Enter valid inputs: " <<endl;
            soln();
        }
    }
}





int soln()
{
    int k;
    int q;
    cin>>k>>q;
    int karr[k];
    int status=1;
    for (int i=0 ; i<k ; i++)
    {
        cin >> karr[i];
    }

    int qarr[q];
    for (int i=0 ; i<q ; i++)
    {
        cin >> qarr[i];
    }

    for (int i=0 ; i<q ; i++)
    {
        cout << min(qarr[i],karr[0]-1) <<" ";
        status=0;
    }    
    cout <<endl;
    return  status;
}


