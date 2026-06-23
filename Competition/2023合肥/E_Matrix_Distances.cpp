#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N][N];



void solve()
{
    unordered_map<int,vector<int>> h,l;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            h[a[i][j]].push_back(i);
            l[a[i][j]].push_back(j);
        }
    }
    int ans = 0;

    auto js = [&](unordered_map<int,vector<int>> &t) -> int {
        int ans = 0;

        for(auto &[u,v] : t) {
            sort(v.begin(),v.end());
            int sum = 0;
            for(int i = 0; i < v.size(); i ++) {
                ans += (i * v[i]) - sum;
                sum += v[i];
            }
        }

        return ans * 2;
    };

    ans += js(h); 
    ans += js(l);
    cout << ans; 







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