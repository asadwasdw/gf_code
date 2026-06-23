#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
#define int long long
const int N=1e3+10;
typedef pair<int,int>PII;
int w[N];
map<PII,PII>st;
unordered_map<int,vector<int>>edgs;
const int INF=0x3f3f3f3f3f3f3f3f;
bool ST[N];

PII dfs(int u,int d,int f)
{
   //cout<<u<<" "<<d<<endl;

    if(u==d)
    {
        return {0,w[d]};
    }

    if(st[{u,d}].first!=0)
    {
        return st[{u,d}];
    }

    if(find(edgs[u].begin(),edgs[u].end(),d) != edgs[u].end()){

        auto t=dfs(d,d,u);
        return {t.first+1,t.second+w[u]};
    }

    PII ans={INF,INF};
    for(auto t:edgs[u]){
        if(t==f)continue;
        if(ST[t])continue;
        ST[t]=true;

        PII T=dfs(t,d,u);
        if(T.first<ans.first){
            ans=T;
        }
        else if(T.first==ans.first&&T.second>ans.second)
        {
            ans=T;
        }
        ST[t]=false;

    }

    
    ans.first+=1;
    ans.second+=w[u];

    return st[{u,d}]=ans;
}



signed main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        string t;cin>>t;
        for(int k=0;k<n;k++)
        {
            if(t[k]=='Y'){
                edgs[i].push_back(k+1);
            }
        }
    }
    int m;
    cin>>m;
    while(m--)
    {
        int a,b;cin>>a>>b;
        auto T=dfs(a,b,-1);
        if(T.first>=INF/2){
            cout<<"Impossible"<<endl;
            continue;
        }
        cout<<T.first<<" "<<T.second<<endl;
    }

    return 0;




}