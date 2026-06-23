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
int a[N],b[N],c[N],d[N];


void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int t; cin >> t;
        t--;
        int x = t / n;
        int y = t % n;
        a[x] ++ ;
        b[y] ++;
        c[x + y]  ++;
        d[x - y + 2010] ++;
        // cout << x << " " << y << endl;
        if(a[x] == n || b[y] == n || c[x + y] == n || d[x - y + 2010] == n) {
            cout << i;
            return;
        }
        
    }

    cout << "-1";


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