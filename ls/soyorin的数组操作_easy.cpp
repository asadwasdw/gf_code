#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

ll a[N];
__int128 b[N];
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n%2==0||n==1){
        cout<<"YES\n";
        return;
    }

    bool ky = true;

    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }

    __int128 cnt = 0;
    for(__int128 i=n;i>=2;i--) {
        b[i]+=i*cnt;
        if(i%2){
            cnt=max(cnt,(b[i]-b[i-1])/(i-1));
        }
    }

    for(int i=1;i<n;i++){
        if(b[i]>b[i+1])ky=false;
    }


    
    // for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;

    if(ky)cout<<"YES\n";
    else cout<<"NO\n";

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