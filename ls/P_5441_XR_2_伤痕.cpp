#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N][N];


void solve()
{
    int n;
    cin >> n;
    if(n == 1) cout << "0\n";

    else cout<<n*(n-3)*(n*n+6*n-31)/48<<endl;
    for(int i = 0; i < n; i ++) {
        // a[i][(i + 1) % n] = a[(i + 1) % n][i] = 1;
        for(int j = 1; j < n; j ++) {
            int z = (i + j) % n;
            if(j == 1) a[i][z] = a[z][i] = 1;
            else if(j % 2 == 0) a[i][z] = 1;
            else a[z][i] = 1; 
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            ans += a[i][j];
            cout << a[i][j] << " \n"[j == n - 1];
        }
    }

    // if(ans != n*(n + 1)/ 2) cout << "NO";

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