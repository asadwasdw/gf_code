#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
bool st[N];
bool flag=false;
stack<int>s;
bool ish[N];



void findh(int u,int fa)
{
    //cout<<u<<endl;
    if(flag)return;
    s.push(u);
    st[u]=true;
    for(auto v:edg[u]){
        if(v==fa)continue;

        if(st[v])
        {
            //cout<<v<<"S"<<endl;
            while(s.size()&&v!=s.top()){
              //  cout<<s.top()<<endl;
                ish[s.top()]=true;
                s.pop();
            }
          
            ish[v]=true;
            flag=true;
            return ;
        }
        findh(v,u);
    }
    if(s.size())s.pop();
}

int mx = INF;

void dfs(int u,int fa)
{
    cout<<u<<" ";
    st[u]=true;

    sort(edg[u].begin(),edg[u].end());
    for(int i=0;i<edg[u].size();i++)
    {
        int v = edg[u][i];

        if(v==fa||st[v])continue;
        if(!ish[v])dfs(v,u);
        else 
        {
            if(flag==false)
            {
                int t = (i+1<edg[u].size()?edg[u][i+1]:mx);
                if(t==fa)mx = (i+2<edg[u].size()?edg[u][i+2]:mx);
                else mx = t;
            }

            if(mx<v&&flag==false)
            {
                //cout<<"s"<<u<<endl;
                flag = true;
                //continue;
            }
            else dfs(v,u);
        }


    }
    
}




void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    if(n==m-1)
    {
        flag=true;
    }
    else {
        findh(1,0);
        flag=false;
        memset(st,0,sizeof st);
    }

    //for(int i=1;i<=n;i++)if(ish[i])cout<<i<<" ";cout<<endl;
 //cout<<"s"<<endl;
    dfs(1,0);
    



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}