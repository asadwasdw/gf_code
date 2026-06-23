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
PII b[N];

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i].first =  a[i];
        b[i].second = 1;
    }
    for(int i = 1; i <= m; i ++) {
        cin >> b[i + n].first;
        b[i + n].second = 2;
    }

    sort(b + 1, b + n + m + 1);
    // for(int i = 1;  i <= n + m; i ++ ) cout << b[i] << " \n"[i == n + m];

    bool ky = false;
    for(int i = 1; i < n + m; i ++) {
        if(b[i].second + b[i + 1].second == 2) ky = true;
    } 
    if(ky) cout << "Yes";
    else cout << "No";



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