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
	string a, b;
	cin >> a >> b;
	map<char,int> num, now;
	int n = a.size();
	a = " " + a;
	for(auto t : b) num[t] ++;

	int cnt = 0;

	auto check = [&](){
		for(char i = 'a'; i <= 'z'; i ++) {
			if(num[i] <= now[i]) cnt ++;
		}
	};
	
	check();
	long long l = 1, r = 0, ans = 0;
	for(;l <= n; l ++) {
		while(r <= n && cnt != 26) {
			now[a[++r]]++;
			if(now[a[r]] == num[a[r]]) cnt++;
		}
		ans += n - r + 1;
		// cout << l << "  " << r << endl;
		if(now[a[l]] == num[a[l]]) cnt--;
		now[a[l]]--;
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