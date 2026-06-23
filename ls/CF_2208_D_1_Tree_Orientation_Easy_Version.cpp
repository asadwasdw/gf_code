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

int f[N];

int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}



void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) f[i] = i;
    vector<vector<int>> d(n + 1, vector<int> (n + 1, 0));
    vector<vector<int>> d1(n + 1, vector<int> (n + 1, 0));
    vector<vector<int>> d2(n + 1, vector<int> (n + 1, 0));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            char x; cin >> x;
            if(x == '1') {
                d[i][j] = 1;
                d1[i][j] = 1;
            }
        }
    }

    for(int k = 1; k <= n; k ++) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(i != j && k != i && k != j && d[i][k] == 1 && d[k][j] == 1 && d[i][j] == 1) {
                    d[i][j] = 0;
                }
            }
        }

        // for(int i = 1; i <= n; i ++) {
        //     for(int j = 1; j <= n; j ++) {
        //         cout << d[i][j] << " \n"[j == n];
        //     }
        // }cout << endl;
    }
    int cnt = 0, cnt2 = 0;
    // vector<int> f(n + 1, 0);
    bool ky = true;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(i == j ) {
                if(d[i][j]) cnt2 ++;
                continue;
            } 
            if(d[i][j] == 0) continue;
            // cout << i << " " << j << endl;
            cnt ++;
            int x = find(i), y = find(j);
            if(x == y)ky = false;
            f[x] = y;
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            d2[i][j] = d[i][j];
        }
    }
    for(int i = 1; i <= n; i ++) d2[i][i] = 1;

    for(int k = 1; k <= n; k ++) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                d2[i][j] |= d2[i][k] & d2[k][j];
            }
        }
    }
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) if(d1[i][j] != d2[i][j]) ky = false;


    if(cnt != n - 1 || cnt2 != n || !ky) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(i == j) continue;
                if(d[i][j] == 0) continue;
                cout << i << " " << j << endl;
            }
        }
    }
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
    return 0;
}