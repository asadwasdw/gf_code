// #pragma GCC optimize(2)
#include<bits/stdc++.h>
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
constexpr int N=6e3+10, M=3e3+10;
constexpr int mod=998244353;
constexpr double eps=1e-9;
int nx[] = {0, 0, 1, -1}, ny[] = {1, -1, 0, 0};


int n,m;
P a[M];
int b[N], c[N];
vector<P> gl[N], gr[N];
P f[N][N];
void chmax(P &a, P b){
    if(a.first < b.first)a = b;
    else if(a.first == b.first && a.second < b.second)a.second = b.second;
}
void solve(){
    cin >> n;
    n+=n;
    for(int i=1; i<=n; ++i){
        int x;cin >> x;
        if(!a[x].first)a[x].first = i;
        else a[x].second = i;
        f[i][i].second++;
        b[i] = x;
        c[i] = x;
    }
    for(int i=1; i<n/2; ++i){
        for(int l=a[i].first; l<=a[i].second; ++l){
            if(a[b[l]].first >= a[i].first && a[b[l]].second <= a[i].second){
                if(c[l] < i){
                    c[l] = i;
                }
            }
        }
    }
    for(int i=1; i<=n/2; ++i){
        gl[a[i].second].push_back({a[i].first, c[a[i].first]});
        // cout << a[i].first << ' ' << a[i].second << ' ' << c[a[i].first] << endl;
        gr[a[i].first].push_back({a[i].second, c[a[i].second]});
    }
    for(int len=2; len<=n; ++len){
        for(int i=1,j=i+len-1; j<=n; ++i, ++j){
            if(i+1 <= j-1){
                f[i][j] = f[i+1][j-1];
                f[i][j].second += 2;
            }
            else f[i][j].second = j - i + 1;
            for(auto [l, w] : gl[j]){
                if(l < i)continue;
                if(l == i){
                    chmax(f[i][j], {w * (j - i + 1), 0});
                    if(i+1 <= j-1)chmax(f[i][j], {w * (f[i+1][j-1].second + 2) + f[i+1][j-1].first, 0});
                }
                else{
                    chmax(f[i][j], {w * (j - l + 1) + f[i][l-1].first, f[i][l-1].second});
                    if(l+1 <= j-1)
                    chmax(f[i][j], {w * (f[l+1][j-1].second + 2) + f[l+1][j-1].first + f[i][l-1].first, f[i][l-1].second});
                }
            }
            for(auto [r, w] : gr[i]){
                if(r > j)continue;
                if(j == r){
                    chmax(f[i][j], {w * (j - i + 1), 0});
                }
                else{
                    chmax(f[i][j], {w * (r - i + 1) + f[r+1][j].first, f[r+1][j].second});
                    if(i+1 <= r-1)
                    chmax(f[i][j], {w * (f[i+1][r-1].second + 2) + f[i+1][r-1].first + f[r+1][j].first, f[r+1][j].second});
                }
            }
            // cout << i <<  ' ' << j << ' ' << f[i][j].first << ' ' << f[i][j].second << endl;
        }
    }
    cout << f[1][n].first << endl;


}


signed main()
{   
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int t = 1;
    // cout << fixed << setprecision(9)
    // cin >> t;
    while(t--)solve();
    return 0;

}
