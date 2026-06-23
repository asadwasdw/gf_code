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

int C[110][100];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            cin >> C[i][j];
        }
    }


    for(int a = 1; a <= n; a ++) {
        for(int b = a + 1; b <= n; b ++) {
            for(int c = b + 1; c <= n; c ++) {
                if(C[a][c] > C[a][b] + C[b][c]) {
                    cout << "Yes";
                    return;
                }
            }
        }
    }

    cout << "No";







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