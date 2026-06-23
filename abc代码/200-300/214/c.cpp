#include<iostream>
#include<algorithm>

using namespace std;
const int N=2e5+10;

long long a[N],b[N];
long long w[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
     for(int i=1;i<=n;i++)cin>>b[i];
     for(int i=2;i<=n;i++){
        long long t=b[i];
        if(i!=2)t=min(w[i-1]+a[i-1],t);
        w[i]=t;
     }

   
        w[1]=min(b[1],w[n]+a[n]);

        for(int i=2;i<=n;i++){
        long long t=b[i];
        t=min(w[i-1]+a[i-1],t);
        w[i]=min(t,w[i]);
     }
    for(int i=1;i<=n;i++)cout<<w[i]<<endl;

}