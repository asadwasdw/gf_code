#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N= 1e5+10;
int a[N],s[N];
int b[N];
int cnt;
void solve()
{
    memset(a,0,sizeof a);
    int n;cin>>n;
    cnt=0;
    int mx=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        mx=max(x,mx);
        a[x]++;
    }

    for(int i=1;i<=mx;i++)
    {
        if(a[i]!=0){
            b[++cnt]=a[i];
        }
    }

    sort(b+1,b+cnt+1);
    //cout<<cnt<<endl;

    for(int i=1;i<=cnt;i++)
    {
        s[i]=s[i-1]+b[i];
       //cout<<b[i]<<" ";
    }
  // cout<<endl;

    for(int i=1;i<=n;i++)
    {
        int l=0,r=cnt;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(b[mid]<=i)l=mid;
            else r=mid-1;
        }
     //  cout<<l<<" ";
       long long ans=s[l];
      
            ans+=(i-1)*(cnt-l);
        cout<<ans<<endl;
    }
}


int main()
{       
    int n;cin>>n;
    while(n--)solve();
}