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


void solve()
{
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int t;cin>>t;
        sum+=t;
    }
    int ans = 0;

    if(n==1){
        cout<<"1";
        return;
    }
    
    for(int i=1;i*n<=sum;i++) {
        if((sum-i*n)%i==0) {
            ans++;

            for(int j=1;j<=n;j++){
                int t=i;
                if(j==n)t+=(sum-i*n);
                // cout<<t<<" ";
            }
            // cout<<endl;
        }
        
    }
    cout<<ans<<endl;







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}