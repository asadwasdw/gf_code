#include "bits/stdc++.h"
using namespace std;

const char nl = '\n';
using ll = long long;


const int N = 1000 + 5;
int l[N], r[N];
bool iset[N];
bool vis[N];
bool adj[N][N];
int n;
bool sat(int k, int v){
	vis[k] = 1;
	iset[k] = v;
	for(int i = 1; i <= n; i++){
		if(adj[k][i]){
			if(vis[i]){
				if(iset[i] == v) return 0;
			}else if(!sat(i, !v)){
				return 0;
			}
		} 
	}
	return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	for(int i = 1; i <= 2 * n; i++){
		int x;
		cin >> x;
		if(x > 0) l[x] = i;
		else r[-x] = i;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(l[i] <= l[j] && r[i] >= l[j] && r[i] <= r[j]) adj[i][j] = adj[j][i] = 1;
            if(adj[i][j] && i < j) cout << i << " " << j << endl;
		}
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		if(!sat(i, 0)){
			cout << "*" << nl;
			exit(0);
		}
	}
	for(int i = 1; i <= n; i++){
		if(iset[i]) cout << 'G';
		else cout << 'S';
	}
	cout << nl;
}