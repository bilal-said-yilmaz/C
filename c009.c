// Struct'a başka bir struct yollamaişlemi.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char adi[20];
    int kurulus;
}takim;

typedef struct {
    char adi[20];
    int yasi;
    takim *tk;    
}futbolcu;

int main(){
    futbolcu f1;
    takim *tk=(takim *)malloc(sizeof(takim));
    strcpy(tk->adi,"GALATASARAY");
    tk->kurulus=1905;

    strcpy(f1.adi,"VICTOR JAMES OSIMHEN");
    f1.yasi=25;
    f1.tk=tk;

    printf("%s adındaki futbolcunun yaşı: %d , takımının adı:%s takımının kuruluşu ise:%d\n",f1.adi,f1.yasi,f1.tk->adi,f1.tk->kurulus);

    return 0;
}
