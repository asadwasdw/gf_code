#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

typedef unsigned long long ull;

const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();//随机数

ull shift(ull x){
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

int n;
ull h[N];
set<ull>trees;

void getHash(int x,int fa){
    h[x]=1;
    for(auto v:edg[x]) {
        if(v == fa)continue;
        getHash(v,x);
        h[x] += shift(h[v]);
    }
    trees.insert(h[x]);
}



void solve()
{

    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    getHash(1,0);
    cout<<trees.size();

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