#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m,k;
int a[N],b[N],c[N];
int sa[N],sb[N];

bool dp[110][55][55];
bitset<4000001>bit;

bool pd(int c, int x1, int y1, int x2, int y2) {
    if(x1 < x2)  c -= sa[x2 - 1] - sa[x1 - 1];
    else if(x2 < x1) c -= sa[n] - sa[x1 - 1] + sa[x2 - 1];

    if(y1 < y2) c -= sb[y2 - 1] - sb[y1 - 1];
    else if(y2 < y1) c -= sb[m] - sb[y1 - 1] + sb[y2 - 1];

    if(c < 0) return false;
    return bit[c];
}



int extend_gcd(int A, int B, int &x, int &y) {
    if(B == 0) {x = 1; y = 0; return A;}
    ll d = extend_gcd(B, A % B, y, x);
    y -= A/B * x;
    return d;
} 


bool pd2(int c, int x1, int y1, int x2, int y2) {
    if(x1 < x2) {
        c -= sa[x2 - 1] - sa[x1 - 1];
    }
    else if(x2 < x1) {
        c -= sa[n] - sa[x1 - 1] + sa[x2 - 1];
    }

    if(y1 < y2) {
        c -= sb[y2 - 1] - sb[y1 - 1];
    }
    else if(y2 < y1) c -= sb[m] - sb[y1 - 1] + sb[y2 - 1];
    if(c < 0) return false;
    int A = sa[n];
    int B = sb[m];
    int C = c;
    int x,y;
    int D = extend_gcd(A,B, x, y);
    if(C % D != 0) return false;

    int X = ((x*(C/D)) % (B/D) + (B/D)) % (B/D);
    if(C - X * A < 0) return false;
    return true;
}
void solve()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i],sa[i] = a[i] + sa[i - 1];
    for(int i = 1; i <= m; i ++) cin >> b[i],sb[i] = b[i] + sb[i - 1];
    for(int i = 1; i <= k; i ++) cin >> c[i];

    int A = sa[n];
    int B = sb[m];
    bit[0] = 1;


    for(int i = 1; i <= 4000000; i ++) {
        if(bit[i] >= A) bit[i] = bit[i] || bit[i - A];
        if(bit[i] >= B && ) bit[i] = bit[i] || bit[i - B];
        if(i <= 10) cout <<bit[i] <<endl;
    }

    cout << bit[5] << endl;

    bool ky = false;
    dp[1][1][1] = true;
    for(int i = 1; i <= k; i ++) {
        for(int x1 = 1; x1 <= n; x1 ++)     
            for(int y1 = 1; y1 <= m; y1 ++) {
                // if(dp[i][x1][y1] == false) continue;

                for(int x2 = 1; x2 <= n; x2 ++) 
                    for(int y2 = 1; y2 <= m; y2 ++) {
                        // if(pd(c[i],x1,y1,x2,y2)) {
                        //     dp[i + 1][x2][y2] = true;
                        //     if(i == k) ky = true;
                        // }

                        if(pd(c[i],x1,y1,x2,y2) != pd2(c[i],x1,y1,x2,y2)) {

                            // cout << pd(c[i],x1,y1,x2,y2) << " " << pd2(c[i],x1,y1,x2,y2) << endl;
                            cout << c[i] <<" "<< x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                        }
                    }
            }
    } 

    if(ky) cout << "yes";
    else cout  <<"no";
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("bitase %d: ",i);
        solve();
    }
}