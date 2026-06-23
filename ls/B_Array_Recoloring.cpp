#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define int long long
//vector<vector<int>>adj(N);

int a[N];
// int l[N][N];
// int r[N][N];
multiset<int> s;
void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    // memset(l, 0, sizeof l);
    // memset(r, 0, sizeof r);

    vector<vector<int>> l(n + 10,vector<int>(1, 0));
    vector<vector<int>> r(n + 10,vector<int>(1, 0));

    {
        int sum = 0;
        for(int i = 1; i <= n; i ++) {
            
            int j = 0;
            int sum = 0;
            for(auto it = s.rbegin(); it != s.rend(); it ++) {
                j ++;
                sum += *it;
                l[i].push_back(sum);
            }
            s.insert(a[i]);

            if(s.size() > k) {
                s.erase(s.begin());
            }
        }
        s.clear();
    }

    {
        int sum = 0;
        for(int i = n; i >= 1; i --) {
            int j = 0;
            int sum = 0;
            for(auto it = s.rbegin(); it != s.rend(); it ++) {
                j ++;
                sum += *it;
                r[i].push_back(sum);
            }
            s.insert(a[i]);

            if(s.size() > k) {
                s.erase(s.begin());
            }

        }
        s.clear();
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= k; j ++) {
    //         cout << l[i][j] << " \n"[j == k];
    //     }
    // }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= k; j ++) {
    //         cout << r[i][j] << " \n"[j == k];
    //     }
    // }

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= k; j ++) {
            if(i != 1 && i != n) {
                if(j == 0 || j == k) continue;
            }
            if(j < l[i].size() && k - j < r[i].size())
                ans = max(ans, a[i] + l[i][j] + r[i][k - j]);
        }
    }
    cout << ans << endl;







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}