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



int ef(int L,int R,int x)
{
    
    int l = L;
    int r = R;

    while(l<r)
    {
        int mid = l+r>>1;
        if(a[mid]-a[L-1]>=x)r=mid;
        else l=mid+1;
    }

    if(a[l]-a[L-1]==x){
        return l;
    }

    return -1;
}



void solve()
{
    int n,p,q,r;
    cin>>n>>p>>q>>r;

    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++)a[i]+=a[i-1];

    //cout<<ef(1,n,4)<<endl;


    for(int i=1;i<=n;i++)
    {

        if(a[i]<(p+q+r))continue;
        int a0 = ef(0,i,a[i]-(p+q+r));
        if(a0==-1)continue;

        int a1=ef(a0+1,i,p);
        if(a1==-1)continue;

        int a2=ef(a1+1,i,q);
        if(a2==-1)continue;
        //cout<<a1<<" "<<a2<<endl;
        if(a[i]-a[a2]==r){
            cout<<"Yes"<<endl;
            return;
        }
    }

    cout<<"No"<<endl;

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