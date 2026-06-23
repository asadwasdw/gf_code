#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<char,int>mp;


void solve()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;

    for(auto a:s)
    {
        mp[a]++;
       // cout<<a<<endl;
    }

    int ans=0;

    for(int i=0;i<26;i++)
    {
       
        char xx = 'a' + i;
        char dx=  'A' + i;
    

        int mid=(mp[xx]+mp[dx])/2;
        
        if(m>=mid-min(mp[xx],mp[dx]))
        {
            ans+=mid;
            m-=mid-min(mp[xx],mp[dx]);
        }
        else{
            ans+=m;
            m=0;
            ans+=min(mp[xx],mp[dx]);
        }
         mp[xx]=mp[dx]=0;
       // cout<<mid<<" "<<mp[xx]<<" "<<mp[dx]<<" "<<xx<<endl;cout<<ans<<" "<<m<<endl;

    }

    cout<<ans<<endl;
}

int main()
{
  int t;cin>>t;while (t--)
    {
        solve();
    }
    
}