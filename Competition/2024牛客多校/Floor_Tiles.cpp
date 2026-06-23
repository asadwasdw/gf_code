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

char a[N][N];
int n, m;
int f[N];
int id[N][N][4];
int cnt = 0;

int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void merge(int a, int b) {
    // cout << a << " " << b << endl;
    a = find(a), b = find(b);
    if(a != b) f[b] = a;
}

int js(){
    cnt = 0;
    for(int i = 0; i < N; i ++) f[i] = i;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            id[i][j][0] = ++cnt;
            id[i][j][1] = ++cnt;
            id[i][j][2] = ++cnt;
            id[i][j][3] = ++cnt;
        }
    }
    
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i][j] == 'B') {
                merge(id[i][j][0],id[i][j][1]);
                merge(id[i][j][2],id[i][j][3]);
            }
            else {
                merge(id[i][j][0],id[i][j][3]);
                merge(id[i][j][1],id[i][j][2]);
            }

            if(j != m)merge(id[i][j][1],id[i][j + 1][3]);
            if(i != n)merge(id[i][j][2],id[i + 1][j][0]);
        }
    }

    int ans = 0;
    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= m; j ++) {
    //         for(int k = 0; k < 4; k ++) {
    //             if(find(id[i][j][k] == id[i][j][k])) ans ++;
    //         }
    //     }
    // }

    for(int i = 1; i <= cnt; i ++ ) {
        if(i == find(i)) ans ++;
        // cout << i << " " << find(i) << endl;
    }
    return ans;
}




void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    cout << js();
    






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