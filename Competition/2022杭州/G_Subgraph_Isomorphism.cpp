#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int d[N];
bool st[N];
int n,m;
vector<int>cur;
int ht=0;
typedef unsigned long long ull;
void tppx() {
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(d[i] == 1) {
            q.push(i);
            st[i]=true;
        }
    }

    while(q.size()){
        int u = q.front();q.pop();
        for(auto v:edg[u]) {
            if(st[v])continue;
            d[v]--;
            if(d[v] == 1) {
                q.push(v);
                st[v] = true;
            }
        }
    }
}

void dfs(int u) {
    cur.push_back(u);
    st[u] = true;
    for(auto v:edg[u]) {
        if(st[v])continue;
        if(d[v]!=2)continue;
        dfs(v);
    }
}


const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();//随机数

ull shift(ull x){
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 8;
    x ^= x << 17;
    x ^= mask;
    return x;
}


ull getHash(int u,int fa) {
    ull res = 1;
    for(auto v:edg[u]) {
        if(d[v]==2)continue;
        if(v==fa)continue;
        res += shift(getHash(v,u));
    }    
    return res;
}


void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        edg[i].clear();
        st[i]=false;
        d[i]=0;
    }
    cur.clear();
    ht=0;

    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
        d[a]++;
        d[b]++;
    }

    if(m == n - 1) {
        cout<<"YES\n";
        return;
    }
    else if(m>n) {
        cout<<"NO\n";
        return;
    }
    tppx();
    // for(int i=1;i<=n;i++)cout<<d[i]<<" ";cout<<endl;

    for(int i=1;i<=n;i++){
        if(d[i]==2){
            ht = i;
            break;
        }
    }

    dfs(ht);

    // for(auto t:cur)cout<<t<<" ";cout<<endl;

    vector<int>hx(n+10);
    int cnt = cur.size();

    for(int i=0;i<cnt;i++){
        hx[i]=getHash(cur[i],-1);
    }
    bool ky = true;

    for(int i=0;i<cnt;i++){
        if(hx[i] != hx[(i-2+cnt)%cnt])ky = false;
    }

    if(ky)cout<<"YES\n";
    else cout<<"NO\n";



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}