#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[N];

void solve()
{
    int n, R, ans = 0;
    cin >> n >> R;
    deque<int> dq;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int cnt = 0;

    for(int i = R; i >= 1; i --) {
        if(a[i] == 1) cnt += 2;
        else {
            ans += cnt + 1;
            cnt = 0;
        }
    }

    cnt = 0;

    for(int i = R; i < n; i ++) {
        if(a[i + 1] == 1) cnt += 2;
        else {
            ans += cnt + 1;
            cnt = 0;
        }
    }


    cout << ans << endl;









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