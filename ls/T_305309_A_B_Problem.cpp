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
const ll P=99997;
//vector<vector<int>>adj(N);

ll a[6][N];

map<ll,bool> mp;

struct node{
	vector<ll> q[N];
	void clear(){
		for(int i=0;i<P;i++)q[i].clear();
	}
	void insert(ll x){
		ll y=(x % P + P) % P;
		q[y].push_back(x);
	}
	bool find(ll x){
		ll y=(x % P + P) % P;
		for(int i=0;i<q[y].size();i++){
			if(q[y][i] == x)return true;
		}
		return false;
	}
}mp2;


void solve()
{
    // mp.clear();
    mp2.clear();
    int n;
    cin >> n;
    for(int i = 1; i <= 5; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            ll t = a[1][i] + a[2][j];
            // mp[t] = 1;
            // cout << t << endl;
            mp2.insert(t);
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            for(int k = 1; k <= n; k ++) {
                
                ll t = a[3][i] + a[4][j] + a[5][k];
                // cout << " - " << t << endl;
                if(mp2.find(-t)) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }

    cout << "No\n";
    return;
    
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}