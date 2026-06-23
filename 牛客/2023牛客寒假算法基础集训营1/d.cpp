#include<iostream>
#include<algorithm>

using namespace std;

void solve()
{
    double x,y,X,Y;
    cin>>x>>y>>X>>Y;
    if(X<=x&&Y<=y)
    {
        double t=X*Y;
        t=max(t,(x-X)*Y);
        t=max(t,(x-X)*(y-Y));
        t=max(t,X*(y-Y));
       // cout<<t<<" "<<x*y<<" ";
        cout<<t/(x*y)<<endl;
    }
    else if(X>x&&Y>y)
    {
        cout<<(x*y)/(X*Y)<<endl;
    }
    else {
        if(X>x)
        {
            double sum1=x*y+Y*(X-x);
            double sum2=x*y+(X-x)*(y-Y);
            double mj1=x*Y;
            double mj2=x*(y-Y);
            cout<<max(mj1/sum1,mj2/sum2)<<endl;
        }
        else {
            double sum1=x*y+(Y-y)*X;
            double sum2=x*y+(Y-y)*(x-X);
            double mj1=y*X;
            double mj2=y*(x-X);
            cout<<max(mj1/sum1,mj2/sum2)<<endl;
        }

    }
}

int main()
{
    int t;cin>>t;while(t--)
    solve();
}