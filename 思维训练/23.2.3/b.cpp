#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e9+7;

int main()
{
    int n;
    cin>>n;
    long long a=1,b=1;
    

    for(int i=1;i<n;i++)
    {
        a=(a*i)%N;
        b*=2;
        b%=N;
    }
    a=(a*n)%N;
    cout<<(a-b+N)%N<<endl;

}