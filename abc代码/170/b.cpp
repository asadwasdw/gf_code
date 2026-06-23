#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    bool ky=true;
    int a,b;cin>>a>>b;

    if(b>4*a||b<2*a)ky=false;

    if(b%2)ky=false;

    if(ky)cout<<"Yes";
   else cout<<"No";

}