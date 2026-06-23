#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{
    map<int,map<int,int>>mp;
   ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(mp.count(x))
        {
            for(auto t:mp[x])
            {
                int b=t.first;
                if(b>=0)b=-(b+1);
                else b=-(b-1);
                mp[x+b][b]=max(mp[x][t.first]+1,mp[x+b][b]);
                ans=max(t.second+1,ans);
            }
        }
        else if(!mp.count(x+1))mp[x+1][1]=1;
    }

    cout<<ans<<endl;
    {
        
    }

}



signed main()
{
     
    /*多组案例初始化*/
    //int t;cin>>t;while(t--)
    solve();
}