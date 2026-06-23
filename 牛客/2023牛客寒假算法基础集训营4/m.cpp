#include<iostream>
#include<algorithm>

using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
    int n;
    cin>>n;
    a[1]=1;
    a[2]=1;
    a[3]=2;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i%3+1]<<" ";
    }


}