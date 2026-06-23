#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>mul (vector<int>a,int b)
{

    vector<int>c;
    int T=0;
    for(auto t:a)
    {
        T+=t*b;
        c.push_back(T%10);
        T/=10;
    }

    while(T)
    {
        c.push_back(T%10);
        T/=10;
    }

    return c;
}

void print(vector<int>a){
    for(int i=a.size()-1;i>=0;i--)cout<<a[i];
    cout<<endl;
}


int main()
{

    int n;cin>>n;
    vector<int>a;
    a.push_back(1);

    for(int i=2;i<=n;i++)
    {
        a=mul(a,i);
    }

    print(a);
}