#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct hesap{
char hesapNumarasi[20];
char isim[15];
char soyad[15];
char sifre[7];
double bakiye;
int aktifMi;
};

int sifreDogrula(struct hesap *hesaplar, int id);
void hesapOlustur(struct hesap **hesaplar, int *hesapSayisi, int *kapasite);
void hesapListele(struct hesap *hesaplar, int hesapSayisi);
int hesapBul(struct hesap *hesaplar, int hesapSayisi, char arananNo[]);
void paraCek(struct hesap *hesaplar, int hesapSayisi, char hesapnumarasi[],double miktar);
void paraYatir(struct hesap *hesaplar, int hesapSayisi, char hesapnumarasi[],double miktar);
void paraTransferi(struct hesap *hesaplar, int hesapSayisi, char gonderenNo[], char aliciNo[], double miktar);
void hesapSil(struct hesap *hesaplar, int hesapSayisi, char silinecekNo[]);
void hesaplariSirala(struct hesap *hesaplar, int hesapSayisi);
void dosyayaKaydet(struct hesap *hesaplar, int hesapSayisi);
void dosyadanOku(struct hesap **hesaplar, int *hesapSayisi, int *kapasite);


int main()
{
   struct hesap *hesaplar = NULL;
   int hesapSayisi=0,kapasite=2,a=0;
   double miktar;
   char arananNumara[20],aliciNo[20],gonderenNo[20];


   hesaplar=(struct hesap*)malloc(kapasite*sizeof(struct hesap));
   if (hesaplar == NULL) {
    printf("Hata: Bellek ayrilamadi!\n");
    return 1;  }
dosyadanOku(&hesaplar, &hesapSayisi, &kapasite);


    int secim=0;
    printf("Islem yapmak istiyor musunuz?Istiyorsaniz 1 ,istemiyorsaniz 0 yazin.=");
   scanf("%d",&secim);

   while(secim){
    printf("\n=================================");
    printf("\n      BANKA YONETIM SISTEMI      ");
    printf("\n=================================\n");
    printf("Hangi islemi yapmak istiyorsunuz?\n");
    printf("0-Cikis.\n");
    printf("1-Yeni hesap Olustur.\n");
    printf("2-Hesaplari Listele.\n");
    printf("3-Hesap Bul.\n");
    printf("4-Para Yatir.\n");
    printf("5-Para Cek.\n");
    printf("6-Hesaplar arasi para transferi.\n");
    printf("7-Hesap sil.\n");
    printf("8-Hesaplari bakiyeye gore sirala.");




    scanf("%d",&secim);

switch(secim){
case 0:
dosyayaKaydet(hesaplar, hesapSayisi);
    printf("Cikis yapiliyor...");
    printf("Basariyla cikildi!"); break;

case 1: hesapOlustur(&hesaplar,&hesapSayisi,&kapasite); break;

case 2: hesapListele(hesaplar, hesapSayisi); break;

case 3: printf("Aradiginiz hesabin numarasi nedir?:");
      scanf("%19s", arananNumara);
        a=hesapBul(hesaplar, hesapSayisi,arananNumara);
        if(a==-1) printf("Gecersiz numara!Tekrar deneyin");
        else {
        printf("\n--- HESAP BILGISI ---\n");
        printf("Hesap No : %s\n", hesaplar[a].hesapNumarasi);
        printf("Ad Soyad : %s %s\n", hesaplar[a].isim, hesaplar[a].soyad);
        printf("Bakiye   : %.2f TL\n", hesaplar[a].bakiye);
    }
    break;


case 4: printf("Para cekmek istediginiz hesabin numarasi nedir?:");
        scanf("%19s", arananNumara);
        printf("\nNe kadar para cekeceksiniz?");
        scanf("%lf",&miktar);
        paraCek(hesaplar, hesapSayisi,arananNumara,miktar);
        printf("\nIslem basarili!");

        break;

case 5:

        printf("Para yatirmak istediginiz hesabin numarasi nedir?:");
        scanf("%19s", arananNumara);
        printf("\nNe kadar para yatiracaksiniz?");
        scanf("%lf",&miktar);
        paraYatir(hesaplar, hesapSayisi,arananNumara,miktar);
        printf("\nIslem basarili!");

        break;

case 6:
       printf("\nPara çekmek istediginiz hesabin numarasi nedir?:");
       scanf("%19s", gonderenNo);
       printf("Para tranfer etmek istediginiz hesabin numarasi nedir?:");
       scanf("%19s", aliciNo);

       printf("\nNe kadar para tranfer edeceksiniz?");
       scanf("%lf",&miktar);
       paraTransferi(hesaplar, hesapSayisi, gonderenNo, aliciNo, miktar);
       printf("\nIslem basarili!");
      break;

case 7:printf("Silinmesini istediginiz hesabin numarasini yaziniz. : ");
       scanf("%19s",arananNumara);
       hesapSil(hesaplar,hesapSayisi,arananNumara);
    break;

case 8:hesaplariSirala(hesaplar,hesapSayisi);
    break;
    default: printf("Gecersiz islem!");
}


   }

   free(hesaplar);
    return 0;
}
int sifreDogrula(struct hesap *hesaplar, int id) {
    char girilenSifre[7];
    printf("Islem onayi icin sifrenizi giriniz: ");
    scanf("%6s", girilenSifre);
    if (strcmp(hesaplar[id].sifre, girilenSifre) == 0) {
        return 1;}

    printf("Hatali sifre! Islem iptal edildi.\n");
    return 0;}


void hesapOlustur(struct hesap **hesaplar, int *hesapSayisi, int *kapasite){
if(*kapasite==*hesapSayisi){
    *kapasite = (*kapasite) * 2;
    *hesaplar=(struct hesap*)realloc(*hesaplar, (*kapasite) * sizeof(struct hesap));
}
if(*hesaplar == NULL) return;

      printf("Hesap Numarasi: ");
      scanf("%s", (*hesaplar)[*hesapSayisi].hesapNumarasi);
      getchar();

      printf("\nIsim ve soyad:");
      scanf("%s %s", (*hesaplar)[*hesapSayisi].isim, (*hesaplar)[*hesapSayisi].soyad);
      printf("\nSifre::");
      scanf("%s", (*hesaplar)[*hesapSayisi].sifre);
      getchar();

      printf("\nBakiye::");
      scanf("%lf", &((*hesaplar)[*hesapSayisi].bakiye));
      (*hesaplar)[*hesapSayisi].aktifMi = 1;
      (*hesapSayisi)++;
      printf("Hesap basariyla olusturuldu!\n");
}

void hesapListele(struct hesap *hesaplar, int hesapSayisi) {
    if (hesapSayisi == 0) {
        printf("Henuz hesap olusturulmadi.\n");
        return;}

    int aktifSayisi = 0;
    for (int i = 0; i < hesapSayisi; i++) {
        if (hesaplar[i].aktifMi == 1) {
            printf("\nHesap numarasi : %s\n", hesaplar[i].hesapNumarasi);
            printf("Isim ve Soyisim: %s %s\n", hesaplar[i].isim, hesaplar[i].soyad);
            printf("Hesap bakiyesi : %.2f TL\n", hesaplar[i].bakiye);
            aktifSayisi++;}}

    if (aktifSayisi == 0) {
        printf("Sistemde aktif hesap bulunmamaktadir.\n");}}

int hesapBul(struct hesap *hesaplar, int hesapSayisi, char arananNo[]){

int i=0;
for(i;i<hesapSayisi;i++){
    if(strcmp(hesaplar[i].hesapNumarasi, arananNo) == 0 && hesaplar[i].aktifMi == 1){
        return i;
    }
}
return -1;


}

void paraCek(struct hesap *hesaplar, int hesapSayisi, char hesapnumarasi[], double miktar) {


    int id = hesapBul(hesaplar, hesapSayisi, hesapnumarasi);
    if (id == -1) {
        printf("Hesap bulunamadi!\n");
        return;
    }
    if (!sifreDogrula(hesaplar, id)) {
        return;}

      if (miktar > hesaplar[id].bakiye) {
        printf("Yetersiz bakiye!\n");
        printf("Guncel Bakiye: %.2f TL\n", hesaplar[id].bakiye);

        return;
    }

    hesaplar[id].bakiye -= miktar;
    printf("Islem basarili! Guncel Bakiye: %.2f TL\n", hesaplar[id].bakiye);
}

void paraYatir(struct hesap *hesaplar, int hesapSayisi, char hesapnumarasi[], double miktar) {
    if (miktar <= 0) {
        printf("Gecersiz tutar! Tutar 0'dan buyuk olmalidir.\n");
        return;
    }

    int id = hesapBul(hesaplar, hesapSayisi, hesapnumarasi);
    if (id == -1) {
        printf("Hesap bulunamadi!\n");
        return;
    }
    if (!sifreDogrula(hesaplar, id)) {
        return;}

    hesaplar[id].bakiye += miktar;
    printf("Islem basarili! Guncel Bakiye: %.2f TL\n", hesaplar[id].bakiye);
}

void paraTransferi(struct hesap *hesaplar, int hesapSayisi, char gonderenNo[], char aliciNo[], double miktar){


if(miktar<=0){
        printf("Gecersiz tutar!");
        return;
}
if(strcmp(aliciNo,gonderenNo)==0){
        printf("Kendinize para transfer edemezsiniz.");
         return ;}

int gId = hesapBul(hesaplar, hesapSayisi, gonderenNo);
int aId = hesapBul(hesaplar, hesapSayisi, aliciNo);


if(gId == -1 || aId == -1 ){
    printf("Alici veya gonderici bulunamadi."); return;}

    if (!sifreDogrula(hesaplar, gId)) {
        return;}


if(miktar>hesaplar[gId].bakiye){
         printf("Yetersiz bakiye!"); return;}

hesaplar[gId].bakiye -= miktar;
hesaplar[aId].bakiye += miktar;

printf("\nIslem basariyla gerceklesti!%.2f TL %s kisisinden %s kisine transfer edildi.",miktar,hesaplar[gId].isim,hesaplar[aId].isim);
printf("\n");
printf("%.2f guncel bakiye.",hesaplar[gId].bakiye);
}

void hesapSil(struct hesap *hesaplar, int hesapSayisi, char silinecekNo[]){
   int id= hesapBul(hesaplar,hesapSayisi,silinecekNo);
    if(id==-1){
        printf("Hesap bulunamadi veya zaten kapali!"); return;
    }

    if (hesaplar[id].bakiye > 0){ printf("Lutfen once hesap bakiyesini (%.2f TL) cekiniz!", hesaplar[id].bakiye); return;}

      hesaplar[id].aktifMi = 0;
      printf("Hesap basariyla kapatildi.\n");
}

void hesaplariSirala(struct hesap *hesaplar, int hesapSayisi) {
    if (hesapSayisi < 2) {
        printf("Siralamak icin en az 2 hesap gereklidir.\n");
        return;
    }

    struct hesap gecici;
    for (int i = 0; i < hesapSayisi - 1; i++) {
        for (int j = 0; j < hesapSayisi - i - 1; j++) {
            if (hesaplar[j].bakiye < hesaplar[j + 1].bakiye) {
                gecici = hesaplar[j];
                hesaplar[j] = hesaplar[j + 1];
                hesaplar[j + 1] = gecici;
            }
        }
    }

    printf("\nHesaplar bakiyelerine gore (en yuksekten en dusuge) siralandi:\n");
    hesapListele(hesaplar, hesapSayisi);
}

void dosyayaKaydet(struct hesap *hesaplar, int hesapSayisi) {
    FILE *dosya = fopen("hesaplar.bin", "wb");
    if (dosya == NULL) {
        printf("Hata: Dosya yazma modunda acilamadi!\n");
        return;
    }

    fwrite(&hesapSayisi, sizeof(int), 1, dosya);
    fwrite(hesaplar, sizeof(struct hesap), hesapSayisi, dosya);
    fclose(dosya);
    printf("Veriler basariyla 'hesaplar.bin' dosyasina kaydedildi.\n");
}

void dosyadanOku(struct hesap **hesaplar, int *hesapSayisi, int *kapasite) {
    FILE *dosya = fopen("hesaplar.bin", "rb");
    if (dosya == NULL) {
        return;
    }

    fread(hesapSayisi, sizeof(int), 1, dosya);

    if (*hesapSayisi > 0) {
        *kapasite = *hesapSayisi + 2;
        struct hesap *gecici = (struct hesap*)realloc(*hesaplar, (*kapasite) * sizeof(struct hesap));
        if (gecici != NULL) {
            *hesaplar = gecici;
            fread(*hesaplar, sizeof(struct hesap), *hesapSayisi, dosya);
            printf("Gecmis veriler yuklendi: %d kayitli hesap bulundu.\n", *hesapSayisi);
        }
    }
    fclose(dosya);
}
