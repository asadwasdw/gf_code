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


int a[N];

void solve()
{
    int n,d,p;
    cin>>n>>d>>p;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    int ans = 0;
    int res = 0;
    int t= d;
    int i;
    int l=n+1;
    for(i=n;i>=1;i--)
    {
        t--;
        res += a[i];
        if(t==0)
        {
            t=d;
            
            if(res>=p){
                ans+=p;
                res = 0;
                l=i;
            }
            else {
                break;
            }
        }
    }

    if(i==0){
        if(res > p){
            ans+=p;
            l=0;
        }
    }
    //for(int i=1;i<=n;i++)cout<<a[i]<<endl;

    for(int j=1;j<l;j++){
        ans+=a[j];
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