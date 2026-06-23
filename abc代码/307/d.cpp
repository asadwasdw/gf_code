#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{

    int n;cin>>n;
    stack<char>s;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='('){
            num++;

            s.push(c);
        }
        else if (c==')')
        {
            if(num){
                while(s.top()!='(')s.pop();
                s.pop();
                num--;
            }
            else {
                s.push(c);
            }
            
        }
        else s.push(c);
    }

    stack<char>ans;
    while(s.size())
    {
        ans.push(s.top());
        s.pop();
    }

    while(ans.size()){
        cout<<ans.top();
        ans.pop();
    }
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