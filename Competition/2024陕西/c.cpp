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

int n, a[N], d[N], f[N];
vector<int> g[N];
void solve()
{
    cin >> n;
    for(int i=1; i<=n; ++i)cin >> a[i];
    for(int i=1; i<=n; ++i){
        d[a[i]]++;
    }
    queue<int> q;
    for(int i=1; i<=n; ++i){
        if(!d[i])q.push(i), f[i] = 1;
    }
    
    while(q.size()){
        int t = q.front();q.pop();
        if(--d[a[t]] == 0){
            f[a[t]] = f[t] + 1;
            if(a[t] <= n)q.push(a[t]);
            else g[a[t]].push_back(f[t]);
        }
    }
    vector<int> st(n + 1);
    int res = 0;
    for(int i=n+1; i<=n+n; ++i){
        sort(g[i].begin(), g[i].end());
        if(g[i].size())res += g[i].back();
    }
    // cout << res << endl;
    for(int i=1; i<=n; ++i){
        if(!d[i] || st[i])continue;
        int k = i, cnt = 1;
        st[k] = 1;
        while(d[k] && a[k] != k && !st[a[k]]){
            st[a[k]]++;
            ++cnt;
            k = a[k];
        }
        res += cnt;
    }
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