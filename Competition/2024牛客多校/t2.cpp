#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int n, k;
int a[N];
int cnt;

bool check() {
	int cnt = 0;
	for(int l = 1; l <= n; l ++) {
		for(int r = l + 1; r <= n; r ++) {
			string s;
			for(int i = l; i <= r; i ++) s += (char)(a[i] - '0');
			int len = r - l + 1;
			if(len % 2) continue;
			if(s.substr(0,len/2) == s.substr(len/2,len/2)) cnt ++;
		}
	}
	return cnt == k;
}

void dfs(int x) {
	if(x == n + 1) {
		if(check()){
			cnt ++;
			// for(int i = 1; i <= n; i ++) {
			// 	cout << a[i] << " \n"[i == n];
			// }
		}
		return;
	}

	a[x] = 0;
	dfs(x + 1);
	a[x] = 1;
	dfs(x + 1);
	a[x] = 2;
	dfs(x +1);
}


void solve()
{
	for(n = 1; n <= 6; n ++) {
		for(k = 0; k <= n * n; k ++) {
			cnt = 0;
			dfs(1);
            if(k > n && cnt)
			cout << n << " " << k << " " << cnt << endl;
		}
	}

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