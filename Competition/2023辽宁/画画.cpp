#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[N][N];


void solve()
{
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 1));
    for(int i = 0; i < n; i ++) {
        if(i % 2 != n % 2) a[i][i] = 0;
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << a[i][j];
        }cout << endl;
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
}