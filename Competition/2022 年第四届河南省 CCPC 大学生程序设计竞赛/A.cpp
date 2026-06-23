#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;cin>>n;
    if(n>10)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    int a[]={1,0,2,3,4,5,6,7,8,9};

    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    
}