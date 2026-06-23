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

ll qmi(ll a,ll b,ll c)
{
    ll res = 1;
    while(b){
        if(b&1)res = res*a%c;
        b>>=1;
        a=a*a%c;
    }
    return res;
}

int a[N];
int s[N];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char t;cin>>t;
        a[i]=t-'0';
    }

    for(int i=1;i<=n;i++){
        bool ky = false;
        for(int j=-1;j<=1;j++){
            if(a[min(n,max(1ll,i+j))]==1){
                ky=true;
            }
        }
        if(!ky){
            cout<<"-1"<<endl;
            return;
        }
    }



    int hh = 0;
    for(int i=n;i>1;i--)
    {
        // if(a[i]==1){
        //     hh++;
        // }
        // else {
           // hh +=qmi(a[i],max(hh,1ll),mod);

        //    if(i==n){
        //         hh=a[i];
        //    }
        //    else
            hh += (a[i]-1)*(hh+1)%mod+1%mod;
        //}
        hh%=mod;
        //cout<<i<<" "<<hh<<endl;

    }

    cout<<hh<<endl;

    




    







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