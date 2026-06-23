#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N][N];


void solve()
{
    int n = 9;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            char t; cin >> t;a[i][j] = t - '0';
            // cin >> a[i][j];
        }
    } 

    bool ky = false;

    for(int i = 2; i < n && !ky; i ++) {
        for(int j = 2; j < n && !ky; j ++) {
            if(a[i][j] == 8) {
                a[i][j] = 0;
                ky = true;
            }
        }
    } 

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j ++ ){
            if(a[i][j] == 0) cout << '8';
            else cout << '*';
        }
        cout << endl;
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