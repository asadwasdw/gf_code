#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

const int N=2e5+10;


void solve()
{
    int n;cin>>n;
    stack<int>s;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        int mx=x;
        while(s.size()!=0&&s.top()>x)
        {
            mx=max(mx,s.top());
            s.pop();
            
        }
        s.push(mx);
    }

    cout<<s.size()<<endl;
    
}


int main()
{
    int t;cin>>t;while(t--)
    solve();

}