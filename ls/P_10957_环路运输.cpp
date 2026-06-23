#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

long long a[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    deque<int> q;
    long long ans = 0;
    for(int i = 1; i <= n * 2; i ++) {
        while(q.size() && i - q.front() > n / 2) q.pop_front();
        
        if(q.size()) {
            // cout << i << " " << q.front() << " " << a[i] + i + a[q.front()] - q.front() << endl;
            ans = max(ans, a[i] + i + a[q.front()] - q.front());
        }
        
        while(q.size() && a[i] - i >= a[q.back()] - q.back()) q.pop_back();
        q.push_back(i);
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