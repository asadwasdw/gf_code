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

struct bird{
    int a, d, b;
}birds[N];


void solve()
{
    int n, m;
    cin >> n >> m;

    map<int,int> cnt;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> birds[i].a >> birds[i].d >> birds[i].b;
        cnt[birds[i].a] ++;
        if(cnt[birds[i].a] == 1) ans ++;
    }
    
    sort(birds + 1, birds + n + 1, [&](bird x, bird y) {
        return x.d < y.d;
    });

    for(int j = 1, i = 1; j <= m; j ++) {
        while(i <= n && birds[i].d == j) {
            cnt[birds[i].a] --;
            if(cnt[birds[i].a] == 0) ans --;

            cnt[birds[i].b] ++;
            if(cnt[birds[i].b] == 1) ans ++;

            i ++;
        }

        // for(int i = 1; i <= m; i ++) cout << cnt[i] << " \n"[i == m];

        cout << ans << endl;
    }









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