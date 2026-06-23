#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];

void solve()
{
    int w; cin >> w;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    int i = 1, j = n;
    int ans = 0;
    while(i <= j) {
        // cout << i << " " << j << endl;
        if(a[j] + a[i] <= w) {
            j --;
            ans ++;
            i ++;
        }
        else ans ++, j --;

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