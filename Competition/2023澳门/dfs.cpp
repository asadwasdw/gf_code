#include<iostream>
#define int long long 
using namespace std;

const int N = 15;
int n, m;
int ans = 0;
int w[N][4];
int id[N][4];
int a[N];
int num[N];

void dfs(int now, int W) {
    if(now == n + 1) {
        ans = max(ans, W);
        return;
    }

    for(int i = 1; i <= 3; i ++) {
        int t = w[now][i];
        num[id[now][i]] ++;
        if(num[id[now][i]] == 3) t += a[id[now][i]];
        dfs(now + 1, W + t);
        num[id[now][i]] --;
    }
}

signed main()
{

    cin >> n >> m;
    for(int i = 1; i <= m; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= 3; j ++) cin >> w[i][j];
        for(int j = 1; j <= 3; j ++) cin >>id[i][j];
    }
    dfs(1, 0);
    cout << ans << endl;
}

