#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;


const int N=4e5+10;

int h[N],e[N],ne[N],idx;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

typedef pair<int,int>PII;


bool st[N];
int path[N];

int ans=0;

void dfs(int u)
{
    //cout<<u<<endl;
    ans++;
    if(ans>=1e6)return;

    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(ans>=1e6)return;
        if(st[j])continue;
        
        st[j]=true;
        dfs(j);

        if(ans>=1e6)return;
        st[j]=false;
    }


}



int main()
{
    int n,m;cin>>n>>m;

    memset(h,-1,sizeof h);

    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    st[1]=true;
    dfs(1);

    cout<<ans<<endl;

}