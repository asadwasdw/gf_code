#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=200+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];
int f[N][N][4];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; ++i){
        int x,y;
        cin >> x >> y;
        f[x][y][0]++;
        f[x][y][1]++;
        f[x+1][y][0]++;
        f[x+1][y][3]++;
        f[x][y+1][1]++;
        f[x][y+1][2]++;
        f[x+1][y+1][2]++;
        f[x+1][y+1][3]++;
    }
    int res = 0;
    for(int i=1; i<=100; ++i)for(int j=1; j<=100; ++j){
        for(int k=0; k<4; ++k)
        if(f[i][j][k]){
            res ++;
        }
    }
    cout << (double)res / 4 << endl;







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