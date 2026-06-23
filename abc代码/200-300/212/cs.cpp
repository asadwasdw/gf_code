#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define debug(x) cout<<#x<<":"<<x<<endl;
#define dl(x) printf("%lld\n",x);
#define di(x) printf("%d\n",x);
#define _CRT_SECURE_NO_WARNINGS
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int N = 5010,M = N * N * 2;
const ll mod = 998244353;
const double eps = 1e-9;
const double PI = acos(-1);
template<typename T>inline void read(T &a) {
	char c = getchar(); T x = 0, f = 1; while (!isdigit(c)) {if (c == '-')f = -1; c = getchar();}
	while (isdigit(c)) {x = (x << 1) + (x << 3) + c - '0'; c = getchar();} a = f * x;
}
int gcd(int a, int b) {return (b > 0) ? gcd(b, a % b) : a;}
int h[N],e[M],ne[M],idx;
int n,m,k;
ll f[N][N];

void add(int a,int b){
	ne[idx] = h[a],e[idx] = b,h[a] = idx++;
}

int main() {
	memset(h,-1,sizeof h);
	read(n),read(m),read(k);
	while(m--){
		int a,b;
		read(a),read(b);
		add(a,b),add(b,a);
	}
	f[0][1] = 1;
	for(int i = 1;i <= k;i++){
		ll sum = 0;
		for(int j = 1;j <= n;j++) sum += f[i - 1][j];
		for(int j = 1;j <= n;j++){
			f[i][j] = sum - f[i - 1][j];
			for(int p = h[j];~p;p = ne[p]) f[i][j] -= f[i - 1][e[p]];
			f[i][j] %= mod;
		} 
	}
	dl(f[k][1]);
	return 0;
}

