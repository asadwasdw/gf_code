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
int a[N],st[N];
int v[N];

void dfs(int x,int num) {
    if(num > m) return; 
    if(x == n + 1) {
        for(int i = 1; i <= n; i ++) cout << v[i] << " \n"[i == n];
        return;
    }

    for(int i = 1; i <= n; i ++) {
        if(st[i]) continue;
        for(int j = 1; j < x; j ++) {
             
        } 
    }
}

void solve()
{
    cin >> n >> m;
    dfs(1,0);







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