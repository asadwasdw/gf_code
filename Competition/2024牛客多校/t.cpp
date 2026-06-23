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


void solve()
{
	int n, l, r;
	cin >> n >> l >> r;
	int cnt = 0;
	for(int i = l; i <= r; i ++) {
		int len = pow(10,n/2);
		int a = i/len, b = i%len;
		if(a < len/10) continue;
		if(b < len/10 && b != 0) continue;
		int sa = sqrt(a);
		int sb = sqrt(b);
		if(sa * sa == a && sb * sb == b) 
		{
			cout << i << endl;
			cnt++;
		}
		// cout << a << " " << b << endl;
	}

	cout << cnt << endl;







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