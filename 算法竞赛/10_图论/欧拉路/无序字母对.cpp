#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

map<PII,int>edg;
map<char,int>d;
vector<char>ans;
int f[N];

// int find(int x)
// {
//     if(x!=f[x])return f[x]=find(f[x]);
//     return x;
// }

void dfs(char u)
{
    int cnt=0;
    for(int i=0;i<26;i++){
        char v = (char)(i+'A');
        if(edg[{u,v}]){
            edg[{u,v}]--;
            edg[{v,u}]--;
            dfs(v);
            cnt++;
            if(cnt>=2)cout<<"s";
        }
    }
    for(int i=0;i<26;i++){
        char v = (char)(i+'a');

        if(edg[{u,v}]){
            edg[{u,v}]--;
            edg[{v,u}]--;
            dfs(v);
            cnt++;
            if(cnt>=2)cout<<"s\n";
        }
    }
     ans.push_back(u);
    
}


void solve()
{
    int n;cin>>n;
    char qd='Z';
    for(int i=1;i<=n;i++)
    {
        char v,u;
        cin>>v>>u;
        qd=min({v,u,qd});
        edg[{u,v}]++;
        edg[{v,u}]++;
        d[v]++;
        d[u]++;
    }
    int js=0;

    bool zd=false;
    
    for(int i=0;i<26;i++)
    {
        if(d[(char)('A'+i)]%2)
        {
            if(!zd)qd=(char)('A'+i);
            zd=true;
            js++;
        }
    }
   
    for(int i=0;i<26;i++)
    {
        if(d[(char)('a'+i)]%2)
        {
            if(!zd)qd=(char)('a'+i);
            zd=true;
            js++;
        }
    }
    // cout<<js<<endl;
    // cout<<qd<<endl;
    if(js!=2&&js!=0)
    {
        cout<<"No Solution"<<endl;
        return;
    }

    dfs(qd);
    //cout<<ans.size()<<endl;
    // cout<<qd<<endl;
    if(ans.size()!=n+1)
    {
        cout<<"No Solution"<<endl;
        return;
    }
    
    reverse(ans.begin(),ans.end());
    for(auto t:ans)cout<<t;

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