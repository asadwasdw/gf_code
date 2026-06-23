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

int n, a[N];
ll cnt[N];

void solve()
{
    cin >> n;
    int mx = 0;
    for(int i=1; i<=n; ++i)cin >> a[i], cnt[a[i]]++, mx = max(mx, a[i]);
    ll res = 0;

    auto bf = [&](){
        int res = 0;
        for(int i=1; i<=n; ++i)for(int j=i+1; j<=n; ++j)for(int k=j+1; k<=n; ++k){
            if(a[i] * __gcd(a[j], a[k]) == a[j] * __gcd(a[i], a[k]) && a[i] * __gcd(a[j], a[k]) == a[k] * __gcd(a[i], a[j]))
            {
                ++res;
                // if (a[i] * a[j] / __gcd(a[i], a[j]) != a[k]) {
                    // cout << a[i] << ' ' << a[j] << ' ' << a[k] << ' ' << __gcd(a[i], a[j]) << ' ';
                    // cout << a[i] * a[j] / __gcd(a[i], a[j]) << ' ' << a[i] * a[j] / __gcd(a[i], a[j]) / a[k] << '\n';
                    // cout << a[i] * a[j] / __gcd(a[i], a[j]) << ' ' << a[k] << '\n';

                // }
                // cout << a[i] << " " << a[j] << " " << a[k] << endl;
            }
            
        }
        return res;
    };
    auto get = [&](int i, int j, int k) -> int{
        if (k < i || i * __gcd(j, k) != k * __gcd(i, j) || j * __gcd(i, k) != k * __gcd(i, j)) return 0;
        if (k == i) {
            return cnt[i] * (cnt[i] - 1) / 2 * cnt[j];
        }
        return cnt[i] * cnt[j] * cnt[k];
    };
    // cout << res << endl;
    
    for(int i=1; i<=mx; ++i){
        for(int j=1; j<=i; ++j){
            if (j == i) {
                if (cnt[i] >= 3)
                    res += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
                continue;
            }
            int LCM = i * j / __gcd(i,j);
            int GCD = __gcd(i, j);
            for (int k = 1; k * k <= GCD; k++) 
            {   
                if (GCD % k == 0) {
                    res += get(i, j, LCM / k);
                    if (k * k != GCD) res += get(i, j, LCM / (GCD / k));
                }
                
            }
            
            // cout << i << ' ' << j << ' ' << res << '\n';
        }
    }
    // cout << bf() << endl;
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