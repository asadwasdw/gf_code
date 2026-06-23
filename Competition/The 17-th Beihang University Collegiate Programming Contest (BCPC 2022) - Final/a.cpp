#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


bool cmp(int a,int b)
{
    return a>b;
}

void solve()
{

    int n;cin>>n;

    vector<int>sc;

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(x%2)continue;
        sc.push_back(x);
       // cout<<x<<" ";
    }
   // cout<<endl;

    cin>>n;
    int num = 0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x%2){
            num++;
        }
    }

    sort(sc.begin(),sc.end(),cmp);
    

    //cout<<num<<endl;

    ll ans=0;
    for(auto t:sc){
        //cout<<t<<" "<<num<<endl;
        num--;
        if(num>=0)continue;

        //cout<<t<<endl;
        ans+=t;
    }

    cout<<ans<<endl;











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