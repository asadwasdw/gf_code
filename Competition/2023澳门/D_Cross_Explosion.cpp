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
int lowbit(int x) { return x & (-x); }

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 10, vector<int>(m + 10, 0));
    vector<vector<int>> t1(n + 10, vector<int>(m + 10, 0));
    vector<vector<int>> t2(n + 10, vector<int>(m + 10, 0));
    vector<vector<int>> t3(n + 10, vector<int>(m + 10, 0));
    vector<vector<int>> t4(n + 10, vector<int>(m + 10, 0));

    auto add = [&](ll x, ll y, ll z) {
        for (int X = x; X <= n; X += lowbit(X))
            for (int Y = y; Y <= m; Y += lowbit(Y)) {
            t1[X][Y] += z;
            t2[X][Y] += z * x;  // 注意是 z * x 而不是 z * X，后面同理
            t3[X][Y] += z * y;
            t4[X][Y] += z * x * y;
        }
    };

    auto range_add = [&](ll xa, ll ya, ll xb, ll yb, ll z) {  //(xa, ya) 到 (xb, yb) 子矩阵
        add(xa, ya, z);
        add(xa, yb + 1, -z);
        add(xb + 1, ya, -z);
        add(xb + 1, yb + 1, z);
    };

    auto ask =[&](ll x, ll y) -> int{
        ll res = 0;
        for (int i = x; i; i -= lowbit(i))
            for (int j = y; j; j -= lowbit(j))
            res += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] -
                    (x + 1) * t3[i][j] + t4[i][j];
        return res;
    };

    auto range_ask = [&](ll xa, ll ya, ll xb, ll yb) -> int{
        return ask(xb, yb) - ask(xb, ya - 1) - ask(xa - 1, yb) + ask(xa - 1, ya - 1);
    };

   for(int i = 1; i <= k; i ++) {
        int x, y;
        cin >> x >> y;
        if(range_ask(x, y, x, y) == 0) {
            range_add(x, y, x, y, 1);
        }
        else {
            {
                int l = y + 1, r = m;
                while(l < r) {
                    int mid = (l + r)>> 1;
                    if(range_ask(x, y, x, mid) == mid - y + 1) l = mid + 1;
                    else r = mid;
                } 
                
                if(range_ask(x,l,x,l) == 0)range_add(x, l, x, l, 1);
   
            }

            {
                int l = x + 1, r = n;
                while(l < r) {
                    int mid = (l + r)>> 1;
                    if(range_ask(x, y, mid, y) == mid - x + 1) l = mid + 1;
                    else r = mid;
                }  
                if(range_ask(l,y,l,y) == 0)range_add(l, y, l, y, 1);
                
            }

            {
                int l = 1, r = y - 1;
                while(l < r) {
                    int mid = (l + r + 1)>> 1;
                    if(range_ask(x, mid, x, y) == y - mid + 1) r = mid - 1;
                    else l = mid;
                }  
                if(range_ask(x,l,x,l) == 0)range_add(x, l, x, l, 1);
            }

            {
                int l = 1, r = x - 1;
                while(l < r) {
                    int mid = (l + r + 1)>> 1;
                    if(range_ask(mid, y, x, y) == x - mid + 1) r = mid - 1;
                    else l = mid;
                }  
                if(range_ask(l,y,l,y) == 0)range_add(l, y, l, y, 1);
            }
        }

        // cout << i << " " << x << " " << y << endl;

        // for(int i = 1; i <= n; i ++ ) {
        //     for(int j = 1; j <= m; j ++) {
        //         cout << range_ask(i, j, i, j) << " \n"[j == m];
        //     }
        // } cout << endl;


    }

    int ans = n * m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(range_ask(i, j, i, j)) ans --;
        }
    }
    cout << ans << endl;
    // cout << n * m - range_ask(1, 1, n, m) << endl;



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