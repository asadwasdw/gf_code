#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N=1e5+10;
ll a[N];

int main()
{

    for(int i=1;i<=100000;i++)
    {
        a[i]=a[i-1]+i;
    }

    int t;cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        cout<<a[x-1]<<endl;
    }
  
   
   
}