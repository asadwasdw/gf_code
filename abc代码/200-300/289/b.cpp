#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int N=110;
bool st[N];

long long a[N];

void solve()
{

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int t;cin>>t;
        st[t]=true;
    }
    stack<int>s;

    for(int i=1;i<=n;i++)
    {
        s.push(i);
        if(!st[i]){
            while(s.size()){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
    }




    
}


int main()
{
    //int t;cin>>t;while(t--)
    solve();
}