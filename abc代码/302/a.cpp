#include<iostream>
#include<algorithm>
#include<map>


using namespace std;

int main()
{
    long long a,b;
    cin>>a>>b;
    int t=a%b;
    if(t)t=1;
    cout<<a/b+t<<endl;
}