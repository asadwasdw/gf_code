#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define int long long
const int N=65;

int a[N];
int n,x;
map<int,map<int,int>>f;

int dfs(int sum,int i)
{
    if(i==1)return sum;
    if(f[sum][i])return f[sum][i];
    if(sum%a[i]==0)return sum/a[i];
    
    int res=sum/a[i];

    int w1=res+dfs(sum-res*a[i],i-1);
    int w2=res+1+dfs((res+1)*a[i]-sum,i-1);
    return f[sum][i]=min(w1,w2);
}


signed main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<dfs(x,n)<<endl;
}