#include<iostream>
#include<algorithm>

using namespace std;

void solve()
{
    long long n,x,y;cin>>n>>x>>y;
    x^=y;

    for(int i=1;i<=n;i++)
    {
        long long  t;cin>>t;
        x^=t;
    }
  //  cout<<x<<" ";
    if(x%2==0){
        cout<<"Alice"<<endl;
    }
    else cout<<"Bob"<<endl;
}

int main()
{
    int t;cin>>t;while(t--)
    solve();
}