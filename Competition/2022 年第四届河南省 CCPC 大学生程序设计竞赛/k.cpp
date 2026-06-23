#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int N=2e5+10;
int f[N];
int jl[N];
int st[N];
int hsize[N];
set<int>sz;
vector<int> ans[N];
long long ansmx[N];


int zh(int x,int sz)
{
   
    if(st[x]==2)return sz;
    else  
    {    sz++;
        st[x]++;
        jl[x]=0;
      return  hsize[x]=zh(f[x],sz);
    }
    
}

void  dfs(int x)
{
    
    if(st[x]==1)
    {
       hsize[x]= zh(x,0);
       return;
    }
    else if(st[x]>=2)return;
    st[x]++;
    dfs(f[x]);
    
}

int xzjl(int x)
{
   
    if(jl[x]==-1)
    {
        jl[x]=xzjl(f[x])+1;
    }
    st[x]++;
    return jl[x];
}



int main()
{
    int n; 
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        jl[i]=-1;
        //cin>>f[i];
        scanf("%d",&f[i]);
       // cout<<i<<" "<<f[i]<<endl;
    }

    for(int i=1;i<=n;i++)
    {
      //if(st[i]==0)
        dfs(i);
        if(jl[i]==-1)
        {
            st[i]++;
           //jl[i]=xzjl(f[i])+1;
        }
    }

  













  int res=0;
    for(int i=1;i<=n;i++)
    {
        if(jl[i]==0)res++;
    }

    cout<<res<<endl;

   
  
}