#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

//vector<vector<int>>edg(N);
#define first x;
#define secode y;

char a[3][N];
bool st[3][N];

void solve()
{
    int n;
    cin >> n;
    queue<PII>q;

    for(int i = 1; i <= n; i ++) {
        st[1][i] = st[2][i] = false;
    }

    for(int i = 1; i <= n; i ++) cin >> a[1][i];
    for(int i = 1; i <= n; i ++) cin >> a[2][i];

    q.push({1,1});

    while(q.size()) {
        auto [x,y] = q.front(); q.pop();
        if(st[x][y]) continue;
        st[x][y] = true;

        for(int k = 0; k < 4; k ++) {
            int tx = x + dx[k];
            int ty = y + dy[k];

            if( tx < 1 || tx > 2 || ty < 1 || ty > n) continue;
            if(tx == 2 && ty == n) {
                cout << "YES\n";
                return;
            }
            if(a[tx][ty] =='<')ty--;
            else ty++;
            q.push({tx,ty});
        }
    }

    if(st[2][n]) cout << "YES\n";
    else cout << "NO\n";
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