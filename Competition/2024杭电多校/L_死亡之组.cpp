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


void solve()
{
    int n, l, d;
    cin >> n >> l >> d;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int t = a[1];
    sort(a + 1, a + n + 1);

    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] < l) cnt ++;
    }

    if(t >= l) {
        if(cnt < 3 || t - a[1] <= d) {
            cout << "No\n";
        }
        else cout << "Yes\n";
    }
    else {
        if(cnt < 3 || a[n] - a[1] <= d) {
            cout << "No\n";
        }
        else cout << "Yes\n";
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