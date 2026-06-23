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

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};


void work(int x, int y, int w) {
    if(w == 0) {a[x][y] = 0;return;}
    set<int> s;
    for(int i = 0; i < 4; i ++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx < 0 || tx > n || ty < 0 || ty > n) continue;
        s.insert(a[tx][ty]);
    }
    int ans = 0;
    while(s.count(ans)) ans ++;
    a[x][y] = w;
}

void solve()
{
    memset(a, -1, sizeof a);
    cin >> n;
    for(int i = 0; i < n; i ++) {
         for(int j = 0; j < n; j ++) work(i, j, 0);
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i % 3 == 1 && j % 3 == 2) work(i, j, 1);   
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i % 3 == 2 && j % 3 == 2) work(i, j, 2);   
        }
    }


    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i % 3 == 2 && j % 3 == 1) work(i, j, 1);   
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 3 == 1 && j % 3 == 1) {
                work(i, j, 1);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + 1) % 3 == j % 3) {
                if (i == n - 1 || j == n - 1 || j == 0) {
                    continue;
                }
                if (i % 3 == 0) {
                    work(i, j + 1, 2);
                }
                work(i, j, 3);
            } else if ((i + 2) % 3 == j % 3) {
                if (i == n - 1 || j == n - 1 || i == 0) {
                    continue;
                }
                if (j % 3 == 0) {
                    work(i + 1, j, 2);
                }
                work(i, j, 3);
            }
        }
    }
    
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) cout << a[i][j] << " \n"[j == n - 1];
    }

    if (n % 3 == 1) {
        for (int i = 2; i < n; i += 3) {
            work(n - 1, i - 1, 1);
            work(n - 1, i, 3);
            work(i - 1, n - 1, 1);
            work(i, n - 1, 3);
        }
    } else if (n % 3 == 2) {
        for (int i = 3; i < n; i += 3) {
            work(n - 1, i - 1, 2);
            work(n - 1, i, 3);
            work(i - 1, n - 1, 2);
            work(i, n - 1, 3);
        }
    } else {
        for (int i = 1; i < n; i += 3) {
            work(n - 1, i - 1, 0);
            work(n - 1, i, 3);
            work(i - 1, n - 1, 0);
            work(i, n - 1, 3);
        }
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