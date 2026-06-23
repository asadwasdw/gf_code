// Problem: 齐次递推公约数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/68774/J
// Memory Limit: 524288 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
typedef double db;
typedef pair<ll,int> P;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr<<(#x)<<":"<<x<<" ";
#define dbg2(x) cerr<<(#x)<<":"<<x<<endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d",&(a))
#define scll(a) scanf("%lld",&(a))
#define pt(a) printf("%d",a);
#define pte(a) printf("%d\n",a)
#define ptlle(a) printf("%lld\n",a)
#define debug(...) fprintf(stderr, __VA_ARGS__)]
const int N=3e6+10,mod=1e9+7;
int t,n,f[N],res;
ll cnt[N];
void sol(){
	sci(n);
	f[1]=1;
	rep(i,2,n){
		f[i]=(3ll*f[i-1]%mod+2ll*f[i-2]%mod)%mod;
	}
	per(i,n,1){
		int tot=1;
		for(int j=2*i;j<=n;j+=i){
			cnt[i]-=cnt[j];
			tot++;
		}
		cnt[i]+=1ll*tot*tot;
		res=(res+1ll*cnt[i]%mod*f[i]%mod)%mod;
	}
	pte(res);
	// int res2=0;
	// for(int i=1;i<=n;++i){
		// for(int j=1;j<=n;++j){
			// res2=(res2+__gcd(f[i],f[j]))%mod;
		// }
	// }
	// pte(res2);
}
int main(){
	t=1;
	while(t--){
		sol();
	}
	return 0;
}