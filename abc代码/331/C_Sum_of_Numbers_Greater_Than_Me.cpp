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
int b[N];
int c[N];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=b[i]=a[i];
    }
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);

    for(int i=1;i<=n;i++) {
        c[i]+=c[i-1];
    }

    for(int i=1;i<=n;i++)
    {
        int l = 1,r=n+1;
        while(l<r){
            int mid = l+r>>1;
            if(b[mid]>=a[i]+1) r = mid;
            else l = mid+1;
        }
        cout<<c[n]-c[l-1]<<" ";
    }







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