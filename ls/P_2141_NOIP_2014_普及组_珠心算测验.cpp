#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[N];
int t[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        t[a[i]] = 1; // 标记 a[i] 是否存在
    }

    // a + b == c;
    int ans = 0;

    // for(int i = 1; i <= n; i ++) { // 枚举a[i] 作为c
    //     bool flag = false;
    //     for(int j = 1; j <= n; j ++) { // a
    //         for(int k = 1; k <= n; k ++) { // b
    //             if(a[j] + a[k] == a[i] && j != k) {
    //                 flag = true;
    //             }
    //         }
    //     }
    //     if(flag) ans ++;
    // }

    for(int i = 1; i <= n; i ++) { // a[i] a
        for(int j = i + 1; j <= n; j ++) { // a[j] b
            int c = a[i] + a[j];
            if(t[c] == 1 ) {
                ans ++;
                t[c] = 0;
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