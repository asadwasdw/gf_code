#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int st[N], p[N], cnt;

void qie_p(int n) {
    st[1] = true;
    for(int i = 2;  i <= n; i ++) {
        if(!st[i])  p[++cnt] = i;
        for(int j = 1; i * p[j] <= n && j <= cnt; j ++) {
            st[p[j] * i] = true;
            if(i % p[j] == 0) break; 
        }
    }
}
bool st2[N];

void solve()
{
    int n;
    cin >> n;
    qie_p(n);

    for(int i = 1; i <= cnt; i ++) {
        for(ll j = p[i]; j <= n; j *= p[i]) {
            st2[j] = true;
        }
    }

    int ans = 0;
    for(int i = 2; i <= n; i ++) {
        ans += st2[i] == false;
    }
    cout << ans;

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