#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

	#define fo(i,a,b) for(int i=a;i<=b;i++)
using i64 = long long;



bool isprime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int findPrime(int n) {
    while (!isprime(n)) {
        n++;
    }
    return n;
}

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int n,m;
int a[N];

int js(char t) {
    int res = 0;
    if('0'<= t && t <= '9') res = t - '0';
    else if('a' <= t && t <= 'z') res = t - 'a' + 10;
    else res = t - 'A' + 36;
    return res; 
}

ll calc(string s) {
    int res = 0;
    ll p = 1;
    reverse(s.begin(), s.end());
    for(auto t : s) {
        res += p * js(t);
        p *= 62;
    }
    return res;
}

typedef unsigned long long ull;
ull p[N],h[N];
const ull P = 1e9 + 11;

void init() {
    p[0] = 1;
    for(int i = 1; i <= n; i ++) {
        h[i] = h[i - 1] * P + a[i];
        p[i] = p[i - 1] * P;
    }
}

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int ans[N];
	bool check(int l,int k)
	{
		return (get(1,l-2*k)+get(2*k+1,l))==2*get(k+1,l-k);
	}

void solve()
{
 
    cin >> n;
    for(int i = 1; i <= n; i ++ ) {
        string s; cin >> s;
        a[i] = calc(s);
    }

    init();


  	for(int k=1;2*k+1<=n;k++) if(check(2*k+1,k))
		{
			int l=2*k+1,r=n;
			while(l<r)
			{
				int mid=l+r+1>>1;
				if(check(mid,k)) l=mid;
				else r=mid-1;
			}
			// cout<<k<<' '<<l<<endl;
			ans[2*k+1]++,ans[l+1]--;
		}

		fo(i,1,n) ans[i]+=ans[i-1];
		fo(i,1,n) cout << ((int)(ans[i]>0));

    // int r = 3;
    // vector<int> res(n+1);
    // // cout << get_ha(1, 1) + get_ha(3, 3) << ' ' << get_ha(2, 2)*2 << endl;
    // for(int i=1; i<=(n-1)/2; ++i){
    //     while(r < i*2+1)++r;
    //     while(r <= n && get(1, r - i*2) + get(1 + i*2, r) == get(1+i, r - i) * 2){
    //         res[r] = 1;
    //         ++r;
    //     }
    // }
    // for(int i=1; i<=n; ++i)cout << res[i];

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