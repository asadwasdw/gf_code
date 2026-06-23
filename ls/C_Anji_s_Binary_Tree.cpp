#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n;
int l[N],r[N];
string s;
int ans = INF;

void dfs(int u,int dis,int num) {
    if(l[u] == 0 && r[u] == 0) {
        ans = min(num, ans);
        return;
    }

    if(l[u]) {
        int t = 0;
        if(s[u] != 'L')t++;
        dfs(l[u],dis+1,num+t);
    }

    if(r[u]) {
        int t = 0;
        if(s[u] != 'R')t++;
        dfs(r[u],dis+1,num+t);
    }
}

void solve()
{
    ans = INF;
    cin >> n;
    cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    dfs(1,0,0);
    cout << ans << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}