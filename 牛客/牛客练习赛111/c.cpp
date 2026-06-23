#include<iostream>
#include<algorithm>

using namespace std;


int main()
{

    int t;cin>>t;
    while(t--)
    {

    
    int m,x;cin>>m>>x;

    int l=m/x;
    int r =l+1;

    //cout<<l<<" "<<r<<endl;

    cout<<m/l-m/(r)<<endl;
    }
}