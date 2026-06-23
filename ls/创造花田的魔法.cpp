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
char a[N][N];
char ans[N][N];

bool isS(int x,int y) {
    if(a[x][y] != 'L' )return false;
    bool ky = true;
    for(int i = -1; i <= 1; i ++) {
        for(int j = - 1; j <= 1; j ++){
            if(a[x + i][y + j] != 'L') ky = false;
        }
    }
    return ky;
}

bool isN(int x,int y) {
    if(a[x][y] != 'G' )return false;
    bool haveL = false, noH = true;
    for(int i = -1; i <= 1; i ++) {
        for(int j = - 1; j <= 1; j ++){
            if(a[x + i][y + j] == 'L') haveL = true;
            if(a[x + i][y + j] == 'H') noH = false;
        }
    }
    // cout << haveL << " " << noH << endl;
    if(haveL && noH) return true;
    return false;
}

bool isB(int x,int y) {
    if(a[x][y] != 'G' )return false;
    for(int i = -1; i <= 1; i ++) {
        for(int j = - 1; j <= 1; j ++){
            if(a[x + i][y + j] == 'H') return false;
        }
    }
    return true;
}



void solve()
{
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            a[i][j] = 'M';
        }
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++ ){
            cin >> a[i][j];
            ans[i][j] = a[i][j];
        }
    }
    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= m; j ++ ) cout << a[i][j] <<" \n"[j == m];
    // }cout << endl;
    // cout << isN(1,1)<< endl;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1;j <= m; j ++) {
            if(isS(i,j))ans[i][j] = 'S';
            else if(isN(i,j))ans[i][j] = 'N';
            else if(isB(i,j)) ans[i][j] = 'B';
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++ ) cout << ans[i][j];cout << endl;
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