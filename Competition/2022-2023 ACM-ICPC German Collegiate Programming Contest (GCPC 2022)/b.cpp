#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
 
 
using namespace std;
 
#define int long long 
 
const int N=4000;
const int M=2e7+10;
int g[N][N];
 
int a[N],b[N];
int match[N];
int n,m;
int num;
 
bool st[M];
int p[M];
int cnt;
 
int H[N],e[N],ne[N],idx;
 
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=H[a];
    H[a]=idx++;
}
 
 
void prime(int n)
{
    n--;
    for(int i=2;i<=n;i++)
    {
        if(!st[i])p[cnt++]=i;
 
        for(int j=0;p[j]*i<=n;j++)
        {
            st[p[j]*i]=true;
            if(i%p[j]==0)break;
        }
    }
}
 
 
 
bool find(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(!g[x][i])continue;
        if(st[i])continue;
        st[i]=true;
 
        if(match[i]==0||find(match[i]))
        {
            match[i]=x;
            return true;
        }
    }
    return false;
 
}
 
 
 
signed main()
{
      ios::sync_with_stdio(false);
      cin.tie(0),cout.tie(0);
    cin>>num;
    unordered_map<int,int>h;
 
    memset(H,-1,sizeof H);
 
    for(int i=1;i<=num;i++)
    {
        int x;
        cin>>x;
 
        if(x%2==0)
        {
            b[++m]=x;
        }
        else {
            if(x==1&&h[x]==0)a[++n]=x;
            else if(x!=1)a[++n]=x;
            h[x]++;
        }
    }
 
    prime(M);
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //cout<<a[i]+b[j]<<endl;
            if(!st[a[i]+b[j]])
            {
                 g[i][j]=1;
               //cout<<i<<" "<<j<<" "<<a[i]<<" "<<b[j]<<endl;
            }
        }
    }
 
    int res=0;
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)st[j]=0;
        if(find(i))res++;
    }
 
    cout<<n+m-res<<endl;
    return 0;
 
 
}