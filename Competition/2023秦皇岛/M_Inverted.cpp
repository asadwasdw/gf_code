#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;


const int N = 1e6+10, M = 30010, mod = 998244353;

vector<vector<int>> e(N);

LL dp[N][2], p[N], st[N];

int find(int a)
{
    if(a != p[a]) p[a] = find(p[a]);
    return p[a];
}

void dfs(int u ,int fa = 0)
{
    if(st[u] == false) return;
    dp[u][1] = 0;
    dp[u][0] = 1;
    for(auto v : e[u])
    {
        if(v == fa) continue;
        dfs(v, u);
        dp[u][1] = ((dp[u][1] * dp[v][0]) % mod + (dp[u][0] * dp[v][1]) % mod + (2 * (dp[u][1] * dp[v][1]) % mod) % mod) % mod;
        dp[u][0] = ((dp[u][0] * dp[v][0]) % mod + (2 * (dp[u][0] * dp[v][1]) % mod) % mod) % mod;
    }
    return;
}

void solve()
{
    // cout<<setiosflags(ios::fixed)<<setprecision(10);
    int n;
    cin>>n;
    for(int i = 1;i < n;i ++)
    {
        int u, v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i = 1; i <= n ;i++) dp[i][1] = 1, dp[i][0] = 0, p[i] = i;
    for(int i = 1; i < n ;i++)
    {
        int x;
        cin>>x;
        st[x] = 1;
        for(auto y : e[x])
        {
            if(st[y])
            {
                p[find(y)] = x;
            }
        }
        dfs(x);
        LL ans = 1;
        for(int i = 1; i <= n ;i++) 
        {
            if(p[i] == i) {
                cout << i << " ";
                ans = (ans * dp[i][1]) % mod;
            } 
          
        }
          cout << "----" << x << "\n";
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}