#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,bool>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

unordered_map<char,int>d;
unordered_map<char,vector<PII>>edg;
vector<string>ans;


void dfs(char u)
{
    //cout<<u<<endl;
    for(auto &T:edg[u]){
        string t = T.first;
        if(T.second)continue;
        T.second=true;
        //cout<<t<<endl;
        char v=t[t.size()-1];
        dfs(v);
        ans.push_back(t);
    }
}

int f[N];
unordered_map<char,int>fz;
int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}



void solve()
{


    for(char i = 1;i<=26;i++){
        f[i]=i;
    }
    int cnt = 0;

    int n;cin>>n;
    char qd='z';
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        char u =a[0];
        char v = a[a.size()-1];
        d[u]++;
        d[v]--;
        qd=min({u,v,qd});
        edg[u].push_back({a,false});

        if(fz[u]==0){
            cnt++;
            fz[u]=cnt;
        }

        if(fz[v]==0){
            cnt++;
            fz[v]=cnt;
        }
        f[find(fz[u])]=find(fz[v]);
    }
    int cnt1 = 0;
    int cnt_1 = 0;
    for(int i=0;i<26;i++)
    {
        char t = 'a'+i;
        if(d[t]){
            if(d[t]==1){
                cnt1++;
                qd=t;
            }
            else if(d[t]==-1){
                cnt_1++;
            }
            else {
                cout<<"***";
                return;
            }
        }
        sort(edg[t].begin(),edg[t].end());
    }

    for(int i=1;i<=cnt;i++)
    {
        if(find(1)!=find(i)){
            cout<<"***";return;
        }
    }

    

    //cout<<cnt1<<" "<<cnt_1<<endl;
    if(cnt_1||cnt1){
        if(cnt_1!=1||cnt1!=1){
            cout<<"***";
            return;
        }
    }

    dfs(qd);

    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i];
        if(i)cout<<".";
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