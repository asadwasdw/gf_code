#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N][N], pre[N][N];
int main(){
    int n, m, c, maxnum = -1e9, ansx, ansy;
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    for(int x1 = 1; x1 + c - 1 <= n; x1++){
        for(int y1 = 1; y1 + c - 1 <= m; y1++){
            int x2 = x1 + c - 1; 
            int y2 = y1 + c - 1;
            int num = pre[x1 - 1][y1 - 1] + pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1];
             if(num > maxnum){
                 maxnum = num;
                 ansx = x1;
                 ansy = y1;
             }
        }
    }
    cout << ansx << " " << ansy;
    return 0;
}