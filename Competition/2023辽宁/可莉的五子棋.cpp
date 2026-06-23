#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int n, m;
int a[N][N];
int check1(int x, int y) {
    int res = 0;
    for(int i = 0, j = 0; i < 5; i ++) {
        if(x + i > n || y + j > m) return -1;
        if(a[i + x][j + y] == 0) return 0;
        res += a[i + x][j + y];
    }
    return res;
}

int check2(int x, int y) {
    int res = 0;
    for(int i = 0, j = 0; j < 5; j ++) {
        if(x + i > n || y + j > m) return -1;
        if(a[i + x][j + y] == 0) return 0;
        res += a[i + x][j + y];
    }
    return res;
}
int check3(int x, int y) {
    int res = 0;
    for(int i = 0, j = 0; j < 5; i ++, j ++) {
        if(x + i > n || y + j > m) return -1;
        if(a[i + x][j + y] == 0) return 0;
        res += a[i + x][j + y];
    }
    return res;
}

int check4(int x, int y) {
    int res = 0;
    for(int i = 0, j = 0; i < 5; i ++, j --) {
        if(x + i > n || y + j <= 0)return -1;
        
        if(a[i + x][j + y] == 0) return 0;
        res += a[i + x][j + y];
    }
    return res;
}



void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }
    }
    ll ans1 = 0, ans2 = 0;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int t = 0;
            t = check1(i, j);
            if(t == 5) ans1++;
            if(t == 10) ans2++;

            t = check2(i, j);
            if(t == 5) ans1++;
            if(t == 10) ans2++;

            t = check3(i, j);
            if(t == 5) ans1++;
            if(t == 10) ans2++;

            t = check4(i, j);
            if(t == 5) ans1++;
            if(t == 10) ans2++;
        }
    }
    cout << ans1 << " " << ans2 << endl;

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