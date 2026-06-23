#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define int long long
vector<vector<int>>edg(N);


int js(int s) 
{
	int res = 0;
	while(s) {
		s -= s&-s;
		res++;
	}
	return res;
}
int a[N], b[N];
int dp[(1ll<<22)+1];


void solve()
{
	int n, c;
	cin >> n >> c;

	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];

	memset(dp, 0x3f, sizeof dp);
	dp[0] = -c;

	for(int s = 0; s < (1ll<<n); s++) {
		int i = js(s);
		for(int j = 1; j <= n; j++) {
			int S = s, sum = 0;
			for(int len = 1; len + i <= n && len + j - 1<= n; len++) {
				int aend = i + len, bend = j + len - 1;
				if((s>>(bend - 1)) & 1) break;
				sum += abs(a[aend] - b[bend]);
				S |= (1ll << (bend - 1));
				dp[S] = min(dp[S], dp[s] + sum + c);
			}
		}
	}

	cout << dp[(1ll << n) - 1] << endl;


}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;t=1;
	//cin>>t;
	for(int i=1;i<=t;i++){
		//printf("Case %d: ",i);
		solve();
	}
}
