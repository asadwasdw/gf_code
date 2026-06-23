#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

unordered_map<string,bool>st;
string s[10];
int ST[N];
int n,m;
bool zd;
void dfs(int num,string t,int num_)
{
    if(num==n){
        if(t.size()<3||t.size()>16)return;
        if(!st[t]){
            cout<<t<<endl;
            zd=true;
        }
        return;
    }
    if(zd)return;

    for(int i=1;i<=n;i++)
    {
        if(ST[i])continue;

        ST[i]=true;
        string T = t+s[i];
        if(num!=n-1)
            while(T.size()<=16&&num_--){
                T+='_';
                dfs(num+1,T,num_);
                if(zd)return ;
            }
        else {
            dfs(num+1,T,0);
        }
        ST[i]=false;
    }
}

void solve()
{
    cin>>n>>m;
    int sz= 0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        sz+=s[i].size();
    }

    for(int i=1;i<=m;i++){
        string t;
        cin>>t;
        //cout<<t<<endl;
        st[t]=true;
    }

    if(sz+n-1>16){
        cout<<"-1\n";
        return ;
    }
    string t;
    dfs(0,t,16-sz);
    if(!zd)cout<<"-1\n";
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