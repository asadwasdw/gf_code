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

void solve()
{
    int n;
    cin >> n;
    int l, r;
    cin >> l >> r;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    deque<int> q;
    int ans = -INF;
    for(int i = 1; i <= n; i ++) {
        int R1 = i - l, L1 = i - r;
        while(q.size() && R1 >= 0 && a[q.back()] >= a[R1]) {
            q.pop_back();
        }
        if(R1 >= 0) q.push_back(R1);
        if(q.size() && q.front() < L1) q.pop_front();

        if(q.size()) {
            ans = max(ans, a[i] - a[q.front()]);
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
    return 0;
}