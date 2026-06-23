#include<bits/stdc++.h>
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
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ans = 0;

    for(int i = 1; i < n; i ++) {
        ans = max(ans, min(a[i], a[i + 1]));
    }

    for(int i = 3; i <= n; i ++) {
        vector<int> b;
        b.push_back(a[i]);
        b.push_back(a[i - 1]);
        b.push_back(a[i - 2]);
        sort(b.begin(),b.end());
        ans = max(b[1], ans);
    }


    cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}