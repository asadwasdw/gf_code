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
    int n;cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int a1=sum/n;
   // cout<<a1<<endl;

    int num=sum%n;
    num=n-num;
    //cout<<num<<endl;
    sort(a+1,a+n+1);
    int ans = 0;

    for(int i=1;i<=n;i++){
        int t = a1;
        if(i>num)t++;
        //cout<<i<<" "<<t<<endl;
        ans+=abs(a[i]-t);
    }
    cout<<ans/2<<endl;

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