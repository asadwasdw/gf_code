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
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) a[i] = i;

	do{
		int cnt = 0;
		for(int i = 1; i + 2 <= n; i ++) {
			vector<int> v;
			v.push_back(a[i]);
			v.push_back(a[i + 1]);
			v.push_back(a[i + 2]);
			sort(v.begin(), v.end());
			if(v[0] + v[1] > v[2]) cnt ++;
		}

		if(cnt == m) {
			for(int i = 1; i <= n; i ++) {
				cout << a[i] << " \n"[i == n];
			}
			return;
		}
	}
	while(next_permutation(a + 1, a + n + 1));

}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cout << setprecision(11) << fixed;
	int t;t=1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		//printf("Case %d: ",i);
		solve();
	}
}