#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
// const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

const int N = 1010, K = 10010;
ll f[N][K], a[N], n, m, p, k[N];
void solve()
{
	cin >> n >> m >> p;
	for(int i = 1;i <= n;i++)  {
		cin >> a[i];
		a[i] %= p;
		k[i] = -1;
		int x = a[i], y = a[i], z = -1;
		for(int j = 3;j <= p * p + 2;j++){
			z = (x + y) % p;
			if(z == a[i] && y == a[i]){
				k[i] = j - 2;
				break;
			}
			x = y;
			y = z;
		}
	}
	
	for(int i = 1;i <= n;i++){
		f[i][1] = f[i][2] = a[i];
		for(int j = 3;j <= k[i];j++){
			f[i][j] = (f[i][j - 1] + f[i][j - 2]) % p;
		}
	}
	
	for(int i = 1;i <= n;i++) 
		for(int j = 1;j <= k[i];j++)
			f[i][j] += f[i][j - 1]; 
			
	int l = 0,r = m;
	while(l < r) {
		ll mid=(l + r + 1) >> 1;
		ll ans=0;
		for(int j = 1;j <= n;j++) {
			ans += mid / k[j] * f[j][k[j]] + f[j][mid % k[j]];
		}
		if(ans <= m) l = mid;
		else r = mid - 1;
	}
	cout << l;
}

ll A[110][10010],S[110][10010];
void solve2() {
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i ++) {
        cin >> A[i][1];
        A[i][1] %= p;
        A[i][2] = A[i][1];
        for(int j = 3; j <= 1e4; j ++) {
            A[i][j] = (A[i][j - 1] + A[i][j - 2]) % p;
        }

        for(int j = 1; j <= 1e4; j ++) {
            S[i][j] = S[i][j - 1] + A[i][j];
        }
    }

    ll res = 0;
    for(int j = 1; j <= 1e4 + 1; j ++) {
        for(int i = 1; i <= n; i ++) {
            res += A[i][j];
        }
        if(res > m) {
            cout << j - 1;
            return;
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
        solve2();
    }
    return 0;
}