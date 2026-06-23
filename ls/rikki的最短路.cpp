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
    int t,a,k;
    cin>>t>>a>>k;
    if(t*a>=0){
        t=abs(t);
        a=abs(a);
        if(a<=t){
            cout<<t<<endl;
        }
        else {
            cout<<a+(a-t)<<endl;
        }
    }
    else {
        if(t<0){
            t=-t;
            a=-a;
        }

        if(a<-k){
            cout<<3*t+2*(-a)<<endl;
        }
        else {
            cout<<2*(-a)+t<<endl;
        }
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