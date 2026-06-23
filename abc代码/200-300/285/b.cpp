#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

map<char,int>num;
void solve()
{

    int n;cin>>n;
    string s;cin>>s;
    s=" "+s;

    for(int i=1;i<n;i++)
    {
       int l=1;
       for(;l+i<=n;l++)
       {
           if(s[l]==s[l+i])break;
       }

       cout<<l-1<<endl;

    }


}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}