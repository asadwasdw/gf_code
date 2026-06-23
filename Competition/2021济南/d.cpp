
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const ll inf = 1e13 + 10;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N], b[N];

ll ksxz(ll  l,ll  r,ll  k) {
	if (l >= r)
		return b[k];
	ll  L = l - 1;
	ll  R = r + 1;
	ll  x = b[(l+r)/2];
	while (L < R)
	{
		do { L++; } while (b[L] < x);
		do { R--; } while (b[R] > x);
		if (L < R)
		{
			ll temp = b[L];
			b[L] = b[R];
			b[R] = temp;
		}
	}

    if (k <= R) return ksxz(l, R, k);
    else return ksxz(R + 1, r, k);
}


void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    auto check1 = [&](ll d) -> __int128_t {

        __int128_t res = 0;

        for(int i = 1; i <= n; i ++) {
            b[i] = a[i] - d * (i - 1);
        }

        ll t = ksxz(1, n, (n + 1)/2);

        for(int i = 1; i <= n; i ++) {
            res += abs(t - b[i]);
        }
        return res;
    };

    int dl = -inf, dr = inf; 
    __int128_t res = INFll;
    while(dr - dl > 3) {
        ll mid1 = (dr - dl) / 3 + dl;
        ll mid2 = (dr - dl) / 3 * 2 + dl;

        if(check1(mid1) > check1(mid2)) dl = mid1;
        else dr = mid2;
    }

    for(ll i = dl; i <= dr; i ++) res = min(check1(i),res);
    cout << (ll)res << endl;
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