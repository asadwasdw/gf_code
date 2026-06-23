#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    double x;
    double l,r;
    cin>>x>>l>>r;

    cout<<min((double)1,max(x-l,(double)0)/(r-l+1))<<endl;
}