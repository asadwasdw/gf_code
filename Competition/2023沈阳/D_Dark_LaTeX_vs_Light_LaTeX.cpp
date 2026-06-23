#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
const int N=1e4+10;

// const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

// vector<vector<int>>adj(N);


struct SAM
{
    int len[N * 2], fail[N * 2], tr[N * 2][26];
    int f[N * 2], ed[N * 2];
    int idx, last;
    SAM(){
        memset(len, 0, sizeof len);
        memset(fail, 0, sizeof fail);
        memset(tr, 0, sizeof tr);
        memset(f, 0, sizeof f);
        memset(ed, 0, sizeof ed);
    }
    void sam_init(){
        idx = 0;
        len[0] = 0;
        fail[0] = -1;
        idx++;
        last = 0;
    }
    
    void sam_extend(int c, int id){
        int cur = idx ++;
        len[cur] = len[last] + 1;
        f[cur]++;
        int p = last;
        while(p != -1 && !tr[p][c]){
            tr[p][c] = cur;
            p = fail[p];
        }
        if(p == -1){
            fail[cur] = 0;
        }
        else{
            int q = tr[p][c];
            if(len[p] + 1 == len[q]){
                fail[cur] = q;
            }
            else{
                int clone = idx ++ ;
                len[clone] = len[p] + 1;
                for(int i=0; i<26; ++i)tr[clone][i] = tr[q][i];
                fail[clone] = fail[q];
                while(p != -1 && tr[p][c] == q){
                    tr[p][c] = clone;
                    p = fail[p];
                }
                fail[q] = fail[cur] = clone;
            }
        }
        last = cur;
        ed[id] = last;
    }
    vector<int> g[N * 2];
    
    int cnt, dfn[N * 2], dep[N];
    vector<int> pos;
    void dfs(int u){
        dfn[u] = ++cnt;
        pos.push_back(u);
        for(auto v : g[u])dep[v] = dep[u] + 1, dfs(v), f[u] += f[v], ++cnt, pos.push_back(u);
    }
    vector<vector<int>> mi;
    vector<int> lg;
    void build_st(){
        mi = vector(21, vector<int>(pos.size() + 10));
        lg = vector<int>(pos.size() + 10);
        lg[0] = -1;
        for(int i=1; i<=pos.size(); ++i)mi[0][i] = pos[i-1], lg[i] = lg[i/2] + 1;
        for(int j=1; j<21; ++j){
            for(int i=1; i + (1<<j) - 1<=pos.size(); ++i){
                if(dep[mi[j-1][i]] < dep[mi[j-1][i+(1<<j-1)]])mi[j][i] = mi[j-1][i];
                else mi[j][i] = mi[j-1][i+(1<<j-1)];
            }
        }
    }

    int query(int l, int r){
        int len = lg[r - l + 1];
        int res1 = mi[len][l];
        int res2 = mi[len][r - (1<<len) + 1];
        if(dep[res1] < dep[res2])return res1;
        return res2;
    }
    void build(string &s){
        sam_init();
        for(int i=0; i<s.size(); ++i)sam_extend(s[i] - 'a', i+1);
        for(int i=1; i<idx; ++i)g[fail[i]].push_back(i);
        dep[0] = 0;
        dfs(0);
        build_st();
    }
    

    void clear(){
        pos.clear();
        lg.clear();
        mi.clear();cnt = 0;
        for(int i=0; i<=idx; ++i){
            f[i] = len[i] = fail[i] = 0;
            for(int j=0; j<26; ++j)tr[i][j] = 0;
            g[i].clear();
        }
        idx = 0;
    }
}sam1, sam2;


string s,t;
ll ans = 0;
void check(string s, string t, bool flag){
    sam1.build(t);
    vector<vector<ll>> sum(s.size() + 10, vector<ll>(s.size() + 10, 0));
    
    for(int i=1, u=0, l=0; i<=s.size(); ++i){
        int x = s[i-1] - 'a';
        while(u && !sam1.tr[u][x]){
            u = sam1.fail[u];
            l = sam1.len[u];
        }
        if(sam1.tr[u][x]){
            u = sam1.tr[u][x];
            ++l;
        }
        else u = 0, l = 0;
        int v = u;
        if(l && u)
        while(v > 0){
            for(int j=sam1.len[sam1.fail[v]]+1; j<=min(l, sam1.len[v]); ++j)sum[i][i - j + 1] += sam1.f[v];
            v = sam1.fail[v];
        }
    }
    for(int i=1; i<=s.size(); ++i){
        for(int j=1; j<=i; ++j){
            sum[i][j] += sum[i][j-1];
            // cout << sum[i][j] << ' ';
        }
    }
    string temp = s;
    reverse(temp.begin(), temp.end());
    sam2.build(temp);
    auto query = [&](int i, int j){
        int u = sam2.ed[s.size() - i + 1], v = sam2.ed[s.size() - j + 1];
        if(sam2.dfn[u] > sam2.dfn[v])swap(u, v);
        return sam2.query(sam2.dfn[u], sam2.dfn[v]);
    };
    for(int i=1; i<=s.size(); ++i){
        for(int j=i+2; j<=s.size(); ++j){
            if(s[i-1] != s[j-1])continue;
            int l = 1, r = min(j - i - 1, (int)s.size() - j + 1);
            int len = sam2.len[query(i, j)];
            len = min(len, r);
            l = len;
            assert(i + l < j && l > 0);
            ans += sum[j-1][i + l] - sum[j-1][i];
            // cout << ans << ' ' << i << ' ' << j << ' ' << l << endl;
        }
    }
    if(flag){
        for(int i=1; i<=s.size(); ++i){
            ans += sum[i][i];
        }
    }
}


void solve()
{
    cin >> s >> t;
    // s = string(5000, 'a');
    // t = s;
    
    check(s, t, true);
    sam1.clear();
    sam2.clear();
    check(t, s, false);
    cout << ans << endl;
    






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