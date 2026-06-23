#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10;
int s[N];

int main()
{
    s[0]=0;
    s[1]=3;
    s[2]=4;
    s[3]=8;
    s[4]=9;
    s[5]=14;
    s[6]=23;

    char a,b;
    cin>>a>>b;
    int x=a-'A';
    int y=b-'A';
   // cout<<x<<y<<endl;

    cout<<abs(s[y]-s[x])<<endl;

}