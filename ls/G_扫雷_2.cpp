#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve()
{
    int n, m;
    cin >> n >> m;
    vector a(n + 10, vector(n + 10, 0));
    if(m >= 4 * n - 4) { // 可以围一圈
        for(int i = 1; i <= n; i ++)  a[i][1] = a[i][n] = a[n][i] = a[1][i] = 1;

        m -= 4 * n - 4;
        for(int i = 2; i < n; i ++) {
            for(int j = 2; j < n; j ++) {
                if(m) {
                    a[i][j] = 1, m--;
                    if(m == 0 && a[i + 1][j + 1] == 0) {
                        swap(a[1][1], a[i + 1][j + 1]);
                    }
                }
            }
        }
    }
    else if(m >= 11) { // 围一个3*3的
        int x = n - 1, y = n - 1;

        while(2 * x + 2 * y - 4 > m - 3) {
            if(x > y) x--;
            else y --;
        }
        // cout << x << " " << y << endl;
        for(int i = 1; i <= x; i ++) {
            for(int j = 1; j <= y; j ++) {
                if(i == 1 || j == 1 || i == x || j == y) a[i][j] = 1, m --;
            }
        }

        a[x + 1][1] = a[1][y + 1] = a[x + 1][y + 1] = 1;
        m -= 3;

        for(int i = 2; i < x; i ++) {
            for(int j = 2; j < y; j ++) {
                if(m) {
                    a[i][j] = 1, m--;
                    if(m == 0 && a[i + 1][j + 1] == 0) {
                        swap(a[1][1], a[i + 1][j + 1]);
                    }
                }
            }
        }
    } else {
        if(m==10)a[1][1]=a[1][2]=a[1][3]=a[1][4]=a[2][1]=a[2][2]=a[2][3]=a[3][1]=a[3][2]=a[4][1]=1;
        if(m==9)a[1][2]=a[1][3]=a[1][4]=a[2][1]=a[2][2]=a[2][3]=a[3][1]=a[3][2]=a[4][1]=1;
        if(m==8)a[1][1]=a[1][3]=a[1][4]=a[2][2]=a[2][3]=a[3][1]=a[3][2]=a[4][1]=1;
        if(m==7)a[1][1]=a[1][2]=a[1][3]=a[2][1]=a[2][2]=a[3][1]=a[n][n]=1;
        if(m==6)a[1][1]=a[1][2]=a[1][3]=a[2][1]=a[2][2]=a[3][1]=1;
        if(m==5)a[1][1]=a[1][2]=a[2][1]=a[n][1]=a[1][n]=1;
        if(m==4)a[1][1]=a[1][2]=a[2][1]=a[n][n]=1;
        if(m==3)a[1][1]=a[1][2]=a[2][1]=1;
        if(m==2)a[1][1]=a[n][1]=1;
        if(m==1)a[1][1]=1;
    }

    cout << "Yes\n";

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
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