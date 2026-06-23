#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
#define int long long
string a[N],b[N];
int f[N];
int find(int x) {
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}

int n;
vector<int>edg[N];

int ans = 0;



void solve(){
   
	int n; cin >> n;
    ans = n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> b[i];
        f[i] = i;
	}

    for(int i = 1; i <= n; i ++) {
		for(int j = 1;j <= n; j ++) {
			if(i == j) continue;
			if(a[i] == a[j] || b[i] == b[j]) 
			{
				int fi = find(i), fj = find(j);
				if(fi != fj) f[fi] = fj;
			}
		}
	}
	

    for(int st = 0; st < (1<<n);st ++ ) {
        vector<int>t;
        t.push_back(0);
        for(int j = 0; j < n; j ++) {
            if((st>>j) & 1) t.push_back(j + 1);
        }
        vector<int>d(n + 1);
        int c = 0;
        for(int i = 1; i < t.size(); i ++) {
            for(int j = i + 1; j < t.size(); j ++) {
                int x = t[i], y = t[j];
                if(find(x) != find(y))c = 3;
                if(a[i] == a[j] || b[i] == b[j]) {
                    d[x] ++;
                    d[y] ++;
                }
            }
        }

        for(int i = 1; i < t.size(); i ++) {
            if(d[t[i]]%2)c++;
        }
        if(c <= 2) {
            // cout << st << "\n";
            ans = min((int)(n - t.size() + 1), ans);
        }

    }
    cout << ans << endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}