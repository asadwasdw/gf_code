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
map<PII,vector<int>>mp;

void init() {
	for(int n = 1; n <= 8; n ++) {
		for(int i = 1; i <= n; i ++) a[i] = i;

		do{
			int cnt = 0;
			for(int i = 1; i + 2 <= n; i ++) {
				vector<int> v;
				v.push_back(a[i]);
				v.push_back(a[i + 1]);
				v.push_back(a[i + 2]);
				sort(v.begin(),v.end());
				if(v[0]+v[1]>v[2])cnt++;
			}
			if(mp[{n, cnt}].size() == 0) {
				for(int i = 1; i <= n; i ++) {
					mp[{n, cnt}].push_back(a[i]);
				}
			}

		}while(next_permutation(a + 1, a + n + 1));
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	// if(n <= 8) {
	// 	if(mp[{n,m}].size()) {
	// 		for(auto t : mp[{n,m}]) {
	// 			cout << t << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	else {
	// 		cout << "-1" << endl;
	// 	}
	// 	return;
	// }


	for(int i = 0; i <= n + 10; i ++) a[i] = 0;
	if(m + 3 > n) {
		cout << "-1" << endl;
		return;
	}

	int now = 0;
	int i = 2, j = n;
	vector<int>id;
	vector<int>id2;
	while(now + m + 3 != n) {
		++now;
		if(now % 3) {
            if(now % 3 == 2) id2.push_back(now);
			a[now] = i ++;
		}
		else {
			id.push_back(now);
			a[now] = j --;
		}
	}

    int tnow = now;

	now++;
	a[now] = 1;
	
	for(int z = i; z <= j; z ++) {
		a[++now] = z;
	}

	{
		int l = 0, r = id2.size() - 1;
		while(l < r) {
            if(a[id2[l]] && a[id2[r]]) swap(a[id2[l]], a[id2[r]]);
			l ++, r--;
		}
	}

	{
		int l = 0, r = id.size() - 1;
        // cout << id.size() << endl;
		while(l < r) {
			if(a[id[l]] && a[id[r]]) swap(a[id[l]], a[id[r]]);
			l ++, r--;
		}
	}
// for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
    for(int i = 1; i + 1 <= tnow; i += 3) {
        if(a[i] && a[i + 1] && a[i] < a[i + 1]) swap(a[i], a[i + 1]);
    }



	int cnt = 0;
	for(int i = 1; i + 2 <= n; i ++) {
		vector<int> v;
		v.push_back(a[i]);
		v.push_back(a[i + 1]);
		v.push_back(a[i + 2]);
		sort(v.begin(),v.end());
		if(v[0]+v[1]>v[2])cnt++;
	}
	assert(cnt == m);
    // cout << cnt << " " << m << endl;

	for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
}


signed main()
{
	init();
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cout << setprecision(11) << fixed;
	int t;t=1;
	cin>>t;
	for(int i=1;i<=t;i++){
		//printf("Case %d: ",i);
		solve();
	}
}