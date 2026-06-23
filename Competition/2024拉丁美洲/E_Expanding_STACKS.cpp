#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);

int l[N],r[N];
int color[N];

bool dfs(int u, int c) {
    color[u] = c;

    for(auto v : edg[u]) {
        if(color[v]) {
            if(color[v] == c) return 0;
        }
        else {
            if(!dfs(v, 3 - c)) return 0;
        }
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= 2 * n; i ++) {
        int x;
        cin >> x;
        if(x > 0) l[x] = i;
        else r[-x] = i;
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(i == j) continue;
            if(l[i] < l[j] && r[i] < r[j] && r[i] > l[j]) {
                edg[i].push_back(j);    
                edg[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        if(color[i]) continue;
        if(!dfs(i,1)) {
            cout <<"*";
            return ;
        }
    }

    for(int i = 1; i <= n; i ++) {
        if(color[i] == 1) cout << "S";
        else cout << "G";
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