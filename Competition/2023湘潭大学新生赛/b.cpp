#include<iostream>
#include<algorithm>

using namespace std;


void solve()
{
    long long a,b,c;
    cin>>a>>b>>c;

    if(c==0)
    {
        cout<<0<<endl;
        return;
    }

    if(a>b)
    {
        long long t=(c/2)*(a+b)-a+b;
        if(c%2!=0)
        {
            t+=a;
        }
        cout<<t<<endl;
    }
    else {
        cout<<c*b<<endl;   
    }


}

int main()
{
    int t=1;cin>>t;while(t--)
    solve();
    return 0;
}