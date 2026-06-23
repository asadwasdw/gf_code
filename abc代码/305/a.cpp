#include<iostream>
#include<algorithm>

using namespace std;

int main()
{

    int x;
    cin>>x;

    int t=x/5;
    int x1=t*5;
    int x2=(t+1)*5;    
    if(x2-x<3&&x2!=105)cout<<x2;
    else cout<<x1;

}