#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
#define x first
#define y second

PII a[N];
int len(int i,int j) {
    return  (a[i].x - a[j].x)*(a[i].x - a[j].x) +(a[i].y - a[j].y)*(a[i].y - a[j].y);
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].first >> a[i].second;
    }

    for(int i = 1;i <= n; i++) {
        int ans = i;
        for(int j = 1; j <= n; j ++) {
            if(len(ans,i) < len(i,j)) {
                ans = j;
            }
        }
        cout << ans << endl;
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