#include<bits/stdc++.h>
// #define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N= 4e6+10;
const int M = 1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n"

//vector<vector<int>>edg(N);

int p[N][27],idx;
ll W[N];

void add(string &s,ll w) {
    int now = 0;
    for(int i=0;i<s.size();i++) {
        int t = s[i] - 'a' + 1;
        if(p[now][t] == 0) {
            // memset(p[idx+1] , 0, sizeof p[idx+1]);
            // for(int i)
            p[now][t] = ++ idx;
            // W[idx] = 0;
        }
        now = p[now][t];
    }
    W[now] = w;
}

ll find(string &s) {
    ll now = 0;
    for(int i=0;i<s.size();i++) {
        int t = s[i] - 'a' + 1;
        if(p[now][t] == 0) {
            return -1;
        }
        now = p[now][t];
    }
    return W[now];
}

char a[M][M];


void solve()
{
    idx = 0;
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
    }

    while(m--) {
        string s; ll w;
        cin >> s >> w;
        if(s.size() > n) continue;
        add(s, w);
    }

    ll ans = 0;
    bool ok = true;

    for(int i = 1; i <= n; i++) {
        string s = "";
        for(int j = 1; j <= n;j ++) {
            
            if(a[i][j]=='#' || j == n) {
                if(j == n && a[i][j] != '#') s += a[i][j];
                if(s.size() ) {
                    ll t = find(s);

                    if(t <= 0) ok = false;
                    else ans += t;

                    // cout << s << endl;
                    s = "";
                }
            }
            else s += a[i][j];
        }
    }


    for(int i = 1; i <= n; i++) {
        string s = "";
        for(int j = 1; j <= n;j ++) {
            
            if(a[j][i]=='#' || j == n) {
                if(j == n && a[j][i] != '#') s += a[j][i];
                if(s.size()) {
                    ll t = find(s);

                    if(t <= 0) ok = false;
                    else ans += t;

                    // cout << s << endl;
                    s = "";
                }
            }
            else s += a[j][i];
        }
    }
    if(!ok)cout <<"-1"<<endl;
    else cout<<ans<<endl;

    for(int i=0;i<=idx;i++) {
        for(int j=0;j<27;j++)p[i][j]=0;
        W[i]=0;
    }

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