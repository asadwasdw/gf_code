#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];
long double b[N];
void solve()
{
    int ans = 0;
    int n;cin>>n;
    for(int i= 1;i<=n;i++){
        cin>>a[i];
        b[i] = log2(a[i]);
    }

    for(int i =2;i<=n;i++){
        // while(b[i]<b[i-1]) {
        //     b[i]+=1;
        //     ans++;
        // }

        if(b[i]<b[i-1]){
            int t = 1 + (b[i-1]-b[i]) - (long double)0.000000001;
            ans += t;
            b[i] += t;
        }
        //cout<<b[i]<<" "<<ans<<endl;
    }
    cout<<ans<<endl;


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}