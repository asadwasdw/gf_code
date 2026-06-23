#include<iostream>
#include<algorithm>

using namespace std;

void solve()
{
   string s;
   cin>>s;
   for(auto t:s)
   {
    if(t=='0')cout<<"1";
    else cout<<"0";
   }    
    
}


int main()
{
 //   int t;cin>>t;while(t--)
    solve();
}