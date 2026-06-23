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
int n,m;
int a[N];
typedef unsigned long long ull;
const ull P = 131;
const ull P2 = 13331;

ull h[N],p[N],fh[N];
ull h2[N],p2[N],fh2[N];

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

ull fget(int l, int r) {
    if(l > r) return 0;
    return fh[l] - fh[r + 1] * p[r - l + 1];
}

ull get2(int l, int r) {
    return h2[r] - h2[l - 1] * p2[r - l + 1];
}

ull fget2(int l, int r) {
    if(l > r) return 0;
    return fh2[l] - fh2[r + 1] * p2[r - l + 1];
}


void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    s = " " + s;
  
    p[0] = 1;
    p2[0] = 1;
    for(int i = 1; i <= n; i ++) {
        h[i] = h[i - 1] * P + s[i] - '0' + 1;
        p[i] = p[i - 1] * P;
        // cout << i << " " << h[i] << endl;

        h2[i] = h2[i - 1] * P2 + s[i] - '0' + 1;
        p2[i] = p2[i - 1] * P2;
    }

    for(int i = n; i >= 1; i --) {
        fh[i] = fh[i + 1] * P + s[i] - '0' + 1;
        fh2[i] = fh2[i + 1] * P2 + s[i] - '0' + 1;
    }

    ull ans1 = 0, ans0 = 0;
    ull ans12 = 0, ans02 = 0;

    for(int i = 1; i <= n; i += k) {
        for(int j = 1; j <= k; j ++) {
            ans1 = ans1 * P + 2;
            ans0 = ans0 * P + 1;

            ans12 = ans12 * P2 + 2;
            ans02 = ans02 * P2 + 1;
        }
        swap(ans1,ans0);
        swap(ans12,ans02);
    }

    // cout << ans1 << " " << ans0 << endl;

    for(int i = 1; i <= n; i ++) {

        ull t = get(i,n) * p[i - 1] + fget(1,i - 1);
        ull t2 = get2(i,n) * p2[i - 1] + fget2(1,i - 1);

        // cout << get(i,n) << " " << fget(1, i - 1) << " " << t <<  endl;
        if((t == ans1 && t2 == ans12)  || (t == ans0 && t2 == ans02)) {
            int ans = i - 1;
            if(ans == 0) ans = n;
            cout << ans << endl;
            return;
        }
    }
    cout << "-1" << endl;


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