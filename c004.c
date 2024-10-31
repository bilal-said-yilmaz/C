#include <stdio.h>
#include <string.h>

int main(){ 
    char str1[20]= "Hello, ";
    char str2[]="World!!!";
    strcat(str1,str2);
    printf("Stringlerin birlestirilmis hali: %s",str1);

    printf("\nilk stringin uzunlugu:%lu\nikinci stringin uzunlugu:%lu",strlen(str1),strlen(str2));

    return 0;
}
