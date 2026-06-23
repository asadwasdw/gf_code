#include<bits/stdc++.h>
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
    vector<int> ans;
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= n; j ++)    
            cin >> a[i][j];

    
    for(int i = 1; i <= n; i ++) {
        if(i % 2) for(int j = 1; j <= n; j ++) ans.push_back(a[i][j]);
        else for(int j = n; j >= 1; j--) ans.push_back(a[i][j]);
    }
    int cnt = 0;
    for(int i = 1; i < n*n; i ++) {
        if(ans[i] > ans[i - 1]) cnt++;
    }
    if(cnt * 2 > n*n )reverse(ans.begin(), ans.end());
    for(int i =0; i < n*n; i ++) cout << ans[i] << " \n"[i == n*n-1];
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