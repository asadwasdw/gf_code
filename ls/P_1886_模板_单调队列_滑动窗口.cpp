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
int ans1[N], ans2[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    deque<int> mx, mn;

    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int i = 1; i <= n; i ++) {
        while(mx.size() && a[mx.back()] <= a[i]) {
            mx.pop_back();
        }
        mx.push_back(i);
        if(mx.front() <= i - m) mx.pop_front();

        ans1[i] = a[mx.front()];

        while(mn.size() && a[mn.back()] >= a[i]) {
            mn.pop_back();
        }
        mn.push_back(i);
        if(mn.front() <= i - m) mn.pop_front();

        ans2[i] = a[mn.front()];
    }

    for(int i = m; i <= n; i ++) cout << ans2[i] << " \n"[i == n];
    for(int i = m; i <= n; i ++) cout << ans1[i] << " \n"[i == n];
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