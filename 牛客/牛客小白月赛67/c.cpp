#include<iostream>
#include<algorithm>

using namespace std;

double js(double x,double y,int t){
    return y/x*t;
}

void solve()
{
    int b,x,y;cin>>b>>x>>y;
    double t=b;
    
    if(x<t/2)
    {
        x+=b-2*x;
    }

    for(int i=(b-1)/2;i<=x+1;i++)
    {
        if(abs(2*i*js(x,y,i)-b*y)<1e-6){
            cout<<"YES"<<endl;
            return ;
        }

        //cout<<i<<" "<<js(x,y,i)<<endl;
    }

    cout<<"NO"<<endl;


}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}