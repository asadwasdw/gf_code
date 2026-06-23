#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e3+1;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int s[N][N];
short h[N][N],l[N][N],fd[N][N];

bool check(int x, int y, int len) {

    int num = 3 * (len - 1) + 1;
    // cout << len << " " << l[x][y] << " " << h[x][y] << " " << fd[x][y] << endl;
    if(len > l[x][y] || len > h[x][y] || len > fd[x][y]) return false;
    len --;
    int sum = s[x][y + len] - s[x][y - 1] - s[x - len - 1][y + len] + s[x - len - 1][y - 1];
    // cout << sum << " " << num << endl;
    if(num != sum) return false;
    return true;
}

int js(int x, int y) {
    int len = 0;
    int d = 1;
    while(d) {
        if(check(x,y,len + d)) {
            len += d;
            d *= 2;
        }
        else {
            d /= 2;
        }
    }
    return len;
}


void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            char t; cin >> t; s[i][j] = t - '0';
            // cin >> a[i][j];
            s[i][j] = s[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if(s[i][j] - s[i-1][j]-s[i][j-1]+s[i-1][j-1]) {
                l[i][j] = l[i - 1][j] + 1;
                fd[i][j] = fd[i - 1][j + 1] + 1;
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = m; j ; j --) {
            if(s[i][j] - s[i-1][j]-s[i][j-1]+s[i-1][j-1]) {
                h[i][j] = h[i][j + 1] + 1;
            }
        }
    }


    // for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) cout << l[i][j] << " \n"[j == m]; 
    // for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) cout << h[i][j] << " \n"[j == m]; 
    // for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) cout << fd[i][j] << " \n"[j == m]; 
     

    // cout << check(5,1,5) << endl;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            ans = max(ans, js(i, j));
        }
    }
    cout << ans;

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