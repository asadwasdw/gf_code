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
int a[N];

void solve()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

 int ans = abs(sy - ty) + max(0ll,(abs(sx - tx) - abs(sy - ty)) / 2);
    if((sx + sy) % 2 == 0) {
        sx ++;
        ans = max(ans,abs(sy - ty) + max(0ll,(abs(sx - tx) - abs(sy - ty)) / 2));
    }
    else {
        sx --;
        ans = max(ans,abs(sy - ty) + max(0ll,(abs(sx - tx) - abs(sy - ty)) / 2));
    }


    cout << ans;
    bool t = true;
    cout << !t << " " << t << endl;
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