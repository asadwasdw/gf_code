#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int s[N][N], r[N], c[N], a[N][N];
void xz(int x, int y) {
  	s[x][y] ^= 1;
	r[x] += a[x][y], c[y] += a[x][y];
	a[x][y] *= -1;
}


void solve()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			char t; cin >> t;
			if(t == '+') a[i][j] = 1;
			else a[i][j] =  -1;
		}
	}

	for(int i = 0; i < n; i ++) cin >> r[i], r[i] = -r[i]; // 这一行还差几个1 最后满足就 = 0
	for(int i = 0; i < n; i ++) cin >> c[i], c[i] = -c[i];

	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			if(a[i][j] == 1) xz(i, j);
		}
	}

	for(int i = 0; i < n; i ++) {
		if(r[i] < 0 || c[i] < 0) {
			cout << "No\n";
			// 在选择了全部的+后， 数量依旧不够
			return;
		}
	}

	//先把所有"+"都选了，那么现在取消选择这个或者选了一个-，他们的贡献就是一样的

	vector<int> rr(n), cc(n);
	for(int i = 0; i < n; i ++) rr[i] = cc[i] = i;

	sort(rr.begin(), rr.end(),[&](int a, int b){
		return r[a] > r[b];
	}); // 先考虑多选了的中较多的，




	for(int i = 0; i < n; i ++) {
		sort(cc.begin(), cc.end(),[&](int a, int b){
			return c[a] > c[b];
		}); 
		int x = rr[i];

		for(int j = 0; j < n && r[x] > 0; j ++) {
			int y = cc[j];
			if(c[y] > 0) {
				// 取消选择
				xz(x, y);
			}
		}
	}

	
	for(int i = 0; i < n; i ++) {
		if(r[i] || c[i]) {
			cout << "No";
			return;
		}
	}

	cout << "Yes\n";
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			cout << s[i][j];
		}cout << endl;
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