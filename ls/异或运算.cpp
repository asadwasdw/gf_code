#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
long long a[N];
#define int long long

void solve()
{
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int k = 0;
    for(int i=62;i>=0;i--) {
        for(int j=k;j<n;j++) {
            if(a[j]>>i & 1) {
                swap(a[k], a[j]);
                break;
            }
        }

        if((a[k] >> i & 1) == 0) {
            continue;
        }

        for(int j = 0; j < n; j++ ) { 
            if(j != k && (a[j]>>i & 1)) {
                a[j] ^= a[k];
            }
        }
        k++;
        if(k==n)break;
    }

    reverse(a,a+k);
    int q;
    cin >> q;
    
    while(q--) {
        int x;
        cin >> x;
        if(k < n) x--;
        if(x >= (1ll << k)) printf("-1\n");
        else {
            int res = 0;
            for(int i = 0;i < k; i++) {
                if(x >> i & 1) {
                    res ^= a[i];
                }
            }
            printf("%lld\n",res);
        }
    }


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        printf("Case #%d:\n",i);
        solve();
    }
}