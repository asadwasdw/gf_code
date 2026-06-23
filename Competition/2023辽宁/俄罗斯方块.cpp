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

int a7[10][10] = {
    {0},
    {0,1},
    {0,1,1},
    {0,1,2,2},
    {0,3,2,2,4},
    {0,3,3,4,4,4},
    {0,3,5,6,6,6,7},
    {0,5,5,5,6,7,7,7},
};

int a8[10][10] = {
    {0},
    {0,1},
    {0,1,1},
    {0,1,2,2},
    {0,6,2,2,3},
    {0,6,6,3,3,3},
    {0,6,8,8,8,4,4},
    {0,7,7,8,9,4,4,5},
    {0,7,7,9,9,9,5,5,5},
};


int b8[10][10] = {
    {0},
    {0,1,1,2,2,3,3,4,4},
    {0,1,1,2,2,3,3,4,4},
    {0,5,5,6,6,7,7,8,8},
    {0,5,5,6,6,7,7,8,8},
    {0,9,9,10,10,11,11,12,12},
    {0,9,9,10,10,11,11,12,12},
    {0,13,13,14,14,15,15,16,16},
    {0,13,13,14,14,15,15,16,16},
};

int a[2000][2000];
int t = 1;
void fza7(int &idx, int x, int y) {
    for(int i = 1; i <= 7; i ++) {
        for(int j = 1; j <= i; j ++)    
            a[i + x - 1][j + y - 1] = idx + a7[i][j];
    }
    idx += 7 * t;
}

void fza8(int &idx, int x, int y) {
    for(int i = 1; i <= 8; i ++) {
        for(int j = 1; j <= i; j ++)    
            a[i + x - 1][j + y - 1] = idx + a8[i][j];
    }
    idx += 9 * t;
}

void fzb8(int &idx, int x, int y) {
    for(int i = 1; i <= 8; i ++) {
        for(int j = 1; j <= 8; j ++)    
            a[i + x - 1][j + y - 1] = idx + b8[i][j];
    }
    idx += 16 * t;
}

void solve()
{
    int n;
    cin >> n;

 
    
    int idx = 0;
    if(n % 8 == 7) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= i; j ++) {
                if(a[i][j]) continue;
                if(i == j  && i % 8 == 1) {
                    fza7(idx, i, j);
                } else fzb8(idx, i, j);
            }
        }

    } else if(n%8 == 0){
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= i; j ++) {
                if(a[i][j]) continue;
                if(i == j  && i % 8 == 1) {
                    fza8(idx, i, j);
                } else fzb8(idx, i, j);
            }
        }
    } else {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= i; j ++) cout << a[i][j] << " \n"[i == j];
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