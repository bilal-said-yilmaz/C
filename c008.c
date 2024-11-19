// Doğrudan struct oluşturma ve struct'a pointer göndererek dolaylı yoldan struct oluşturma arasındaki fark incelendi.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct ogrenci{
    char adi[30];
    int yasi;
    float notu;
};
typedef struct {
    char adi[30];
    char bransi[50];
}ogretmen;

int main(){
    //DIRECT
    struct ogrenci ogr1;
    strcpy(ogr1.adi,"Bilal Said");
    ogr1.yasi=20;
    ogr1.notu=95.5;
    printf("%s adındaki öğrencinin yaşı: %d , notu ise:%.2f\n",ogr1.adi,ogr1.yasi,ogr1.notu);

    //UNDIRECT
    struct ogrenci *o2= (struct ogrenci *)malloc(sizeof(struct ogrenci ));
    strcpy(o2->adi,"Doğan");
    o2->yasi=20;
    o2->notu=98;
    printf("%s adındaki öğrencinin yaşı: %d , notu ise:%.2f\n",o2->adi,o2->yasi,o2->notu);

    //TYPEDEF
    ogretmen ogretmen1;
    strcpy(ogretmen1.adi,"Ferhunde");
    strcpy(ogretmen1.bransi,"Tarih");
    printf("%s adınadki öğretmenin branşı: %s\n",ogretmen1.adi,ogretmen1.bransi);

    //UNDIRECT TYPEDEF
    ogretmen *ogretmen2=(ogretmen *)malloc(sizeof(ogretmen));
    strcpy(ogretmen2->adi,"Kılıçarslan");
    strcpy(ogretmen2->bransi,"Coğrafya");
    printf("%s adınadki öğretmenin branşı: %s\n",ogretmen2->adi,ogretmen2->bransi);

    return 0;
}
