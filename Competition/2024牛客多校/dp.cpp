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

int a[N];
int b[N];
void solve()
{

    int n = 4;
    cin >> n;
    n *= 2;
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    for(int i = 1; i <= n/2; i ++) a[i] = i;
    int res = 0;
    // a[1] = 4, a[2] = 3, a[3] = 2, a[4] = 1;

    do{
        vector<int> st(n + 10, 0);
        int ans = 0;
        for(int i = 1; i <= n/2; i ++) {
            int l, r;
            l = 0, r = 0;
            int cnt = 0;
            for(int j = 1; j <= n; j ++) {
                if(b[j] == a[i] && st[j] == 0) {
                    if(l == 0) l = j;
                    else r = j;
                }
            }

            for(int j = l; j <= r; j ++) {
                if(st[j] == 0) cnt ++;
                st[j] = 1;
            }
            // cout << l << " " << r << " " << cnt << endl;
            if(r)ans += cnt * a[i];
        }

        if(ans == 32) {
            for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n]
        }

        // cout << ans << endl;
        res = max(ans, res) ;

    }while(next_permutation(a + 1, a + n/2 + 1));

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