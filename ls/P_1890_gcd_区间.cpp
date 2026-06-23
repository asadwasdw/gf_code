#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int b[N][20];
int a[N];
int lg2[N];
void solve()
{
    int n, q;
    cin >> n >> q;
    
    for(int i = 2; i <= n; i ++) {
        lg2[i] = lg2[i >> 1] + 1;
    }

    for(int i = 1; i <= n; i ++) {

        cin >> a[i];
        b[i][0] = a[i];
    }

    for(int j = 1; j < 20; j ++ ) {
        for(int i = 1; i <= n; i ++) {
            b[i][j] = gcd(b[i][j - 1], b[min(n, i + (1 << (j - 1)))][j - 1]);
        }
    }


    while(q --) {
        int l, r;
        cin >> l >> r;
        int lg = lg2[r - l + 1];
        // cout << l << " " << r << " " << lg << " "<<  b[r - (1 << lg) + 1][lg]<< " " << endl;
        cout << gcd(b[l][lg], b[r - (1 << lg) + 1][lg]) << endl;
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
    return 0;
}