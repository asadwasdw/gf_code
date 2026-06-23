#include<bits/stdc++.h>

using namespace std;
const int N=80+1,M=1e4+1;

int f[N][M];
int a[81],b[81];

signed main()
{
    int n,x,y;
    cin>>n>>x>>y;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];   
    }

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;

    for(int i = 1; i <= n; i ++) {
        for(int j = i; j >= 1; j --) {
            for(int k = x; k >= a[i]; k --) {
                f[j][k] = min(f[j][k], f[j - 1][k - a[i]] + b[i]);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= x; j ++) {
            if(f[i][j] <= y) ans = max(ans, i);
        }
    }
    cout << min(n, ans + 1) << endl;
}