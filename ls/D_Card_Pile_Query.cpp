#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


int h[N];
int ne[N];
int pre[N];

void solve()
{
    memset(h, -1, sizeof h);
    memset(ne, -1, sizeof ne);
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i ++) {
        h[i] = i;
        ne[i] = -1;
        pre[i] = i;
    }

    while(q --) {
        int x, y; cin >> x >> y;
        if(pre[x] <= n) {
            h[pre[x]] = -1;
        } else {
            ne[pre[x] - n] = -1;
        }
        pre[x] = y + n;
        ne[y] = x;

        // for(int i = 1; i <= n; i ++) cout << h[i] << " ";
        // cout << endl;
    }


    for(int i = 1; i <= n; i ++) {
        int j = h[i];
        int cnt = 0;
        while(j != -1) {
            cnt ++;
            j = ne[j];
        }
        cout << cnt << " ";
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
    return 0;
}