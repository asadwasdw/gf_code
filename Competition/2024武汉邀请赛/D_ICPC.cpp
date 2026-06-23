#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

/*#####################################BEGIN#####################################*/

const int N = 5e3 + 5;
int a[N];
ll F[N][2 * N];
ll g[N][2 * N];
ll sum[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int s = 1; s <= n; s++)
    {
        for (int t = 1; t <= 2 * n; t++)
        {
            int l = max(1, s - t);
            int r = min(n, s + t);
            g[s][t] = max(sum[s] - sum[l - 1], sum[r] - sum[s - 1]);
           
         }
    }
    for (int t = 1; t <= 2 * n; t++)
        for (int s = 1; s <= n; s++)
            F[s][t] = max({F[s - 1][t - 1],F[s+1][t-1], g[s][t]});


    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll temp = 0;
        for (int j = 1; j <= 2 * n; j++)
        {
            temp ^= j * F[i][j];
        }
        ans ^= (i + temp);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
