#include<algorithm>
#include<iostream>

using namespace std;

const int N=2e5+10;
long long  a[N],b[N];

long long rcg(long long a,long long b)
{
    if(b==0)return a;
    else return rcg(b,a%b);
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int j=1;j<=m;j++)cin>>b[j];



    if(n==1)
    {
        for(int j=1;j<=m;j++)cout<<a[1]+b[j]<<endl;
        return 0;
    }

    sort(a+1,a+n+1);



    long long t=a[2]-a[1];
    for(int i=3;i<=n;i++)
    {
        t=rcg(t,a[i]-a[1]);
    }

    for(int j=1;j<=m;j++)
    {
        cout<<rcg(t,a[1]+b[j])<<" ";
    }

    

}