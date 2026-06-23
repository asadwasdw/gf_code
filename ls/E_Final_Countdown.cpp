#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N];
int b[N];

void solve()
{
    int n;
    cin>>n;
    // for(int i=1;i<=n;i++)cout<<b[i];cout<<endl;
    for(int i=0;i<=n+1;i++)b[i]=0;
    for(int i=1;i<=n;i++){
        char t;cin>>t;
        a[i]=t-'0';
        b[i]+=a[i];
        b[n+1]-=a[i];
    }
    for(int i=1;i<=n;i++)b[i]+=b[i-1];

    for(int i=n;i>=1;i--){
        b[i-1]+=b[i]/10;
        b[i]%=10;
    }

    bool ky =false;
    for(int i=0;i<=n;i++){
        if(b[i])ky=true;
        if(ky==false)continue;
        cout<<b[i];
    }
    cout<<endl;


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