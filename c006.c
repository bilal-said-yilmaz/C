// Diziye eleman ekleme 

#include <stdio.h>

int main(){
// Öncelikle diziye doğrudan kendimiz eleman ekliyoruz sonrasında bunları değiştireceğiz
int dizi[11]={123,123,1244,2245,5};
printf("5. indexteki eleman 0 olmalı :%d \n",dizi[5]);
for (int i=0;i<11;i++){
    printf("%d. indexteki elemana değer giriniz:  ",i);
    scanf("%d",&dizi[i]);

};
for (int j=0;j<11;j++){
    printf("%d. indeksteki eleman: %d\n",j,dizi[j]);
    
};
return 0;
}
