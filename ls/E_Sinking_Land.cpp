#include<bits/stdc++.h>
#define int long long
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
bool st[N][N];
int d[N][N];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};



void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> q;
    


    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            d[i][j] = 100; // 给INF定了个100，cao
            cin >> a[i][j];
            if(i == 1 || i == n || j == 1 || j == m) q.push({a[i][j], i, j}), d[i][j] = a[i][j];
        }
    }
    
  

    while(q.size()) {
        auto [w, x, y] = q.top(); q.pop();

        if(st[x][y]) continue;
        st[x][y] = true;

        // cout << x << " " << y << endl;

        for(int k = 0; k < 4; k ++) {
            int tx = x + dx[k];
            int ty = y + dy[k];

        
                
            if(tx <= 1 || tx >= n || ty <= 1 || ty >= m) continue;

            if(st[tx][ty]) continue;

            if(max(w, a[x][y]) >= d[tx][ty]) continue;
    

            d[tx][ty] = max(w, a[x][y]);
            q.push({d[tx][ty], x, y});
        } 
    }


    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= m; j ++) cout << d[i][j] << " \n"[j == m];
    // }

    vector<int> l;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            l.push_back(max(a[i][j], d[i][j]));
        }
    }

    sort(l.begin(), l.end());

    for(int i = 1; i <= k; i ++) {
        cout << -(upper_bound(l.begin(),l.end(),i) - l.end()) << endl;
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