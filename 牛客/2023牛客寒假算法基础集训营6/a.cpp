#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long t;
    cin>>t;
    if(t>=1&&t<=7){
        cout<<"very easy"<<endl;
    }
    else if(t<=233)cout<<"easy"<<endl;
    else if(t<=10032)cout<<"medium"<<endl;
    else if(t<=114514)cout<<"hard"<<endl;
    else if(t<=1919810)cout<<"very hard"<<endl;
    else cout<<"can not imagine"<<endl;
    return 0;
}