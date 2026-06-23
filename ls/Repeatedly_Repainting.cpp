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


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n + 10,vector<char>(m + 10,'.'));
    vector<vector<int>> dis(n + 10,vector<int>(m + 10,0));


    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> v[i][j];
      
        }
    }

    int cnt = 4;
    while(cnt --){
        vector<vector<char>> v2(n + 10,vector<char>(m + 10,'.'));

        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                int cnt = 0;
                for(int x = -1; x <= 1; x ++) {
                    for(int y = -1; y <= 1; y ++) {
                        cnt += (v[x + i][y + j] == '#');
                    }
                }

                
                if(cnt && v[i][j] == '.') v2[i][j] = '#';

                if(v[i][j] == '#') v2[i][j] = '.';

            }
        }
        v = v2;


        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                cout << v[i][j];
            }
            cout << endl;
        } 
        cout << endl;

    }



    queue<PII> q;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(v[i][j] == '#') {
                dis[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    
    while(q.size()) {
        auto [x, y] = q.front(); q.pop();

        for(int i = -1; i <= 1; i ++) {
            for(int j = -1; j <= 1; j ++) {
                int tx = x + i;
                int ty = y + j;
                if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
                if(dis[tx][ty]) continue;
                dis[tx][ty] = dis[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }


    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(dis[i][j] % 2) cout << '#';
            else cout << ".";
        }
        cout << endl;
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