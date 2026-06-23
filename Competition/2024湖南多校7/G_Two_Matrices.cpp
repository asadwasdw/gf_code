#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int a[N][N];
int b[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>A,B;
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= m; j ++) 
            cin >> a[i][j],A.push_back(a[i][j]);

    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= m; j ++) 
            cin >> b[i][j],B.push_back(b[i][j]);
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    bool ky = true;

    for(int i = 0; i < n * m; i ++) {
        if(A[i] != B[i]) ky = false;
    }
    
    if((n >= 2 && m >= 3) || (n >= 3 && m >= 2) || (n >= 4) || (m >= 4)) {
        
    }
    else {
        if(n == 2 && m == 2) {
            if(a[1][1] != b[1][1]) swap(a[1][1],a[2][2]);
            if(a[1][2] != b[1][2]) swap(a[1][2],a[2][1]);
        }

        if(m == 3) {
            if(a[1][1] != b[1][1]) swap(a[1][1],a[1][3]);
        }

        if(n == 3) {
            if(a[1][1] != b[1][1]) swap(a[1][1],a[3][1]);
        }


        for(int i = 1; i <= n; i ++ ) {
            for(int j = 1; j <= m; j ++) {
                if(a[i][j] != b[i][j]) ky = false;
            }
        }
    }

    if(ky) cout << "YES\n";
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