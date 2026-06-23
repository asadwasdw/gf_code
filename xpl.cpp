#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1e6 + 10;
int st[N],primes[N],cnt;
int s[N];
// int phi[N];
vector<int> mp[N];

void phi(){
    int n=N-1;
    for(int i=2; i<=n ; i++){
        if(!st[i]){
            primes[++cnt] = i;
        }

        for(int j=1 ; j<=cnt && primes[j]*i <=n ; j++){
            st[primes[j] * i]=1;
            if(i%primes[j] == 0) {
                st[i*primes[j]]=1;
                break;
            }
        }
    }
    primes[0] = 1;
}



void solve () {
    int op, x, k, n;
    cin >> op;
    if ( op == 1 ) {
        cin >> n >> x;
        int ans = 0;
        while ( st[x] ) { // 非质
            x -= s[x];
            ans += s[n];
            n -= s[n];
        }
        cout << ans + s[x] << '\n';

    } else if ( op == 2 ) {
        cin >> n >> k;
        int ans = 0;
        int round = 1;
        while ( k > s[n] ) {
            
            k -= s[n];
            n -= s[n];
            round++;
        }
        k--;
        //cout << round << ' ' << k << '\n';
        cout << mp[round][k] << '\n';
    }
}

signed main(){

    phi();
    for(int i=1 ; i<N ; i++){
        if(!st[i]){
            s[i]=1;
        }
        s[i]+=s[i-1];
        // printf("%d %d\n",i,s[i]);
    }

    for ( int i=1; i<=1e6; i++ ) {
        int ans = 0;
        int n = 1e6;
        int round = 1;
        int v = i;
        while ( st[v]) { // 非质
            v -= s[v];
            ans += s[n];
            n -= s[n];
            round++;
        }
        mp[round].push_back(i);
    }

    // for ( int i=1; i<=2; i++ ) {
    //     for ( int j=0; j<4; j++ ) {
    //         cout << mp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int t; cin >> t;
    while ( t-- ) {
        solve();
    }
}
	

