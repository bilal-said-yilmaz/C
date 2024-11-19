// Büyükten küçüğe sıralanmış diziye eklediğimiz elemanı olması gerektiği yere koyma problemi. 
#include <stdio.h>

int main(){
    int ogrenciler[21]={100,100,92,91,87,86,85,85,85,84,83,82,75,64,60,57,53,42,40,35};
    int yeni,flag=0,suanki=0;

    printf("Yeni öğrencinin aldığı notu girin\n");
    scanf("%d",&yeni);
    for (int i=0;i<21;i++){
        if (yeni <=ogrenciler[i]){
            flag=i+1;
        }
        if (ogrenciler[i]!=0){
            suanki++;
            }
    }
    if(21>suanki){
    for (int i=21-1;i>=flag;i--){
        ogrenciler[i+1]=ogrenciler[i];
    }
    ogrenciler[flag]=yeni;
}
    for (int i=0;i<21;i++){
        printf("%2d. Kişinin aldığı NOT:\t%3d \n",i+1,ogrenciler[i]);
}

    return 0;
}
