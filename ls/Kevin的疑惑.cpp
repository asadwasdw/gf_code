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
    int num = 0;
    int l,r,k;
    cin>>l>>r>>k;
    num=r-l+1;
   
    if(num%2==1 && l%2){
        num = (num+1)/2;
    }
    else num=num/2;

    if(k==0) {
        cout<<(r-l+1)%2<<endl;
    }
    else cout<<num%2<<endl;
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