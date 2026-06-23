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

bool cmp(int a,int b){
    return a<b;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }

    while(q--){
        int x;cin>>x;
        int l =0,r=n;
        while(l<r){
            int mid = (l+r+1)>>1;
            if(a[mid]<=x)l=mid;
            else r=mid-1;
        }
        cout<<r<<endl;
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