#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 50;

int n, len[maxn], sum[maxn], fsum[maxn];
int f[maxn], fa[maxn];
bool tb[maxn], ta[maxn], tc[maxn];
vector<int> ss[maxn];

int ask(int x){
	if(sum[x]) return 0;
	if(tb[x]) return len[x];
	tb[x] = true;
	len[x] = ask(f[x]) + 1;
	return len[x];
}

int fdfs(int x){
	int ans = 0;
	if(sum[x])ans++;
	tc[x] = true;
	for(int c : ss[x]){
		if(tc[c]) continue;
		ans += fdfs(c);
	}
	return ans;
}
void dfs(int x, vector<int> &v){
	if(ta[x])return;
	ta[x] = true;
	v.push_back(len[x]);
	for(int c : ss[x])	if(!ta[c])dfs(c, v);
}

void solve(){
	cin >> n;
	int x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		ss[x].push_back(i);
		ss[i].push_back(x);
		f[i] = x;
		sum[x]++;
	}
	queue<int> qu;
	for(int i = 1; i <= n; i++){
		if(sum[i] == 0)
			qu.push(i);
	}
	while(!qu.empty()){
		x = qu.front(); qu.pop();
		if(-- sum[f[x]] == 0)qu.push(f[x]);
	}
	int tk = 0;
	vector<vector<int> >ve;
	map<int,int> ma;
	for(int i = 1; i <= n; i++){
		if(sum[i])tk++;
		else ask(i);
	}
	for(int i = 1; i <= n; i++){
		if(ta[i])continue;
		int tk = fdfs(i);
		if(ma.find(tk) == ma.end()){
			vector<int> v; v.clear();
			ve.push_back(v);
			ma[tk] = ve.size() - 1;
			fsum[ve.size() - 1] = tk;
		}
		dfs(i, ve[ma[tk]]);
	}
	for(auto &v : ve)sort(v.begin(), v.end());
	int m;cin >> m;
	while(m--){
		ll a, b;
		cin >> a >> b;
		if(a == b)cout << n << '\n';
		else {
			if(a > b)swap(a, b);
			int ans = 0;
			for(int i = 0; i < ve.size(); i++){
				vector<int> &v = ve[i];
				if((b - a)%fsum[i] == 0){
					ans += upper_bound(v.begin(), v.end(), a) - v.begin();
				}
			}
			cout << ans << '\n';
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--)solve();
}
