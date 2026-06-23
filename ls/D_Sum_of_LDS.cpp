#include<iostream>
using namespace std;
int n,a,b,z,cnt;
int main(){
    scanf("%d",n);
    cin>>a>>b;
    z=a+b;
    for(int i=0;i<n;i++){
        if(n-z){
            n-=z;
            cnt++;
        }else{
            break;
        }
    }
    printf("%d",cnt);
    return 0;
}