#include<algorithm>
#include<iostream>

using namespace std;


int main()
{
    long long x;
    cin>>x;
    int t;
    while(x)
    {
        x>>=1;
        t++;
    }
    cout<<t-1;
}