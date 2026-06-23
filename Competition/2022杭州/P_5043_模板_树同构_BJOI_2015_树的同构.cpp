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

typedef pair<ull,ull>Hash2;
map<Hash2,int>trees;

int n;
ull h[N];
int size[N],weight[N],centroid[2];

void getCentroid(int x, int fa) {
    size[x] = 1;
    weight[x] = 0;
    for (int i : edg[x]) {
        if (i == fa) {
        continue;
        }
        getCentroid(i, x);
        size[x] += size[i];
        weight[x] = std::max(weight[x], size[i]);
    }
    weight[x] = std::max(weight[x], n - size[x]);
    if (weight[x] <= n / 2) {
        int index = centroid[0] != 0;
        centroid[index] = x;
    }
}


ull getHash(int u,int fa) {
    h[u]=1;
    for(auto v : edg[u]) {
        if(v == fa) continue;
        getHash(v,u);
        h[u] += shift(h[v]);
    }
    return h[u];
}


void solve()
{

    int num; cin>>num;

    for(int i=1;i<=num;i++) {
        cin>>n;
        for(int j=1;j<=n;j++){
            int fa;cin>>fa;
            if(fa==0)continue;
            edg[fa].push_back(j);
            edg[j].push_back(fa);
        }

        getCentroid(1,-1);

        Hash2 hash;
        hash.first = getHash(centroid[0],0);
        if(centroid[1]==0){
            hash.second = hash.first;
        }
        else {
            hash.second = getHash(centroid[1],0);
        }
        if(hash.first>hash.second){
            swap(hash.first,hash.second);
        }

        if(trees[hash] == 0){
            trees[hash] = i;
        }

        cout<<trees[hash]<<endl;
        
        centroid[0]=centroid[1]=0;
        for(int i=1;i<=n;i++)edg[i].clear();
        
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