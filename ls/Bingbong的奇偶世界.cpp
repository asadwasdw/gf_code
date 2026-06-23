#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9 + 7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];


void solve()
{
    int n;cin >> n;
    int num = 0;
    int ans = 0;
    string s;
    cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; i ++) {
        int t = s[i] - '0';
        if(t == 0 && num == 0) {
            ans++;
        }
        else {
            if(t % 2 == 0) ans += num + 1;
            num += num;
            if(t != 0)num++;
            // else ans++;
        }
        ans %= mod;
        num %= mod;
        // cout << num << " " << ans << endl;
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
}