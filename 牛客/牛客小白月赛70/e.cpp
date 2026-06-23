#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

    int n,m;
    cin>>n>>m;
   int t=(int)log2(n)+(int)log2(m);
   if(t%2){
    cout<<"Alice"<<endl;
   }
   else cout<<"Bob"<<endl;
    }
}    