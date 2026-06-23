#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

int ws(int x)
{
    int ans=0;
    while(x)
    {
        ans++;
        x/=10;
    }
    return ans;
}

void solve()
{
    int a,b;
    cin>>a>>b;
    if(ws(a)!=ws(b)){
        cout<<"-1"<<endl;
        return;
    }

    stack<int>s;
    while(a)
    {
        int t=(a%10)*(b%10);
        s.push(t);
        a/=10;
        b/=10;
    }

    while(s.size())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;


}



signed main()
{
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
    int t;cin>>t;while(t--)
    solve();
}