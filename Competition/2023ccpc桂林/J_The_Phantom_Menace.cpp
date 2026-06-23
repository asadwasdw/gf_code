#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>g(N);
int d[N];
#define endl "\n"

typedef unsigned long long ull;
string s[N];
const ull P = 13331;
ull p[N];
vector<ull>h[N];

vector<int>ans;

void init(){
    p[0] = 1;
    for(int i=1;i<N;i++)p[i]=p[i-1]*P;
}

ull get(int n,int l,int r) {
    if(l>r)return 0;
    return h[n][r]-h[n][l-1]*p[r-l+1];
}

unordered_map<ull,int>ID;
int cnt;
int id(ull x)
{
    if(ID[x] == 0) ID[x] = ++cnt;
    return ID[x];
}
bool st[N];

void dfs(int u) {
    //cout<<u<<" ";
    for(int i=(int)g[u].size()-1;i>=0;i=(int)g[u].size()-1){
         PII p=g[u][i];
         g[u].pop_back();
        int v = p.first;
        if(st[p.second])continue;
        dfs(v);
        st[p.second] = true;
        ans.push_back(p.second);
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=2*n;i++){

        cin>>s[i];
        s[i]=" "+s[i];
        h[i].clear();h[i].resize(m+10);
        for(int j=1;j<=m;j++){
            h[i][j]=h[i][j-1]*P+s[i][j]-'a';
        }
    }
    ull P2 = P<<15;

    for(int i=0;i<m;i++) {
        ID.clear();
        cnt = 0;
        for(int j=1;j<=n;j++) {
            ull a = get(j,1,i);
            ull b = get(j,i+1,m)+P2;
            id(a),id(b);
            // cout<<s[j].substr(1,i)<<" "<<id(a)<<endl;
            // cout<<s[j].substr(i+1)<<" "<<id(b)<<endl;
        }

        for(int j=1+n;j<=2*n;j++) {
            ull a = get(j,1,m-i)+P2;
            ull b = get(j,m-i+1,m);
            id(a),id(b);

            // cout<<s[j].substr(1,m-i)<<" "<<id(a)<<endl;
            // cout<<s[j].substr(m-i+1)<<" "<<id(b)<<endl;
        }

        int start = 0;
        for(int j=0;j<=2*cnt;j++) {
            d[j]=0;
            g[j].clear();
        }

        for(int j=1;j<=n;j++){
            int p = id(get(j,1,i));
            int q = id(get(j,i+1,m) + P2);
            
            d[p]++;
            d[q]--;
            g[p].push_back({q,j});
            start=p;
        }
        
        for(int j=1+n;j<=2*n;j++){
            int p = id(get(j,1,m-i)+P2);
            int q = id(get(j,m-i+1,m));
            d[p]++;
            d[q]--;
            g[p].push_back({q,j});
        }

        bool flag = true;
        for(int j=1;j<=cnt;j++){
            if(d[j])flag = false;
        }
        if(!flag)continue;
        // cout<<i<<endl;

        for(int i=1;i<=2*n;i++)st[i] = false;

        ans.clear();

        dfs(start);
       // cout<<ans.size()<<endl;
       
          for(int j=1;j<=2*n && flag;j++)
            if(st[j]==false) flag=false;
        if(flag==false) continue;
 

        vector<int>ans1,ans2;
        reverse(ans.begin(),ans.end());
        for(auto t:ans){
            if(t>n)ans2.push_back(t-n);
            else ans1.push_back(t);
        }

        // for(auto t:ans)cout<<t<<" ";cout<<endl;

        for(auto t:ans1)cout<<t<<" ";cout<<endl;
        for(auto t:ans2)cout<<t<<" ";cout<<endl;
        return;
    }
    cout<<-1<<endl;

}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}