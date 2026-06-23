#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n;
PII a[N];
int fa[N];
int find(int k){
    return k == fa[k] ? k : fa[k] = find(fa[k]);
}
void merge(int a, int b){
    int f1 = find(a), f2 = find(b);
    if(f1 != f2)fa[f2] = f1;
}
void solve()
{
    cin >> n;
    for(int i=1; i<=n; ++i)fa[i] = i;
    vector<array<int, 3>> d(n);
    for(int i=1; i<=n; ++i){
        cin >> a[i].first >> a[i].second;
        d[i-1] = {a[i].first - i, i - a[i].second, i};
    }
    sort(d.begin(), d.end());
    set<PII> p;
    for(int i=0; i<n; ++i)p.insert({d[i][1], d[i][2]});
    vector<int> st(n+1);
    for(int i=0; i<n; ++i){
        int x = d[i][0], y = d[i][1], id = d[i][2];
        if(st[id] == 1)continue;
        st[id] = 1;
        p.erase({y, id});
        auto it = p.lower_bound({y, 0});
        auto temp = it;
        while(it != p.end()){
            st[it->second] = 1;
            fa[it->second] = id;
            ++it;
        }
        p.erase(temp, p.end());
    }
    for(int i=1; i<=n; ++i)find(i);
    for(int i=1; i<=n; ++i){
        d[i-1] = {-(a[i].first - i), -(i - a[i].second), i};
    }
    sort(d.begin(), d.end());
    p.clear();
    for(int i=0; i<n; ++i)p.insert({d[i][1], d[i][2]});
    for(int i=0; i<n; ++i){
        int x = d[i][0], y = d[i][1], id = d[i][2];
        if(st[id] == 2)continue;
        st[id] = 2;
        int f1 = find(id);
        p.erase({y, id});
        auto it = p.lower_bound({y, 0});
        auto temp = it;
        while(it != p.end()){
            st[it->second] = 2;
            fa[find(it->second)] = f1;
            ++it;
        }
        p.erase(temp, p.end());
    }
    for(int i=1; i<=n; ++i)st[find(i)] = 3;
    int res = 0;
    for(int i=1; i<=n; ++i)if(st[i] == 3)++res;
    cout << res << endl;






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