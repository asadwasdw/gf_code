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

int a[N], s[N];

void solve()
{
    int n, b;
    cin >> n >> b;

    int mid = 0;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[i] < b) a[i] = -1;
        else if(a[i] > b) a[i] = 1;
        else mid = i, a[i] = 0;

        s[i] = s[i - 1] + a[i];
        // cout << a[i] << " \n"[i == n];
    }
    ll ans = 0;

    // for(int l = 1; l <= mid; l ++) {
    //     for(int r = mid; r <= n; r ++) {
    //         // cout << l << " " << r << " " << s[r] - s[l - 1] << endl;
    //         if(s[r] - s[l - 1] == 0 && (r - l + 1) % 2 == 1 ) {
    //             // cout << l << " " << r << endl;
    //             ans ++;
    //         }
    //     }
    // }

    // map<int,int> odd;
    // map<int,int> even;
    
    // for(int l = 1; l <= mid; l ++) {
    //     if((l - 1) % 2 == 0) even[s[(l - 1)]] ++;
    //     else odd[s[(l - 1)]]++;
    // }

    // for(int r = mid; r <= n; r ++) {
    //     if(r % 2 == 0) {
    //         ans += odd[s[r]];
    //     } else {
    //         ans += even[s[r]];
    //     }
    // }

    map<int,int> cnt;
    // cnt[0] = 1;
    for(int i = 1; i <= mid; i ++) {
        cnt[s[i - 1]] ++;
    }

    for(int i = mid; i <= n; i ++) {
        ans += cnt[s[i]];
    }

    cout << ans  << endl;
}

int sl[N], sr[N];

void solve2() {
    int n, b;
    cin >> n >> b;

    int mid = 0;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[i] < b) a[i] = -1;
        else if(a[i] > b) a[i] = 1;
        else mid = i, a[i] = 0;
    }
    map<int,int> cnt;
    for(int i = mid; i >= 1; i --) {
        sl[i] = sl[i + 1] + a[i];
        cnt[sl[i]] ++;
    }
    ll ans = 0;
    for(int i = mid; i <= n; i ++) {
        sr[i] = sr[i - 1] + a[i];
        ans += cnt[- sr[i]];
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
        solve();
    }
    return 0;
}