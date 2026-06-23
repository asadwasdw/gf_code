#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int f[N];

int find(int x){
    if(x!=f[x])return f[x]=find(f[x]);
    return x;
}
int root;
int y;
int st[N];

bool dfs(int u,int fa)
{

    for(auto t:edg[u]){
        if(t==fa)continue;
        if(t==y){
            //cout<<t<<endl;
            st[t]++;
            return true;
        }

        if(dfs(t,u)){
           // cout<<t<<endl;
            st[t]++;
            return true;
        }
    }

    return false;
}

void dfs2(int u,int fa,int bj)
{
    f[u]=bj;

    for(auto t:edg[u]){
        if(t==fa)continue;
        if(st[t])continue;
        dfs2(t,u,bj);
    }
}




void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)f[i]=i;

    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        
        int fa=find(a);
        int fb=find(b);
        //cout<<a<<" "<<b<<endl;
        //cout<<fa<<" "<<fb<<endl;
        if(fa==fb){
            root = a;
            y =b;
            continue;
        }

        edg[a].push_back(b);
        edg[b].push_back(a);
        f[fa]=fb;


        // cout<<i<<endl;
        // for(int i=1;i<=n;i++)cout<<find(i)<<" ";cout<<endl;
    }
    st[root]++;
    dfs(root,0);
    for(int i=1;i<=n;i++)f[i]=0;

    for(int i=1;i<=n;i++)
    {
        if(f[i]==0){
            if(st[i]){
                dfs2(i,0,i);
            }
        }

    }


    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(f[a]!=f[b])cout<<"No"<<endl;
        else cout <<"Yes"<<endl;
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