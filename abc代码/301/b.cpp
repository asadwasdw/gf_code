#include<iostream>
#include<algorithm>


using namespace std;

const int N=1e5+10;
int a[N];

int xh(int l,int r)
{
  // cout<<l<<" "<<r<<endl;
    if(l>r)
    {
        for(int i=l-1;i>r;i--)cout<<i<<" ";
    }
    else 
    {
         for(int i=l+1;i<r;i++)cout<<i<<" ";
    }


    return 0;
}

int main()
{
    int t;cin>>t;

    for(int i=1;i<=t;i++)
    {
        cin>>a[i];
    }

   cout<<a[1]<<" ";


    for(int i=2;i<=t;i++)
    {

        xh(a[i-1],a[i]);
        cout<<a[i]<<" ";
    }
    return 0;

    
}