#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3e5+10;
const int mod = 1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

ll Inv[N], fac[N];  //分别表示逆元和阶乘
int c[610][610];
int a[610][N];
int b[601][610];

int js(int x,int y) {
    int N = 512;
    int q = x / N, r = x % N;
    int ans = 0;
    // cout << x <<" "<< y <<" "<< q <<" "<< r <<endl;
    for(int i = 0;i <= q;i++) {
        if(b[q][i]) {
            ans^=a[r][i*N+y];
        }
    }
    return ans;
}


void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[0][i];

    for(int i=1;i<513;i++) {
        for(int j=0;j<n;j++){
            if(i+j>=n)break;
            a[i][j] = a[i-1][j] ^ a[i-1][j+1];
        }
    }

  
    b[0][0] = 1;
    for(int i=1;i<=600;i++){
        b[i][0] = b[i][i]  = 1;
        for(int j=1;j<i;j++){
            b[i][j] = b[i-1][j] ^ b[i-1][j-1];
        }
        // for(int j=0;j<=i;j++)cout<<b[i][j]<<" ";cout<<endl;
    }
    
    int q;
    cin>>q;
    while(q--) {
        int x,y;
        cin>>x>>y;
        cout << js(x,y)<<endl;

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