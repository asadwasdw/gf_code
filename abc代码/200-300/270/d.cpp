#include<iostream>
#include<algorithm>

using namespace std;

const int N =1e5+10;
int a[N];

int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=k;i++)cin>>a[i];

    bool ky=true;
    int ans=0;
    while(n)
    {
        while(a[k]>n)k--;
        if(ky)ans+=a[k];
        ky=!ky;
        n-=a[k];
    }
    cout<<ans<<endl;
}