#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<unordered_map>
#include<vector>
#include<cstring>

using namespace std;

const int N=1010;


int ST[N];
int a[N],b[N];
int n;
int st[N];
unordered_map<int,vector<int>>edge;

void dfs(int x,int b)
{
    st[x]++;
    ST[x]=1;
    for(auto t:edge[x]){
        if(t==b)continue;
        if(ST[t])continue;
      
        dfs(t,b);
    }
}



int pd(int u)
{
    memset(st,0,sizeof st);
    int ua=a[u],ub=b[u];
    memset(ST,0,sizeof ST);
    dfs(u,0);

    memset(ST,0,sizeof ST);
    dfs(ua,u);

    memset(ST,0,sizeof ST);
    dfs(ub,u);
   

    for(int i=1;i<=n;i++){
        if(st[i]>=3)return true;
    }
    return false;
}

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        edge[a[i]].push_back(i);
        edge[b[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){

        if(pd(i))cout<<"Y";
        else cout<<"N";

    }

    return 0;

}