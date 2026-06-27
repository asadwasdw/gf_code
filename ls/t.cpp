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
	ll sum = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	ll res = 0;
	cin >> res;
	for(int i = 1; i <= n; i ++) {
		if(sum - 2 * a[i] == res) {
			cout << i << " ";
		}
	}
	cout << endl;






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