#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N];
int n;
void solve()
{
    
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    ll ans = 0;

    for(int l = 1; l <= n; l ++) {
        for(int r = l ; r <= n; r ++) {
            ll res = 0, sum = 0;
            for(int i = l; i <= r; i ++) {
                res ^= a[i], sum += a[i];
            }
            if(res == sum) ans ++;
        }
    }

    cout << ans << endl;
}

ll s1[N], s2[N];

void solve2() {
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s1[i] = s1[i - 1] + a[i], s2[i] = s2[i - 1] ^ a[i];
    }

    ll ans = 0;
    for(int l = 1; l <= n; l ++) {
        for(int r = l ; r <= min(l + 35, n); r ++) {
            ll res = s2[r] ^ s2[l - 1], sum = s1[r] - s1[l - 1];

            if(res == sum) ans ++;
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
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve2();
    }
    return 0;
}