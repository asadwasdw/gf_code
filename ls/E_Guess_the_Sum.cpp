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
int cnt = 0;
int ask(int i, int j) {
    int ans = 0;

    {
        int l = (1 << i) * j;
        int r = (1 << i) * (j + 1) - 1;

        for(int i = l; i <= r ; i ++) {
            ans += a[i];
        }

        // cout << l << " " << r << " " << ans << endl;
        return ans;
    }
    
    cout << "? "<< i << " " << j << endl;
    cin >> ans;
    return ans;
}

int js(int x) {
    if(x == -1) return 0;
    int ans = 0;
    while(x) {
        int t = x & -x;
        x -= t;
        int j = x / t, i = log2(t);
        ans += ask(i,j);
    } 
    return ans;
}


void solve()
{
    int n,l,r;
    cin >> n >> l >> r;
    for(int i = 0; i < (1 << n); i ++) {
        cin >> a[i];
    }



    // for(int i = 0; i < (1 << n); i ++) {
    //     cout << i << " " << js(i + 1) << endl;
    // }

    int ans = js(r + 1) - js(l); 
    cout << "! "<< (ans % 100 + 100) % 100 << endl;

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