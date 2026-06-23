#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<vector>
#include<cstring>

using namespace std;



void solve()
{
    int z;cin>>z;
    int n=0,m=0;
    string s;cin>>s;

    for(auto t:s)
    {
        if(t=='o')n++;
        if(t=='x')m++;
    }
 //   cout<<n<<" "<<m<<endl;

    if(m){
        cout<<"No";
    }
    else if(n){
        cout<<"Yes";
    }
    else cout<<"No";

}


int main()
{
    //int t;cin>>t;while(t--)
    solve();
}