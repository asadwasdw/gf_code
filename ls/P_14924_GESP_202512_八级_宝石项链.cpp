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
int l[N][20];
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    map<int,int> mp;
    int cnt = 0;
    for(int i = 1, j = 0; i <= 2 * n; i ++) {
        while(j <= 2 * n && cnt < m) {
            j ++;
            mp[a[j]] ++;
            if(mp[a[j]] == 1) cnt ++;
        }

        l[i][0] = j + 1;
        mp[a[i]] --;
        if(mp[a[i]] == 0) cnt --;
        cout << i << " " << l[i][0] << endl;
    }

    for(int j = 1; j < 20; j ++) {
        for(int i = 1; i <= 2 * n; i ++) {
            l[i][j] = l[l[i][j - 1]][j - 1];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int x = i;
        int res = 0;
        for(int j = 19; j >= 0; j --) {
            if(i <= l[x][j] && l[x][j] <= i + n) {
                x = l[x][j];
                res += 1 << j;
                // cout << x << " " << res << endl;
            }
        }
        // cout << i << " " << x << " " << res << endl;
        ans = max(ans, res);
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