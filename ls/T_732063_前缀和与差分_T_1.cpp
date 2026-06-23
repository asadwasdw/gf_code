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

int a[N], s[N];


bool check(int x) {
    if(x <= 1) return false;
    for(int i = 2; i * i <= x; i ++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n = 1e5;
    for(int i = 1; i <= n; i ++) {
        if(check(i)) {
            a[i] = 1;
        }

        s[i] = s[i - 1] + a[i];
        // cout << i << " " << a[i] << endl;
    } 

    int q;
    cin >> q;
    while(q --) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
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