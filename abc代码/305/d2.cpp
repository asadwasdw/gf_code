#include<iostream>
#include<algorithm>

using namespace std;


const int N =2e5+10;
int a[N];
int b[N];
int n;

int zl(int x)
{
    int l=0,r=n;
    while(l<r){
        int mid=l+r+1>>1;
        if(a[mid]<=x)l=mid;
        else r=mid-1;
    }
    return l;
}


int main()
{
    cin>>n;
    n--;
    for(int i=0;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        if(i%2==0)b[i]+=b[i-1]+a[i]-a[i-1];
        else b[i]=b[i-1];
    }

   // for(int i=0;i<=n;i++)cout<<b[i]<<" ";cout<<endl;

    int q;cin>>q;
    b[n+1]=b[n];

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        int L = zl(l);
        int R = zl(r);

        int ansl=b[L];
        if(b[L+1]!=b[L])ansl+=l-a[L];

        int ansr=b[R];
        if(b[R+1]!=b[R])ansr+=r-a[R];
        // cout<<a[L]<<" "<<a[R]<<" ";
        // cout<<ansl<<" "<<ansr<<endl;
        cout<<ansr-ansl<<endl;
    }

}