#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%d", &t);
    int x = 0, y = 0, cnt = 0;
    bool flag = 1;
    bool p = 0;
    for(int i = 1; i <= t; i++){
        int a, b;
        scanf("%d-%d",&a, &b);
        // printf("%d %d\n",a,b);
        // printf("%d %d %d\n",p,a+b,cnt);
        if(p && a + b > cnt){
            printf("error %d", i);
            return 0;            
        }

        if(a > 11 || b > 11 || a + b < cnt){
            printf("error %d", i);
            return 0;
        } 
        if(a == 11 && b == 11){
            printf("error %d", i);
            return 0;            
        }

        if(((a + b + 1) / 2) % 2)
            flag = 0;
        else flag = 1;

        if(flag){
            if(a < x || b < y){
                printf("error %d", i);
                return 0;
            }
            x = a, y = b;
        }else {
            if(a < y || b < x){
                printf("error %d", i);
                return 0;
            }
            y = a, x = b;
        }
        cnt = a + b;

        if(x == 11 || y == 11) p = 1;
    }    
    printf("ok");
    return 0;
}