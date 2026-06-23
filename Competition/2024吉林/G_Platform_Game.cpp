#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];

struct T
{
    int y;
    int l, r;
}p[N];


bool cmp(T a, T b) {
    if(a.y != b.y) return a.y > b.y;
    return a.l < b.l;
}


void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i].l >> p[i].r >> p[i].y;
    }
    sort(p + 1, p + n + 1,cmp);
    int x, y;
    cin >> x >> y;

    for(int i = 1; i <= n; i ++){
        if(p[i].y >= y) continue;
        if(p[i].r <= x) continue;
        if(p[i].l >= x) continue;
        y = p[i].y;
        x = p[i].r;
    }



    cout << x << endl;






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