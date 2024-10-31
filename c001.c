#include <stdio.h>

int main(){
    int nums[11]={9,8,7,6,5,4,3,2,1,0,-1};
    for (int i=0;i<11;i++){
        printf("%d\n",(nums[i]*nums[i]));
    }
    return 0;
}
