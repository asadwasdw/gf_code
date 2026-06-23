#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N=500010,M=500020;

int n,m;
int h[N],e[M],ne[M],idx;
int color[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool dfs(int u,int c)
{
    color[u]=c;
    
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!color[j])
        {
            if(!dfs(j,3-c)) return false;
        }
        else if(color[j]==c) return false;
        
        
    }
    return true;
    
}
int a[N],b[N];

int main()
{
    cin>>m>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<=n;i++){
        cin>>b[i];
        add(a[i],b[i]);
        add(b[i],a[i]);
    }
    

    bool flag=true;
    for (int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1))
            {
                flag= false;
                break;
            }
        }
    }
    
    if(flag)cout<<"Yes"<<endl;
    else cout <<"No"<<endl;
}

