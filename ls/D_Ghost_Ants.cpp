#include<bits/stdc++.h>
#define int long long
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
PII T[N];

bool cmp(PII a, PII b) {
    return a.first < b.first;
}

void solve()
{
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        T[i] = {a[i], (int)(s[i] - '0')};
    }

    sort(T + 1, T + n + 1, cmp);

    int ans = 0;
    int r = 0;
    int res = 0;
    for(int i = 1; i <= n; i ++) {
        while(r + 1 <= n && (T[r + 1].first - T[i].first) <= 2 * m) {
            r ++;
            if(T[r].second == 0) res ++;
        }
        if(T[i].second == 1) ans += res;
        else res --;
        // cout << i << " " << r << endl;
    }
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