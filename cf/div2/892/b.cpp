#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//https://codeforces.com/contest/1793/problem/B
void solve()
{
    int x,y;cin>>x>>y;

    vector<int>ans;

    for(int i=y;i<x;i++){
        ans.push_back(i);
    }
    for(int i=x;i>y;i--){
        ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto t:ans)cout<<t<<" ";
    cout<<endl;
    
}

int main()
{
    int t;cin>>t;while(t--)
    {
        solve();
    }
}