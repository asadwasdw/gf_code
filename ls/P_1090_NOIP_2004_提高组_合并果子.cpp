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


void solve()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > q;
    while(n --) {
        int x; cin >> x;
        q.push(x);
    }
    int ans = 0;
    while(q.size() >= 2) {
        int a = q.top();q.pop();
        int b = q.top();q.pop();
        ans += a + b;
        q.push(a + b);
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