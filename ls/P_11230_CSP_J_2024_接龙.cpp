#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

vector<int> p[N];
int dp[110][N];

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    for(int i = 1; i <= n; i ++) {
        int l; cin >> l;
        for(int j = 1; j <= l; j ++) {
            int x; cin >> x;
            p[i].push_back(x);
        }
    }

    memset(dp, -1, sizeof dp);
    dp[0][1] = 0;

    for(int i = 1; i <= 100; i ++) { //枚举轮数
        for(int j = 1; j <= 2e5; j ++) { // 枚举起始牌
            
            for(int z = 1; z <= n; z ++) { 
                int len = 0;
                for(int K = 0; K < p[z].size(); K++){ // 枚举每一个人的手牌  sum(l) <= 2e5
                    int t = p[z][K];

                    if(len) { // 当前的牌可以作为结束牌
                        len --;
                        if(dp[i][t] == -1) dp[i][t] = z;
                        else if(1 <= dp[i][t] && dp[i][t] <= n && dp[i][t] != z) dp[i][t] = 0; 
                    }

                    if(t == j && dp[i - 1][t] != -1 && dp[i - 1][t] != z) {
                        len = k - 1;
                    }
                }
            }

        }
    }



    while(q --) {
        int r, c;
        cin >> r >> c;
        if(dp[r][c] == -1) cout << "0\n";
        else cout << "1\n";
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
}