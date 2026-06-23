#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];

#define PRIME_LIM 1000000000
#define N 1000000000

int primes[PRIME_LIM] = {0};
int flags[N/96 + 1] = {0};

int get_prime()
{
    int nu = 5, to = 0;
    primes[0] = 2;
    primes[1] = 2, primes[2] = 3;
    for(int i = 0; nu <= N; i++) {
        if(!(flags[i>>5]&(1<<(i&31)))) primes[++primes[0]] = nu;
        for(int j = 3; j <= primes[0] && primes[j] * nu <= N; j++) {
            to = (nu * primes[j] - 5) >> 1;
            to -= to/3;
            flags[to>>5] |= 1<<(to&31);
            if(!(nu % primes[j])) break;
        }
        nu += 2 + ((i&1) << 1);
    }
    return primes[0];
}

void solve()
{
    cout << get_prime();
    


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