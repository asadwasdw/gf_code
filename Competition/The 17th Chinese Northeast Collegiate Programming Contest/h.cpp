#include<iostream>
#include<algorithm>
#include<cmath>



using namespace std;


void solve()
{
        double n,num,d;
    scanf("%lf%lf%lf",&n,&num,&d);

    double x,y;

    x= n/((num-1)*sqrt(2)*2+2);

    x=d/x/x;

    printf("%.8lf\n",x);
}

int main()
{
    int t;cin>>t;while(t--)
    solve();
}