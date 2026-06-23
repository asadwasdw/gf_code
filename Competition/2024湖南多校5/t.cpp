#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int a[N][N];
int s[N][N];
int s2[N][N];

void solve()
{
    int n,m;
    cin >> n >> m;

    while(m -- ) {
        int x, y, r;
        cin >> x >> y >> r;
        x ++, y++;
        a[x][y - r] += 1;
        a[x][y + r] += 1;
        a[x - r][y] -= 1;
        a[x + r][y] -= 1;
        
        s2[x][y + r] += 1;
        s2[x + r][y] += 1;
        s2[x - r][y] += 1; 
    }

    // for(int i = 2; i <= n + 1; i ++) {
    //     for(int j = 2; j <= n + 1; j ++) a[i][j] = 1;
    // }

    
    for(int i = 2; i <= n + 1; i ++ ) {
        for(int j = 2; j <= n + 1; j ++) cout << a[i][j] << " \n"[j == n + 1];
    }
    cout << endl;

    for(int j = 2; j <= n + 1; j ++) {
        for(int i = 1; i <= n + 2; i ++) {
            s[i][j] = a[i][j] + a[i][j-1] + s[i-1][j-1] + s[i+1][j-1] - s[i][j - 2];
            s2[i][j] += s[i][j];
        }
    }

    for(int i = 2; i <= n + 1; i ++ ) {
        for(int j = 2; j <= n + 1; j ++) cout << s[i][j] << " \n"[j == n + 1];
    }
    cout << endl;
 
    for(int i = 2; i <= n + 1; i ++ ) {
        for(int j = 2; j <= n + 1; j ++) cout << s2[i][j] << " \n"[j == n + 1];
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