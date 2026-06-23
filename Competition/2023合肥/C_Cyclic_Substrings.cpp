#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=6e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int sz, tot, last;
int cnt[N], ch[N][11], len[N], fail[N];
int s[N];
int node(int l){
    sz++;
    memset(ch[sz], 0, sizeof ch[sz]);
    len[sz] = l;
    fail[sz] = cnt[sz] = 0;
    return sz;
}
void clear(){
    sz = -1;
    last = 0;
    s[tot = 0] = 0;
    node(0);
    node(-1);
    fail[0] = 1;
}

int getfail(int x){
    while(s[tot - len[x] - 1] != s[tot])x = fail[x];
    return x;
}
void insert(int c, int i){
    s[++tot] = c;
    int now = getfail(last);
    if(!ch[now][c]){
        int x = node(len[now] + 2);
        fail[x] = ch[getfail(fail[now])][c];
        ch[now][c] = x;
    }
    last = ch[now][c];
    // cnt[last]++;
}
// vector<int> g[N];
ll res = 0;
// void dfs(int u){
//     for(auto v : g[u]){
//         dfs(v);
//         cnt[u] += cnt[v];
//     }
    
    
// }
void solve()
{
    clear();
    cin >> n;
    string s;
    cin >> s;
    s = s + s;
    s.erase(s.begin());
    for(int i=0; i<s.size(); ++i){
        insert(s[i] - '0' + 1, i);
        if(i >= n-1)cnt[last]++;
    }
    for(int i=sz; i>=0; --i){
        if(i != 1)
        cnt[fail[i]] += cnt[i];
    }
    for(int i=sz; i>=0; --i){
        // cnt[i] += cnt[i+1];
        if(len[i] > 0 && len[i] <= n && cnt[i] > 0){
            // cout << cnt[u] << ' ' << len[u] << endl;
        res += 1ll * cnt[i] * cnt[i] % mod * len[i] % mod;
        res %= mod;
        }
    }
    // for(int i=0; i<=sz; ++i){
    //     if(i != 1)g[fail[i]].push_back(i);
    // }
    // dfs(1);
    cout << res;




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}