#include <stdio.h>


     struct tip{
        char neTur[20];
        char sat_kira[10];
    };
    struct gayrimenkul{
        struct tip t;
        int fiyat;
        char konum[20];
    };
   
int main(){
    struct gayrimenkul gayrimenkul1 = {{"Arsa", "sat"}, 2000000, "Karacaoglan"};
    struct gayrimenkul gayrimenkul2 = {{"Daire", "kira"}, 10000, "Baglar"};

     printf("İlk Gayrimenkulümüzün özellikleri: Ne Tür: %s, Sat/Kira: %s, Fiyat(TL): %d, Konum: %s\n",
           gayrimenkul1.t.neTur, gayrimenkul1.t.sat_kira, gayrimenkul1.fiyat, gayrimenkul1.konum);
    printf("İkinci Gayrimenkulümüzün konumu: %s\n",gayrimenkul2.konum);
    printf("İkinci Gayrimenkulümüzün fiyatı(TL): %d\n",gayrimenkul2.fiyat);

    return 0;
}
