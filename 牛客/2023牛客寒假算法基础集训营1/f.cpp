#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int N=1e5+10;

int f[N];
long long num[N];
long long zd[N];
bool st[N];
int find(int x)
{
    if(x!=f[x])return f[x]=find(f[x]);
    return x;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        num[i]=1;
    }

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(find(a)!=find(b)){
            num[find(b)]+=num[find(a)];
            f[find(a)]=find(b);
        }
    }

    int gs=0;
    int wz=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x){
            if(zd[find(i)]==0)gs++;
            zd[find(i)]+=i;
            if(wz==0){
               // cout<<x<<i<<endl;
                wz=i;
            }
        }
    }

    long long ans=0;
    if(gs==0)
    {
        for(int i=1;i<=n;i++){
            int t=find(i);
            if(!st[t]){
                st[t]=true;
                ans+=num[t]*num[t];
              //  cout<<num[t]<<endl;
            }
        }
    }
    else if(gs==1){
       // cout<<wz<<endl;
        ans=num[find(wz)]*num[find(wz)];
    }

    cout<<ans<<endl;


}