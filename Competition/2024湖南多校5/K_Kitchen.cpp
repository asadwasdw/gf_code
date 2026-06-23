#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int b[N];
int c[N];


void solve()
{
    int n,nx,ny;
    cin >> n >> nx >> ny;
    vector<int>a;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int mn = a[0],mx = a[n - 1];
    for(int i = 1; i<= nx; i ++) cin >> b[i];
    for(int i = 1; i<= ny; i ++) cin >> c[i];

    for(int i = 1; i <= nx; i ++) {
        for(int j = 1; j <= ny; j ++) {
            int t = b[i] * c[j];
            if(t >= mn && t <= mx) a.push_back(t);
        }
    }
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i = 1; i < a.size(); i ++) {
        ans = max(ans, a[i] - a[i - 1]);
    }
    cout << ans << endl;
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