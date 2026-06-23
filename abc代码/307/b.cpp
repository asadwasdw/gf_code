#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


const int N =110;

string s[N];


bool pd(string a)
{
    for(int i=0;i<=a.size()/2;i++)
    {
        if(a[i]!=a[a.size()-1-i])return false;
    
    }
    return true;


}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(pd(s[i]+s[j])){
                cout<<"Yes";
                return;
            }
        }
    }
    cout<<"No";
    return ;

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