#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int n;cin >> n;
    vector<array<int, 2>> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        sum += a[i][0];
    }
    if (n == 1) {
        cout << "N\n";
        return;
    }
    vector<set<int>> dp(sum + 1);
    dp[0].insert(0);
    for (int i = 0; i < n; i++)
        for (int j = sum; j >= a[i][0]; j--){
            set<int> nx;
            for (auto x : dp[j - a[i][0]])
                nx.insert(__gcd(x, a[i][1]));
            swap(dp[j], nx);
        }
            
    
    for (int i = 0; i * 2 <= sum; i++) {
        for (auto x : dp[i]) {
            if (x && (sum - 2 * i) % x == 0) {
                cout << "Y\n";
                return;
            }
        }
        if (i * 2 == sum && dp[i].size()) {
            cout << "Y\n";
            return;
        }
    }
    cout << "N\n";
    
    




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