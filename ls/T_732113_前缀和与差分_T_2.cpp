#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N][N];
int t[N][N];
int s[N][N];


int get(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int c = 1; c <= min(n, m); c ++) {

        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(a[i][j] < c) {
                    t[i][j] = 1;
                } else{
                    t[i][j] = 0;
                }
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + t[i][j];
                // cout << t[i][j] << " \n"[j == m];
            }
        }

        for(int x1 = 1; x1 <= n; x1 ++) {
            for(int y1 = 1; y1 <= m; y1 ++) {
                int x2 = x1 + c - 1, y2 = y1 + c - 1;
                if(x2 > n || y2 > m) continue;
                int sum = get(x1, y1, x2, y2);
                if(sum == 0) {
                    ans = max(ans,c);
                } 
            }
        }
    }

    cout << ans;
}

int n, m;
bool check(int c) {
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i][j] < c) {
                t[i][j] = 1;
            } else{
                t[i][j] = 0;
            }
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + t[i][j];
            // cout << t[i][j] << " \n"[j == m];
        }
    }

    for(int x1 = 1; x1 <= n; x1 ++) {
        for(int y1 = 1; y1 <= m; y1 ++) {
            int x2 = x1 + c - 1, y2 = y1 + c - 1;
            if(x2 > n || y2 > m) continue;
            int sum = get(x1, y1, x2, y2);
            if(sum == 0) {
                return true;
            } 
        }
    }

    return false;
}


void solve2() {

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    int l = 0, r = min(n, m);
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    } 

    cout << l;
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
        solve2();
    }
    return 0;
}