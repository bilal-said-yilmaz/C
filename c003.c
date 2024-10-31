#include <stdio.h>

int main(){
    char text[6]={"Bilal"};
    for (int i = sizeof(text)-2 ; i>=0 ;i--){
        printf("%c\t",text[i]);
    }
    return 0;
}
