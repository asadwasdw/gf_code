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
int st[1<<25];
int js(int x) {
    int res = 0;
    while(x) {
        if(x&1)res ++ ;
        x >>= 1;
    }
    return res;
}
void solve()
{
    int n; cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n;j ++) {
            for(int z = j + 1; z < n; z ++ ) {
                if((a[i]^a[j]^a[z]) == 0) {
                    st[(1<<i) | (1<<j) | (1<<z)] = 1; // 三元组
                }
            }
        }
    }
    int ans = n;
    for(int i = 0; i < (1<<n); i ++) {
        if(st[i] == 0) {
            ans = min(ans, n - __builtin_popcount(i));
        }
        else {
            for(int j = 0; j < n; j++ ) {
                st[i | (1<<j)] = 1;
            }
        }
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