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

int p[N], go[N][25]; //go[i][j] 从i开始， 发生了 1 << j 次合并， 现在开头的在哪个位置
int a[N];


void solve()
{
    int n;
    cin >> n;
    memset(p, 0x3f, sizeof p);
    memset(go, 0x3f, sizeof go);

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = n; i >= 1; i --) {
        go[i][0] = p[a[i]] + 1; // 一次合并
        p[a[i]] = i;
    }

    for(int j = 1; j <= 20; j ++) {
        for(int i = 1; i <= n; i ++) {
            if(go[i][j - 1] <= n) go[i][j] = go[go[i][j - 1]][j - 1]; // go[i][j - 1]次后， 还在范围内
        }
    }

    int q;
    cin >> q;
    while(q --) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int i = l; i <= r; ) {
            for(int j = 20; j >= 0; j --) {
                if(go[i][j] - 1 <= r) { // -1, 是可能r就是最后一张牌， 根本没有下一个位置
                    i = go[i][j];
                }
            }
            // cout << i << endl;
            if(i <= r) {
                ans ++;
                i ++;
            }
        }
        cout << ans << endl;
    }







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
    return 0;
}