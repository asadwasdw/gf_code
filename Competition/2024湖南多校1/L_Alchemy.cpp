// #pragma GCC optimize(2)
#include<bits/stdc++.h>
#define init ios::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define endl '\n'
#define lowbits(x) ((x)&((-x)))
#define INF 0x3f3f3f3f
#define uu __int128
#define PI acos(-1)
#define ls k<<1
#define rs k<<1|1
using namespace std;
typedef  long long ll;
typedef  unsigned long long ull;
typedef pair<int, int> P;
typedef pair<int, pair<int, int> > PII;
const int N=2e6+10, M=2*N;
const int mod=998244353;
const double eps=1e-9;
int nx[] = {0, 0, 1, -1}, ny[] = {1, -1, 0, 0};


int n,m;
string s;

int a[N];
int f[N][2];

void solve(){
    cin >> s;
    n = s.size();
    s = " " + s;
    f[0][1] = INF;
    for(int i=1; i<=n/2; ++i){
        if(s[i] == s[n-i+1]){
            f[i][0] = min(f[i-1][0], f[i-1][1]+1);
            f[i][1] = f[i-1][1] + 1;
        }
        else{
            f[i][0] = min(f[i-1][0]+2, f[i-1][1]+1);
            f[i][1] = min(f[i-1][0]+1, f[i-1][1]+2);
        }
    }
    cout << min(f[n/2][0], f[n/2][1]) << endl;

}


signed main()
{   
    init;
    int t = 1;
    // cout << fixed << setprecision(9)
    // cin >> t;
    while(t--)solve();
    return 0;

}
