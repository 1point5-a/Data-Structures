#include <iostream>
#include <algorithm>
#include <vector>
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
        if (state!=0)
        {
            cout<<"Enter valid inputs: " <<endl;
            soln();
        }
    }
}



int soln()
{
    
    int n;
    cin >> n;
    vector <int> arr(n); 
    vector <int> sarr(n);
    for (int i=0 ; i<n ; i++) //order of n
    {
        cin >>arr[i];
        sarr[i] = arr[i];
    }
    sort(sarr.begin(),sarr.end()); //order of nlogn

    int max = sarr[n-1];
    int max2= sarr[n-2];

    for (int i=0 ; i<n ; i++) //order of n
    {
        if (arr[i]==max)
        {
            cout << max -max2 <<" ";
        }
        else
        {
            cout <<arr[i]-max<<" ";
        }

    }
    cout<<endl;
    return 0;

}