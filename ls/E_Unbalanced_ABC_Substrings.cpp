#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

const int N=1e6+10;
int s[N][3];
typedef pair<int,int>PII;
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        char c;
        cin >> c;
        for(int j = 0; j < 3; j ++ )s[i][j] = s[i - 1][j];
        s[i][c - 'A'] ++;
    }

    ll ans = 1ll * n * (n + 1)/ 2;
    ll res = 0;
    for(int a = 0; a < 3; a ++) {
        for(int b = a + 1; b < 3; b ++) {
            map<int,int> cnt;
            cnt[0] = 1;
            for(int i = 1; i <= n; i ++) {
                int t = s[i][a] - s[i][b];
                res += cnt[t];
                cnt[t] ++;
            }
        }
    }

    ll abc = 0;
    map<PII, int> cnt;
    cnt[{0, 0}] = 1;
    for(int i = 1; i <= n; i++) {
        int t1 = s[i][0] - s[i][1]; // A-B
        int t2 = s[i][1] - s[i][2]; // B-C
        abc += cnt[{t1, t2}];
        cnt[{t1, t2}] ++;
    }

    cout << ans - (res - 2 * abc) << endl;
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