#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

vector<vector<PII>>edg(N);

int st[N];
int f[N];
int n,m,q;
bool wj[N];
bool zg[N];
int find(int x)
{
    if(x!=f[x])return f[x]=find(f[x]);
    return f[x];
}


void bfs(int x)
{
    int u = find(x);
    if(zg[u])return;
    zg[u]=true;
    queue<PII>q;
    q.push({u,0});
    st[u]=0;


    while(q.size()){
        auto t = q.front();q.pop();
        
        for(auto j:edg[t.first]){
            if(j.first==t.first&&j.second!=0)wj[u]=true;
           //cout<<j.first<<endl;
            if(j.first==u)continue;
            if(st[j.first]==0){
                st[j.first]=j.second+t.second;
                //cout<<j.second+t.second<<endl;
                 q.push({j.first,st[j.first]});
                //cout<<j.first<<endl;
            }
            else{
                if(st[j.first]==j.second+t.second){

                }
                else 
                {
                    wj[u]=true;
                    return ;
                }
            }
           
        }
    }
}

void solve()
{
    cin>>n>>m>>q;
    for(int i=0;i<=n+1;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        edg[a].push_back({b,c});
        edg[b].push_back({a,-c});
        //cout<<a<<" "<<b<<" "<<c<<endl;
        if(find(a)!=find(b))
        {
            f[find(a)]=find(b);
        }
    }

    //bfs(1);

    for(int i=1;i<=n;i++)
    {
        if(!st[i]){
            bfs(i);
        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     if(wj[find(i)])cout<<i<<" YES ";
    //     cout<<find(i)<<" "<<st[i]<<endl;
    // }

    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(find(x)!=find(y))cout<<"nan"<<endl;
        else if(wj[find(x)])cout<<"inf"<<endl;
        else 
        {
            cout<<st[y]-st[x]<<endl;
        }
    }
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