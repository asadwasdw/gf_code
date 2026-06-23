#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int n;
PII a[N];
int cur[N];
vector<PII> res;


void dfs(int l, int r){
    if(l > r)return;
    if(l == r){
        for(int i=cur[l]+1; i<=a[l].first; ++i)res.push_back({2, a[l].second});
        cur[l] = a[l].first;
        return;
    }
    int mid = l + r >> 1;
    
    for(int i=mid+1; i<=r; ++i){
        if(cur[i] < a[i].first){
            cur[i]++;
            res.push_back({2, a[i].second});
        }
    }
    int t = 0;
    while(cur[mid+1] + t < a[mid+1].first){
        res.push_back({1, cur[mid+1] + t});
        ++t;
    }
    for(int i=mid+1; i<=r; ++i)cur[i] += t;

    dfs(mid+1, r);
    dfs(l, mid);
}


void solve()
{
    cin >> n;
    for(int i=1; i<=n; ++i)cin >> a[i].first, a[i].second = i;
    sort(a+1, a+1+n);
    dfs(1, n);
    cout << res.size() << endl;
    // vector<int> p(n+1);
    for(auto [l, r] : res){
        cout << l << ' ' << r << endl;
        // if(l == 2)p[r]++;
        // else{
        //     for(int i=1; i<=n; ++i)if(p[i] == r)++p[i];
        // }
    }
    // for(int i=1; i<=n; ++i)cout << p[i] << " \n"[i == n];
    
    






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