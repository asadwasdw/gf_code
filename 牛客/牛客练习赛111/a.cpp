#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;


void solve()
{
    int t;cin>>t;
    stack<int>s;

    while(t%10==0)
    {
        s.push(0);
        t/=10;
    }

    cout<<10-t%10;
    while(s.size())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;

}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}