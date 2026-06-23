#include<iostream>
#include<algorithm>


using namespace std;


void solve()
{
    int n;cin>>n;
    string s;
    cin>>s;
    int a=0;
    int ans=0;
    for(auto t:s)
    {
        if(t=='o')a++;
        if(t=='-')
        {
            ans=max(a,ans);
            a=0;

        }
        
    }

    reverse(s.begin(),s.end());

    a=0;
 
    for(auto t:s)
    {
        if(t=='o')a++;
        if(t=='-')
        {
            ans=max(a,ans);
            a=0;
        }
        
    }

    if(ans==0)ans=-1;
    cout<<ans<<endl;

}


int main()
{
   // int t=1;cin>>t;while(t--)
    solve();
    return 0;
}