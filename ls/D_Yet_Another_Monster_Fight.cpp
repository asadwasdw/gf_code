#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
#define int long long 
int a[N];
int b[N];
int c[N];

void solve()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        b[i] = a[i]-i;
        c[i] = a[i]+i;
        b[i] = max(b[i], b[i-1]);
    }

    for(int i=n; i; i--) {
        c[i] = max(c[i],c[i+1]);
    }

    int ans = INF ;
    for(int i=1;i<=n;i++) {
       int res = a[i];
       res = max(i + b[i-1]+(n-i),res);
       res = max(c[i+1]+(i-1)-i,res);
       ans = min(ans, res);
    }
    cout << ans << endl;


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}