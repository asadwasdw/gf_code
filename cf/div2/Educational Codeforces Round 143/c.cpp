#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=2e5+10;

long long c[N],a[N],s[N];
long long num[N],snum[N];
long long sc[N];
void solve()
{

    int n;cin>>n;
    memset(sc,0,sizeof sc);
    memset(num,0,sizeof num);
    memset(snum,0,sizeof snum);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }


    for(int i=1;i<=n;i++)
    {
        int l=i-1,r=n;
        while(l<r){
           long long mid=l+r+1>>1;
            if(s[mid]-s[i-1]<=c[i])l=mid;
            else r=mid-1;
        }
       // cout<<l<<endl;

        snum[i]++;
        snum[l+1]--;
       sc[l+1]+=c[i]-(s[l]-s[i-1]);
    }

    for(int i=1;i<=n;i++)
    {
        num[i]=snum[i]+num[i-1];
       // cout<<num[i]<<" ";
        cout<<num[i]*a[i]+sc[i]<<" ";
    }

    cout<<endl;

    

}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}