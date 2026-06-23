#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(b==0){
        cout<<"Gold"<<endl;
    }
    else if(a==0){
        cout<<"Silver"<<endl;
    }
    else cout<<"Alloy";
}