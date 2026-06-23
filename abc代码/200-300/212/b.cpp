#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    int a,b,c,d;
    scanf("%1d%1d%1d%1d",&a,&b,&c,&d);
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    if(a==b&&b==c&&c==d){
        cout<<"Weak"<<endl;
    }
    else if((a+1)%10==b&&(b+1)%10==c&&(c+1)%10==d){
        cout<<"Weak"<<endl;
    }
    else cout<<"Strong"<<endl;
}