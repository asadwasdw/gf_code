#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,string>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

map<string,int>d;
map<string,int>fz;
int cnt = 0;
int f[N];
int find(int x){
    if(x!=f[x]) f[x]=find(f[x]);
    return f[x];
}


void solve()
{
    for(int i=1;i<=250000*2+1;i++)f[i]=i;
    string u,v;
    while(cin>>u)
    {
        cin>>v;
        d[u]++;
        d[v]++;
        if(fz[u]==0){
            ++cnt;
            fz[u]=cnt;
        }
        if(fz[v]==0){
            ++cnt;
            fz[v]=cnt;
        }
        if(find(fz[u])!=find(fz[v]))
        {
            f[find(fz[u])]=find(fz[v]);
        }

    }
    int js=0;
    for(auto t:d){
        if(t.second%2){
            js++;
        }
    }

    for(int i=1;i<=cnt;i++)
    {
       // cout<<find(i)<<endl;
        if(find(i)!=find(1)){
            cout<<"Impossible";
            return;
        }
    }


    if(js&&js!=2)cout<<"Impossible";
    else cout<<"Possible";

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