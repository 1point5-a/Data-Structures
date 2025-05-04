//Program to find the maximum possible number of blocks on tower one after making/choosing not to make moves

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

//main function
int main()
{
    int t;
    cout<<"Enter number of test cases:              ";
    cin>>t; //inputs the number of testcases from the user
    for (int i=1 ; i<=t ;i++)
    {
        cout<<"\n\n";
        cout<<"*********  "<<"Test Case "<<i<<"  *********"<<endl;
        cout<<"\n";
        solve();
    }
}


//function that takes one test case from the user and displays the answer
void solve()
{
    int n;
    cout<<"Enter number of towers:                  ";
    cin>>n;
    cout<<"Enter number of blocks in each tower:    ";
    vector<int> arr(n);

    for (int i=0 ; i<n ;i++)
    {
        cin>>arr[i];
    }
    int ans;
    ans=arr[0];
    sort(arr.begin()+1 , arr.end());

    for(int j=1 ; j<n ; j++)
    {
        if (arr[j]>ans)
        {
            ans=(ans+arr[j]+1)/2 ;
        }
    }

    cout<<"max no of blocks in the first tower:     "<<ans<<endl;
}