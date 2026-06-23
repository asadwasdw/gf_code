#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


int a[N];
int cnt[N];
void solve()
{


    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i ++) {
        cnt[0] ++;
    }

    int k = 1;

    for(int i = 1; i <= q; i ++) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            a[x] ++;
            cnt[a[x]] ++;
            if(cnt[k] == n) k ++;
        } else {
            cout << cnt[x + k - 1] << endl;
        }
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
    return 0;
}