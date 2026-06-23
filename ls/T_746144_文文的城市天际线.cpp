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

ll a[N], h[N];

void solve()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> h[i];
	}

	stack<int> s;
	for(int i = 1; i <= n; i ++) {
		while(s.size() && h[s.top()] <= h[i]) {
			int l = s.top(); s.pop();
			int r = i;
			a[l + 1] ++, a[r] --;
			cout << l << " " << r << endl;
		}

		if(s.size()) {
			int l = s.top();
			int r = i;
			a[l + 1] ++, a[r] --;
			cout << l << " " << r << endl;
		}

		s.push(i);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		a[i] += a[i - 1];
		ans = max(a[i], ans);
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