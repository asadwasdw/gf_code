#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;
int a[N];

void solve()
{
    int n,k;cin>>n>>k;
    int l=0,r=0;
    for(int i=1;i<=n;i++)
    {
        int t;scanf("%1d",&t);
        a[i]=t;
        if(t==1)
        {
            if(l==0)l=i;
            r=i;
        }
    }
  
    if(k>=n-r&&a[n]==0&&r!=0&&r!=n){
        k-=n-r;
        a[n]=1;
        a[r]=0;
    }
    if(k>=l-1&&a[1]==0&&a[l]==1&&l!=n&&l!=1&l!=0){
        k-=l-1;
        a[1]=1;
        a[l]=0;
    }
    long long ans=0;
    for(int i=1;i<n;i++){
        ans+=a[i]*10+a[i+1];
     //cout<<a[i]<<" ";
    }
    // cout<<a[n];

    cout<<ans<<endl;

}

int main()
{
    int t;cin>>t;while(t--)
    solve();
}