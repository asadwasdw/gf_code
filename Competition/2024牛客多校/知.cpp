#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N], s[N];


void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int t = 0;

    for(int i = n; i >= 1; i --) {
        int avg = INF;
        for(int j = 0; j < i; j ++) {
            avg = min(avg, (s[i] - s[j] + t + (i - j - 1)) / (i - j));
        }
       
        if(a[i] > avg) {
            t += a[i] - avg;
            a[i] = avg;
        }
        else {
            if(t >= avg - a[i]) {
                t -= avg - a[i];
                a[i] = avg;
            }
            else {
                a[i] += t;
            }
            // a[i] += min(t, avg - a[i]);
        }
    }
    int ans = 1;
    for(int i = 1; i <= n; i ++) {
        // cout << a[i] << " " << i << endl;
        ans *= a[i];
        ans %= mod;
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