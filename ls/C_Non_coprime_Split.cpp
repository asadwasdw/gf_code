#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


int js(int x)
{
    int n = sqrt(x)+1;
    for(int i=2;i<=n;i++){
        if(x%i==0)return i;
    }
    return 0;
}


void solve()
{
    int l,r;
    cin>>l>>r;
    if(r-l>=1)
    {
        int t ;
        if(r%2==0)t=r;
        else t=r-1;
        if(t>=4){
            cout<<t/2<<" "<<t/2<<endl;
        }
        else cout<<"-1\n";
    }
    else {

        int t = js(l);
        if(t==0||l==t)cout<<"-1\n";
        else cout<<l-t<<" "<<t<<endl;
    }

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