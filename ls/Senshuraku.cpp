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

int a[N];
int ans = 0;
int dpl[N][3], dpr[N][3];

void solve()
{
    int n;
    cin >> n;
    int mx1 = 0, mx2 = 0;

    for(int i = 1; i <= 2 * n; i ++) {
        cin >> a[i];
        if(a[i] > mx1) {
            mx2 = mx1;
            mx1 = a[i];
        } else if(a[i] > mx2) {
            mx2 = a[i];
        }
    }

    for(int i = 1; i <= 2 * n; i += 2) {
        for(int t = 0; t < 2; t ++) {
            int x = (t == 0) + a[i];
            int y = (t == 1) + a[i];
            
        }
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