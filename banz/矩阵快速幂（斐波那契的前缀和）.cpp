#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
const int M = 4;
struct matrix{
    int m[M][M]={0};
    matrix(){};
    matrix(int t){
        for(int i = 1; i < M;i ++) {
            for(int j = 1; j < M; j ++) {
                m[i][j] = t;
            }
        }
    }

    void print(){
        for(int i = 1; i < M;i ++) {
            for(int j = 1; j < M; j ++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

matrix operator * (const matrix& a, const matrix & b) {
    matrix c(0);
    for(int i = 1; i < M;i ++) {
        for(int k = 1; k < M; k ++) 
            if(a.m[i][k]) 
                for(int j = 1; j < M; j ++) 
                    if(b.m[k][j]) {
                        c.m[i][j] += a.m[i][k] * b.m[k][j];
                        c.m[i][j] %= mod;
                    }
    }
    return c;
}

matrix qmi(matrix a, int b) {
    matrix res(0);
    for(int i = 1; i < M; i ++) res.m[i][i] = 1;
    while(b) {
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 

void solve()
{
    int n;
    cin >> n;

    matrix t1(0),t2(0);
    t1.m[1][1] = 1;
    t1.m[1][2] = 1;
    t1.m[1][3] = 1;
    
    t2.m[2][1] = 1;
    t2.m[1][2] = 1;
    t2.m[2][2] = 1;
    t2.m[2][3] = 1;
    t2.m[3][3] = 1;

    // t1.print();
    // t2.print();
    // (t1*qmi(t2, n-1)).print();
    cout << (t1*qmi(t2,n-1)).m[1][1]<<endl;

    // m[1][1] 是斐波那契第n项
    // m[1][3] 是斐波那契前n项和
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