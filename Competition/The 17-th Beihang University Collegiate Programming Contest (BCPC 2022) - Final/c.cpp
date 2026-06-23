#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


void solve()
{


    int n;
    cin>>n;

    if(n==1){
        cout<<"2\n2 1";
    }
    else 
    {
        cout<<3<<endl;
       // cout<<"2 0 2\n";

       cout<<n-1<<" "<<n<<" "<<0<<endl;
       cout<<n<<" 0 "<<n<<endl;

       for(int i=3;i<=n;i++)
       {
            cout<<i<<" "<<i<<" "<<i<<endl; 
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