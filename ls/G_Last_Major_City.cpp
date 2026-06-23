#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int h[N], e[N], ne[N], w[N], idx;
int n, m, k;
int dp[4010][1050];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}



void solve()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i ++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--, v--;
        // cout << u << " " << v << " " << w << endl;
        add(u, v, w);
        add(v, u, w);
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 1; j < (1 << k);  j ++) {
            dp[i][j] = INFll;
        }
    }


    for(int i = 0; i < k - 1; i ++) {
        dp[i][1<<i] = 0;
    }



    auto dj = [&](int st) {
        priority_queue<PII, vector<PII>, greater<PII>>q;
        vector t(n, 0);
        for(int i = 0; i < n; i ++) {
            q.push({dp[i][st], i});
        }

        // cout << st << endl;

        while(q.size()) {
            auto [dis, u] = q.top(); q.pop();
            if(t[u]) continue;
            t[u] = 1;

            // cout << u << " " << dis << endl;

            for(int i = h[u]; ~i; i = ne[i]) {
                int v = e[i];
                if(dp[v][st] > dis + w[i]) {
                    dp[v][st] = dis + w[i];
                    q.push({dp[v][st], v});
                }
            }
        }
    };



    for(int st = 1; st < (1 << (k - 1)); st ++) {
        for(int t = st; t; t = (t - 1) & st) {
            for(int i = 0; i < n; i ++) {
                dp[i][st] = min(dp[i][st], dp[i][t] + dp[i][st ^ t]);
            }
        }

        dj(st);
    }


    for(int i = k - 1; i < n; i ++) {
        cout <<  dp[i][(1 << (k - 1)) - 1] << endl;
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
}