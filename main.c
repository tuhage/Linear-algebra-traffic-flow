#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>


enum Anayollar {tYolu,xYolu,yYolu,zYolu};
enum Yollar {aYolu,bYolu,cYolu,dYolu,eYolu};
enum Nitelikler {bas,son,aracYogunlugu,isim};

int haritaSecimi;
int celiski;
char TEMP[10];
void allegroGiris();

void allegroHarita();

void allegroYonleriCiz(int aSon,int bSon,int cSon,int dSon,int eSon,int tSon,int xSon,int ySon,int zSon);

void bilinmeyenlerMatrisiniOlustur(int N,char matris[N],int yollar[5][4],int anaYollar[4][4]);

void aracSayisiAl(char yolAdi,int *aracsayisi,int * bilinmeyenSayisi);

void matrisSifirla(int R,int N,int matris[R][N],int sonucMatrisi[R]);

void matrisOlustur(int R,int N,int matris[R][N],int sonucMatrisi[R],char bilinmeyenlerMatrisi[N],int yollar[5][4],int anaYollar[4][4]);

void matrisCiz(int R,int N,int matris[R][N],int sonucMatrisi[R],char bilinmeyenlerMatrisi[N]);

void gauss(int R,int N,int matris[R][N],int sonucMatrisi[R]);

int sonucKontrol(int R,int N,int matris[R][N],int sonucMatrsisi[R]);

void sonucuYaz(int R,int N,int matris[R][N],int sonucMatrsisi[R],char bilinmeyenlerMatrisi[N],int durum);

void yonSorgula(char Yoladi,int *yol);

int yonKontrol(int yollar[5][4],int anaYollar[4][4]);

int celiskiKontrol(int dugumNo,int yollar[5][4],int anaYollar[4][4]);

void GirisCikisAl(char Yoladi,int* girisSayisi,int* cikisSayisi,int* anayol);

void isimleriGir(int a[5][4],int b[4][4]);

//dugumCoz(N,i,matris[k],&sonucMatrisi[k],bilinmeyenlerMatrisi,yollar,anaYollar);
void dugumCoz(int N,int dugumNo,int *matrisSatir,int *matrisSatirSonuc,char bilinmeyenlerMatrisi[N],int yollar[5][4],int anaYollar[4][4]);

int dugumKontrol(int dugumNo,int yollar[5][4],int anaYollar[4][4]);

int indexBul(const char *dizi,int N,int aranan);

void delay(unsigned int mseconds);

int main(void) {

    allegroGiris();

        while(1){
            printf("Bir harita secin: ");
            scanf("%s",TEMP);
            haritaSecimi=atoi(TEMP);
            if(haritaSecimi!=2&&haritaSecimi!=1){
                printf("Lutfen gecerli bir harita numarası girin : (1 veya 2)\n");
                continue;
            }

            break;      }

    allegroHarita();

        int girisSayisi = 0, cikisSayisi = 0, bilinmeyenSayisi = 0;
        int yollar[5][4] = {}, anaYollar[4][4];
        isimleriGir(yollar, anaYollar);

        printf("\nAna yollarin giris ve cikis bilgilerini giriniz(giris icin->1)(cikis icin->1) : \nGiris ve Cikis degerleri en fazla 2 adet olabilir.\n");


        GirisCikisAl((char) anaYollar[tYolu][isim], &girisSayisi, &cikisSayisi, anaYollar[tYolu]);
        GirisCikisAl((char) anaYollar[xYolu][isim], &girisSayisi, &cikisSayisi, anaYollar[xYolu]);
        GirisCikisAl((char) anaYollar[yYolu][isim], &girisSayisi, &cikisSayisi, anaYollar[yYolu]);
        GirisCikisAl((char) anaYollar[zYolu][isim], &girisSayisi, &cikisSayisi, anaYollar[zYolu]);


        printf("\n\n---Ana yollarin giris ve cikis degerleri basarili bir sekilde alındı---\n\n");

        printf("t yolu : ");
        if (anaYollar[tYolu][bas] == 0)printf("Giris\n"); else printf("Cikis\n");
        printf("x yolu : ");
        if (anaYollar[xYolu][bas] == 0)printf("Giris\n"); else printf("Cikis\n");
        printf("y yolu : ");
        if (anaYollar[yYolu][bas] == 0)printf("Giris\n"); else printf("Cikis\n");
        printf("z yolu : ");
        if (anaYollar[zYolu][bas] == 0)printf("Giris\n"); else printf("Cikis\n");

        printf("\n\n");
            while(1) {
                if (haritaSecimi == 1) {
                    yonSorgula((char) yollar[aYolu][isim], yollar[aYolu]);
                    yonSorgula((char) yollar[bYolu][isim], yollar[bYolu]);
                    yonSorgula((char) yollar[dYolu][isim], yollar[dYolu]);
                    yonSorgula((char) yollar[cYolu][isim], yollar[cYolu]);

                } else {

                    yonSorgula((char) yollar[aYolu][isim], yollar[aYolu]);
                    yonSorgula((char) yollar[bYolu][isim], yollar[bYolu]);
                    yonSorgula((char) yollar[dYolu][isim], yollar[dYolu]);
                    yonSorgula((char) yollar[cYolu][isim], yollar[cYolu]);
                    yonSorgula((char) yollar[eYolu][isim], yollar[eYolu]);

                }
                int test=yonKontrol(yollar,anaYollar);
                if(test==1)break;
                else if(test==0)
                    printf("\nUc veya dort yolun yonu ayni noktada kesisemez ! \nlutfen yonleri tekrar giriniz \n");
                else if(test==2)
                    printf("\nUc veya dort yolun baslangic noktasi ayni olamaz ! \nlutfen yonleri tekrar giriniz \n");
            }
        printf("\n\n\n--- Yonler basarili bir sekilde alindi---\n\n\n...Yonler harita uzerinde gosteriliyor...\n\n\n");

       allegroYonleriCiz(yollar[aYolu][son],yollar[bYolu][son],yollar[cYolu][son],yollar[dYolu][son],yollar[eYolu][son],anaYollar[tYolu][son],anaYollar[xYolu][son],anaYollar[yYolu][son],anaYollar[zYolu][son]);
        while(bilinmeyenSayisi<1){
            bilinmeyenSayisi=0;
        if (haritaSecimi == 1) {
            aracSayisiAl((char) yollar[aYolu][isim], &yollar[aYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) yollar[bYolu][isim], &yollar[bYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) yollar[dYolu][isim], &yollar[dYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) yollar[cYolu][isim], &yollar[cYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[tYolu][isim], &anaYollar[tYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[xYolu][isim], &anaYollar[xYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[yYolu][isim], &anaYollar[yYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[zYolu][isim], &anaYollar[zYolu][aracYogunlugu], &bilinmeyenSayisi);
            if(bilinmeyenSayisi==8)bilinmeyenSayisi=-1;
        } else {

            aracSayisiAl((char) yollar[aYolu][isim], &yollar[aYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) yollar[bYolu][isim], &yollar[bYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) yollar[dYolu][isim], &yollar[dYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) yollar[cYolu][isim], &yollar[cYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) yollar[eYolu][isim], &yollar[eYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[tYolu][isim], &anaYollar[tYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[xYolu][isim], &anaYollar[xYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[yYolu][isim], &anaYollar[yYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[zYolu][isim], &anaYollar[zYolu][aracYogunlugu], &bilinmeyenSayisi);
            if(bilinmeyenSayisi==9)bilinmeyenSayisi=-1;

        }
        if(bilinmeyenSayisi==0)printf("\nLutfen en az bir adet bilinmeyen girin.\n");
        if(bilinmeyenSayisi==-1)printf("\nLutfen en az bir adet bilinen girin.\n");
        }

        
        printf("\n\n\n--- Yogunluk degerleri basarili bir sekilde alindi---\n\n\n...Matris olusturuluyor...\n\n\n");
       
        int N = bilinmeyenSayisi,R=5;
        int matris[R][N], sonucMatrisi[R];
        char bilinmeyenlerMatrisi[N];
        //if(N>5)N=5;


        bilinmeyenlerMatrisiniOlustur(N, bilinmeyenlerMatrisi, yollar, anaYollar);
        matrisSifirla(R,N, matris, sonucMatrisi);
        matrisOlustur(R,N, matris, sonucMatrisi, bilinmeyenlerMatrisi, yollar, anaYollar);
        matrisCiz(R,N, matris, sonucMatrisi, bilinmeyenlerMatrisi);
        printf("\n\n");
        gauss(R,N,matris,sonucMatrisi);
       int sonuc=sonucKontrol(R,N,matris,sonucMatrisi);
       sonucuYaz(R,N,matris,sonucMatrisi,bilinmeyenlerMatrisi,sonuc);

        return 0;

    }


int sonucKontrol(int R,int N,int matris[R][N],int sonucMatrsisi[R]){
     int kontrol=0,kontrol1=0,kontrol2=0,sonsuzindis;

    for (int i = 0; i <N; ++i) {
        if(matris[i][i]==1 )kontrol1++;if(sonucMatrsisi[i]>=0)kontrol++;

    }

    for (int j = R-1; j >=0 ; --j) {
        for (int i = 0; i <N ; ++i) {
            if(matris[j][i]!=0){kontrol2=0;break;}
            kontrol2++;
        }
        if(kontrol2==N)if(sonucMatrsisi[j]!=0)return -1;//çelişki durumu
        kontrol2=0;
    }

    if(kontrol==N && kontrol1==N)return 1; // çözüm var
    if(kontrol<N && kontrol1==N) return -2; //negatif bir yoğunluk değeri olamaz
     if(N>4)return 11;
 


}

void sonucuYaz(int R,int N,int matris[R][N],int sonucMatrsisi[R],char bilinmeyenlerMatrisi[N],int durum){

    if(celiski==-1){
        
        printf("\n---SONUC---\n   Girdiginiz degerler birbiri ile celiskili oldugundan herhangi bir sonuc bulunamamistir.\n\n\n");
        return -1;
    }

                if(durum==1){
                    printf("\n");
                    matrisCiz(N,N,matris,sonucMatrsisi,bilinmeyenlerMatrisi);
                    printf("\n\n---- Sonuc basarili bir sekilde hesaplandi ---- \n");
                    printf("\n        ---- SONUC ----                 \n\n");
                    for (int i = 0; i <N ; ++i) {
                        printf("     %c yolunun yogunlugu = %d \n",bilinmeyenlerMatrisi[i],sonucMatrsisi[i]);

                    }
                    scanf("%1s",TEMP);
                    scanf("%1s",TEMP);
                }else if(durum=11){
                            
                   
                    
                        matrisCiz(R,N,matris,sonucMatrsisi,bilinmeyenlerMatrisi);
                        printf("\n\n");
                        
                      
                    

                   int k=0,temp=0;
                   
                    for(int i=0;i<R;i++){
                        if(matris[i][i]!=1)continue;
                        printf("\n%2c = %2d ",bilinmeyenlerMatrisi[i],sonucMatrsisi[i]);
                        for(int j=i+1;j<N;j++){
                            if(matris[i][j]!=0){
                                if(matris[i][j]<0) printf(" + %2c ",bilinmeyenlerMatrisi[j]);
                                if(matris[i][j]>0) printf(" - %2c ",bilinmeyenlerMatrisi[j]);
                                k++;
                            }
                            
                        }
                            if(k==0 && sonucMatrsisi[i]<0){
                                 
                    
                    printf("\n\n---- Yogunluk degeri negatif olamayacagi icin cozum bulunanamaktadır.---\n\n");return -1;
                    
                            }
                        k=0;
                    }
                    printf("\n\n");
                    temp=-1;
                    for(int i=0;i<R;i++){
                        if(matris[i][i]!=1)continue;
                        
                        for(int j=i+1;j<N;j++){
                            if(matris[i][j]!=0){
                                k++;
                            }
                        }
                    if(k==0)continue;
                        
                        if(i>0&&k!=0)
                          printf(" && ");
                        k=0;
                          
                        for(int j=i+1;j<N;j++){
                            if(matris[i][j]!=0){
                
                                if(matris[i][j]<0) printf(" -%c",bilinmeyenlerMatrisi[j]);
                                if(matris[i][j]>0) printf(" +%c",bilinmeyenlerMatrisi[j]);
                               
                              
                            }
                          
                    }
                            printf(" < %2d",sonucMatrsisi[i]);
                }
                    
                      printf("\nEsitsizliklerini saglayan her deger icin cozum bulunmaktadir.");
                     
                     scanf("%1s",TEMP);
                    scanf("%1s",TEMP);
                   

                }else if(durum==-1){

                    printf("\n");
                    matrisCiz(R,N,matris,sonucMatrsisi,bilinmeyenlerMatrisi);
                    printf("\n\n---- SONUC ---- \n");
                    printf("\n---- Girdiginiz degerler celiskili oldugu icin cozum bulunanamaktadır.---\n\n");
                        
                    scanf("%1s",TEMP);
                    scanf("%1s",TEMP);

                }else if(durum==-2){

                    printf("\n");
                    matrisCiz(R,N,matris,sonucMatrsisi,bilinmeyenlerMatrisi);
                    printf("\n\n---- SONUC ---- \n");
                    for(int i=0;i<R;i++){
                        if(matris[i][i]!=1)continue;
                        printf("\n%2c = %2d ",bilinmeyenlerMatrisi[i],sonucMatrsisi[i]);
                        for(int j=i+1;j<N;j++){
                            if(matris[i][j]!=0){
                                if(matris[i][j]<0) printf(" + %2c ",bilinmeyenlerMatrisi[j]);
                                if(matris[i][j]>0) printf(" - %2c ",bilinmeyenlerMatrisi[j]);
                            } 
                        }
                    }
                    printf("\n---- Yogunluk degeri negatif olamayacagi icin cozum bulunanamaktadır.---\n\n");

                        scanf("%1s",TEMP);
                        scanf("%1s",TEMP);
                }








}

void GirisCikisAl(char Yoladi,int* girisSayisi,int* cikisSayisi,int* anayol){
    int girisCikis,yolNum=0;
    while(1){
        printf("\n%c yolu : ",Yoladi);
        scanf("%s",TEMP);
        girisCikis=atoi(TEMP);
        if((girisCikis)==1)(*girisSayisi)++;
        else if((girisCikis)==-1)(*cikisSayisi)++;
        else{printf("Lütfen geçerli bir değer giriniz ! Giris icin:1 Cikis icin:-1\n");continue;}
        if((*girisSayisi)>2){
            printf("En fazla 2 adet giris yolu girebilirsiniz !!\nLütfen tekrar giris yapin\n");(*girisSayisi)--;continue;
        }
        if((*cikisSayisi)>2){
            printf("En fazla 2 adet cikis yolu girebilirsiniz !!\nLütfen tekrar giris yapin\n");(*cikisSayisi)--;continue;
        }

        break;
    }
    if(Yoladi=='t')yolNum=1;
    else if(Yoladi=='x')yolNum=2;
    else if(Yoladi=='y')yolNum=3;
    else if(Yoladi=='z')yolNum=4;

    if(girisCikis==1){anayol[bas]=0;anayol[son]=yolNum;}
    else{anayol[son]=0;anayol[bas]=yolNum;}


}


void yonSorgula(char Yoladi,int *yol){
    char baslangicnoktasi,Yonu;
    while(1) {
        printf("\n%c yolu icin baslangic noktasini giriniz : ", Yoladi);
        scanf("%s",TEMP);
        if(strlen(TEMP)>1){
            printf("Lütfen geçerli bir baslangic noktasi girin\n");
            continue;}
        baslangicnoktasi=TEMP[0];
        if (Yoladi == 'a' && (baslangicnoktasi != 't' && baslangicnoktasi != 'x')){
            printf("Lütfen geçerli bir baslangic noktasi girin\n");
            continue;}
        else if (Yoladi == 'b' && (baslangicnoktasi != 'x' && baslangicnoktasi != 'y')){
            printf("Lütfen geçerli bir baslangic noktasi girin\n");
            continue;}
        else  if (Yoladi == 'c' && (baslangicnoktasi != 't' && baslangicnoktasi != 'z')){
            printf("Lütfen geçerli bir baslangic noktasi girin\n");
            continue;}
        else if (Yoladi == 'd' && (baslangicnoktasi != 'z' && baslangicnoktasi != 'y')){
            printf("Lütfen geçerli bir baslangic noktasi girin\n");
            continue;}
        else if (Yoladi == 'e' && (baslangicnoktasi != 't' && baslangicnoktasi != 'y')){
            printf("Lütfen geçerli bir baslangic noktasi girin\n");
            continue;}
        break;
    }



    while(1) {

        printf("\n%c yolu icin yonu giriniz : ", Yoladi);
        scanf("%s",TEMP);
       if(strlen(TEMP)>1){
           printf("Lutfen geçerli bir yon girin\n");
        continue;}
       Yonu=TEMP[0];
        if ((Yoladi == 'a' && baslangicnoktasi == 't' )&& (Yonu != 'x')){
            printf("Lutfen geçerli bir yon girin\n");
            continue;}
        else if((Yoladi == 'a' && baslangicnoktasi == 'x' )&& (Yonu != 't')){
            printf("Lutfen geçerli bir yon girin\n");
            continue;
        }else if ((Yoladi == 'b' && baslangicnoktasi == 'y' )&& (Yonu != 'x')){
            printf("Lutfen geçerli bir yon girin\n");
            continue;}
        else if((Yoladi == 'b' && baslangicnoktasi == 'x' )&& (Yonu != 'y')){
            printf("Lutfen geçerli bir yon girin\n");
            continue;
        }
        else if ((Yoladi == 'c' && baslangicnoktasi == 't' )&& (Yonu != 'z')){
            printf("Lutfen geçerli bir yon girin\n");
            continue;}
        else if((Yoladi == 'c' && baslangicnoktasi == 'z' )&& (Yonu != 't')){
            printf("Lutfen geçerli bir yon girin\n");
            continue;
        }else if ((Yoladi == 'd' && baslangicnoktasi == 'y' )&& (Yonu != 'z')){
            printf("Lutfen geçerli bir yon girin\n");
            continue;}
        else if((Yoladi == 'd' && baslangicnoktasi == 'z' )&& (Yonu != 'y')){
            printf("Lutfen geçerli bir yon girin\n");
            continue;
        }else if ((Yoladi == 'e' && baslangicnoktasi == 'y' )&& (Yonu != 't')){
            printf("Lutfen geçerli bir yon girin\n");
            continue;}
        else if((Yoladi == 'e' && baslangicnoktasi == 't' )&& (Yonu != 'y')){
            printf("Lutfen geçerli bir yon girin\n");
            continue;
        }




        break;
    }

    if(baslangicnoktasi=='t')yol[bas]=1;
    else if(baslangicnoktasi=='x')yol[bas]=2;
    else if(baslangicnoktasi=='y')yol[bas]=3;
    else if(baslangicnoktasi=='z')yol[bas]=4;

    if(Yonu=='t')yol[son]=1;
    else if(Yonu=='x')yol[son]=2;
    else if(Yonu=='y')yol[son]=3;
    else if(Yonu=='z')yol[son]=4;


}
int yonKontrol(int yollar[5][4],int anaYollar[4][4]){



    if(haritaSecimi==1){

        if(yollar[aYolu][son]==anaYollar[tYolu][son]&&yollar[aYolu][son]==yollar[cYolu][son])return 0;
        if(yollar[aYolu][son]==anaYollar[xYolu][son]&&yollar[bYolu][son]==anaYollar[xYolu][son])return 0;
        if(yollar[dYolu][son]==anaYollar[yYolu][son]&&yollar[bYolu][son]==anaYollar[yYolu][son])return 0;
        if(yollar[cYolu][son]==anaYollar[zYolu][son]&&yollar[dYolu][son]==anaYollar[zYolu][son])return 0;


    }else{
        if(yollar[aYolu][son]==anaYollar[tYolu][son]&&yollar[eYolu][son]==yollar[cYolu][son])return 0;
        if(yollar[aYolu][son]==anaYollar[xYolu][son]&&yollar[bYolu][son]==anaYollar[xYolu][son])return 0;
        if(yollar[dYolu][son]==anaYollar[yYolu][son]&&yollar[bYolu][son]==yollar[eYolu][son])return 0;
        if(yollar[cYolu][son]==anaYollar[zYolu][son]&&yollar[dYolu][son]==anaYollar[zYolu][son])return 0;

    }
    if(haritaSecimi==1){

        if(yollar[aYolu][bas]==anaYollar[tYolu][bas]&&yollar[aYolu][bas]==yollar[cYolu][bas])return 2;
        if(yollar[aYolu][bas]==anaYollar[xYolu][bas]&&yollar[bYolu][bas]==anaYollar[xYolu][bas])return 2;
        if(yollar[dYolu][bas]==anaYollar[yYolu][bas]&&yollar[bYolu][bas]==anaYollar[yYolu][bas])return 2;
        if(yollar[cYolu][bas]==anaYollar[zYolu][bas]&&yollar[dYolu][bas]==anaYollar[zYolu][bas])return 2;


    }else{
        if(yollar[aYolu][bas]==anaYollar[tYolu][bas]&&yollar[eYolu][bas]==yollar[cYolu][bas])return 2;
        if(yollar[aYolu][bas]==anaYollar[xYolu][bas]&&yollar[bYolu][bas]==anaYollar[xYolu][bas])return 2;
        if(yollar[dYolu][bas]==anaYollar[yYolu][bas]&&yollar[bYolu][bas]==yollar[eYolu][bas])return 2;
        if(yollar[cYolu][bas]==anaYollar[zYolu][bas]&&yollar[dYolu][bas]==anaYollar[zYolu][bas])return 2;

    }

    return 1;


}
void aracSayisiAl(char yolAdi,int *aracsayisi,int * bilinmeyenSayisi){

    while(1) {
        printf("\n%c yolundaki arac yogunlugunu giriniz(bilgi yok ise : -1 girin) : ", yolAdi);
        scanf("%s",TEMP);
        *aracsayisi = atoi(TEMP);
        if (*aracsayisi == 0 || *aracsayisi<-1){
            printf("Lutfen gecerli bir arac yogunlugu girin:\n");
            continue;
        }
        if (*aracsayisi == -1)*bilinmeyenSayisi += 1;

        break;}

}
//matrisOlustur(N,matris,sonucMatrisi,bilinmeyenlerMatrisi,yollar,anaYollar);
void matrisSifirla(int R,int N,int matris[R][N],int sonucMatrisi[R]){
    for (int i = 0; i <R ; ++i) {
        for (int j = 0; j <N ; ++j) {
            matris[i][j]=0;

        }
        sonucMatrisi[i]=0;
    }
}
int celiskiKontrol(int dugumNo,int yollar[5][4],int anaYollar[4][4]){
    int son,toplam=0;
    if(dugumNo==5)son=0;
    else son=dugumNo;
    
    if(haritaSecimi==1){
        
        if(dugumNo==1){
            if(yollar[aYolu][son]==son)toplam-=yollar[aYolu][aracYogunlugu];
            else toplam+=yollar[aYolu][aracYogunlugu];
            
             if(yollar[cYolu][son]==son)toplam-=yollar[cYolu][aracYogunlugu];
            else toplam+=yollar[cYolu][aracYogunlugu];
            
             if(anaYollar[tYolu][son]==son)toplam-=anaYollar[tYolu][aracYogunlugu];
            else toplam+=anaYollar[tYolu][aracYogunlugu];
            
            if(toplam!=0)return -1;
        }else if(dugumNo==2){
            if(yollar[aYolu][son]==son)toplam-=yollar[aYolu][aracYogunlugu];
            else toplam+=yollar[aYolu][aracYogunlugu];
            
             if(yollar[bYolu][son]==son)toplam-=yollar[bYolu][aracYogunlugu];
            else toplam+=yollar[bYolu][aracYogunlugu];
            
             if(anaYollar[xYolu][son]==son)toplam-=anaYollar[xYolu][aracYogunlugu];
            else toplam+=anaYollar[xYolu][aracYogunlugu];
            
            if(toplam!=0)return -1;
            
        }else if(dugumNo==3){
            if(yollar[dYolu][son]==son)toplam-=yollar[dYolu][aracYogunlugu];
            else toplam+=yollar[dYolu][aracYogunlugu];
            
             if(yollar[bYolu][son]==son)toplam-=yollar[bYolu][aracYogunlugu];
            else toplam+=yollar[bYolu][aracYogunlugu];
            
             if(anaYollar[yYolu][son]==son)toplam-=anaYollar[yYolu][aracYogunlugu];
            else toplam+=anaYollar[yYolu][aracYogunlugu];
            
            if(toplam!=0)return -1;
            
        }
        else if(dugumNo==4){
            if(yollar[dYolu][son]==son)toplam-=yollar[dYolu][aracYogunlugu];
            else toplam+=yollar[dYolu][aracYogunlugu];
            
             if(yollar[cYolu][son]==son)toplam-=yollar[cYolu][aracYogunlugu];
            else toplam+=yollar[cYolu][aracYogunlugu];
            
             if(anaYollar[zYolu][son]==son)toplam-=anaYollar[zYolu][aracYogunlugu];
            else toplam+=anaYollar[zYolu][aracYogunlugu];
            
            if(toplam!=0)return -1;
            
        }
        else if(dugumNo==5){
            if(anaYollar[tYolu][son]==son)toplam-=anaYollar[tYolu][aracYogunlugu];
            else toplam+=anaYollar[tYolu][aracYogunlugu];
            
             if(anaYollar[xYolu][son]==son)toplam-=anaYollar[xYolu][aracYogunlugu];
            else toplam+=anaYollar[xYolu][aracYogunlugu];
            
             if(anaYollar[yYolu][son]==son)toplam-=anaYollar[yYolu][aracYogunlugu];
            else toplam+=anaYollar[yYolu][aracYogunlugu];
            
            if(anaYollar[zYolu][son]==son)toplam-=anaYollar[zYolu][aracYogunlugu];
            else toplam+=anaYollar[zYolu][aracYogunlugu];
            
            if(toplam!=0)return -1;
            
        }
        
    }else{
        
        if(dugumNo==1){
            if(yollar[aYolu][son]==son)toplam-=yollar[aYolu][aracYogunlugu];
            else toplam+=yollar[aYolu][aracYogunlugu];
            
             if(yollar[cYolu][son]==son)toplam-=yollar[cYolu][aracYogunlugu];
            else toplam+=yollar[cYolu][aracYogunlugu];
            
            if(yollar[eYolu][son]==son)toplam-=yollar[eYolu][aracYogunlugu];
            else toplam+=yollar[eYolu][aracYogunlugu];
            
             if(anaYollar[tYolu][son]==son)toplam-=anaYollar[tYolu][aracYogunlugu];
            else toplam+=anaYollar[tYolu][aracYogunlugu];
            
            if(toplam!=0)return -1;
        }else if(dugumNo==2){
            if(yollar[aYolu][son]==son)toplam-=yollar[aYolu][aracYogunlugu];
            else toplam+=yollar[aYolu][aracYogunlugu];
            
             if(yollar[bYolu][son]==son)toplam-=yollar[bYolu][aracYogunlugu];
            else toplam+=yollar[bYolu][aracYogunlugu];
            
             if(anaYollar[xYolu][son]==son)toplam-=anaYollar[xYolu][aracYogunlugu];
            else toplam+=anaYollar[xYolu][aracYogunlugu];
            
            if(toplam!=0)return -1;
            
        }else if(dugumNo==3){
            if(yollar[dYolu][son]==son)toplam-=yollar[dYolu][aracYogunlugu];
            else toplam+=yollar[dYolu][aracYogunlugu];
            
             if(yollar[bYolu][son]==son)toplam-=yollar[bYolu][aracYogunlugu];
            else toplam+=yollar[bYolu][aracYogunlugu];
            
            if(yollar[eYolu][son]==son)toplam-=yollar[eYolu][aracYogunlugu];
            else toplam+=yollar[eYolu][aracYogunlugu];
            
             if(anaYollar[yYolu][son]==son)toplam-=anaYollar[yYolu][aracYogunlugu];
            else toplam+=anaYollar[yYolu][aracYogunlugu];
            
            if(toplam!=0)return -1;
            
        }
        else if(dugumNo==4){
            if(yollar[dYolu][son]==son)toplam-=yollar[dYolu][aracYogunlugu];
            else toplam+=yollar[dYolu][aracYogunlugu];
            
             if(yollar[cYolu][son]==son)toplam-=yollar[cYolu][aracYogunlugu];
            else toplam+=yollar[cYolu][aracYogunlugu];
            
             if(anaYollar[zYolu][son]==son)toplam-=anaYollar[zYolu][aracYogunlugu];
            else toplam+=anaYollar[zYolu][aracYogunlugu];
            
            if(toplam!=0)return -1;
            
        }
        else if(dugumNo==5){
            if(anaYollar[tYolu][son]==son)toplam-=anaYollar[tYolu][aracYogunlugu];
            else toplam+=anaYollar[tYolu][aracYogunlugu];
            
             if(anaYollar[xYolu][son]==son)toplam-=anaYollar[xYolu][aracYogunlugu];
            else toplam+=anaYollar[xYolu][aracYogunlugu];
            
             if(anaYollar[yYolu][son]==son)toplam-=anaYollar[yYolu][aracYogunlugu];
            else toplam+=anaYollar[yYolu][aracYogunlugu];
            
            if(anaYollar[zYolu][son]==son)toplam-=anaYollar[zYolu][aracYogunlugu];
            else toplam+=anaYollar[zYolu][aracYogunlugu];
            
            if(toplam!=0)return -1;
            
        }
        
    }
    
}
void matrisOlustur(int R,int N,int matris[R][N],int sonucMatrisi[R],char bilinmeyenlerMatrisi[N],int yollar[5][4],int anaYollar[4][4]){
    int k=0;
    for (int i = 1; i <6 ; ++i) {
        if(dugumKontrol(i,yollar,anaYollar)==0){
            celiski=celiskiKontrol(i,yollar,anaYollar);continue;
        }
        dugumCoz(N,i,matris[k],&sonucMatrisi[k],bilinmeyenlerMatrisi,yollar,anaYollar);
        k++;
        if(k==R)break;
    }
}
void matrisCiz(int R,int N,int matris[R][N],int sonucMatrisi[R],char bilinmeyenlerMatrisi[N]){
    for (int k = 0; k <N ; ++k) {
        printf("%3c",bilinmeyenlerMatrisi[k]);
    }
    printf("\n");
    for (int i = 0; i <R ; ++i) {
        for (int j = 0; j <N ; ++j) {
            printf("%3d",matris[i][j]);

        }
        printf("  | %d\n",sonucMatrisi[i]);

    }


}


void gaussAdimYazici(int R,int N,int matris[R][N],int sonucMatrisi[R],int durum,int islemYapilanSatirIndis,int islemYapilanSatirIndis2,int sayi){



    if (durum==1){

            for (int i = 0; i <R ; ++i) {

            for (int j = 0; j <N ; ++j) {
            printf("%3d",matris[i][j]);

            }

                if(i==R/2){
                    printf("  | %-3d      R%d --> R%d * %d\n",sonucMatrisi[i],islemYapilanSatirIndis+1,islemYapilanSatirIndis+1,sayi);

                }else  printf("  | %d\n",sonucMatrisi[i]);
            }

            printf("\n");

    }else if(durum==2){

        for (int i = 0; i <R ; ++i) {

            for (int j = 0; j <N ; ++j) {
                printf("%3d",matris[i][j]);

            }

            if(i==R/2){
                printf("  | %-3d      R%d <--> R%d\n",sonucMatrisi[i],islemYapilanSatirIndis+1,islemYapilanSatirIndis2+1);

            }else  printf("  | %d\n",sonucMatrisi[i]);
        }

        printf("\n");




    }else if (durum==3){

        for (int i = 0; i <R ; ++i) {

            for (int j = 0; j <N ; ++j) {
                printf("%3d",matris[i][j]);

            }

            if(i==R/2){
                printf("  | %-3d      R%d --> R%d - R%d * %d\n",sonucMatrisi[i],islemYapilanSatirIndis+1,islemYapilanSatirIndis+1,islemYapilanSatirIndis2+1,sayi);

            }else  printf("  | %d\n",sonucMatrisi[i]);
        }

        printf("\n");

    }


}

void gauss(int R,int N,int matris[R][N],int sonucMatrisi[R]){

    int temp;float a;

    for (int i = 0; i <R ; ++i) {
        
        if(matris[i][i]!=0){
            a=(float)1/matris[i][i];
            for (int j = 0; j <N ; ++j) {
                matris[i][j]*=a;


            }
            sonucMatrisi[i]*=a;
            gaussAdimYazici(R,N,matris,sonucMatrisi,1,i,0,a);
        }

        if(matris[i][i]!=1){

            for (int j = i+1; j <R ; ++j) {

                if(matris[j][i]!=0){
                    a=(float)1/matris[j][i];
                    for (int k = 0; k <N ; ++k) {
                        matris[j][k]*=a;

                    }
                    sonucMatrisi[j]*=a;

                    for (int l = 0; l <N ; ++l) {
                        temp=matris[j][l];
                        matris[j][l]=matris[i][l];
                        matris[i][l]=temp;

                    }
                    temp=sonucMatrisi[j];
                    sonucMatrisi[j]=sonucMatrisi[i];
                    sonucMatrisi[i]=temp;
                    gaussAdimYazici(R,N,matris,sonucMatrisi,2,i,j,a);
                    break;
                }

            }
        }

        if(matris[i][i]!=1)continue;

        for (int m = i+1; m <R ; ++m) {

            if(matris[m][i]!=0){
                a=(float)matris[m][i];

                for (int j = 0; j <N ; ++j) {
                    matris[m][j]-=matris[i][j]*a;
                }
                sonucMatrisi[m]-=sonucMatrisi[i]*a;

                gaussAdimYazici(R,N,matris,sonucMatrisi,3,m,i,a);

            }



        }


    }

    for (int n = 0; n <R-1 ; ++n) {


        for (int i = n+1; i <R ; ++i) {
            if(matris[n][i]==0)continue;
            if(matris[i][i]==0)continue;
            a=matris[n][i];
            for (int j = 0; j <N ; ++j) {
                matris[n][j]-=a*matris[i][j];

            }
            sonucMatrisi[n]-=a*sonucMatrisi[i];


            gaussAdimYazici(R,N,matris,sonucMatrisi,3,n,i,a);
        }


    }

}
//dugumCoz(N,i,matris[k],&sonucMatrisi[k],bilinmeyenlerMatrisi,yollar,anaYollar);


void dugumCoz(int N,int dugumNo,int *matrisSatir,int *matrisSatirSonuc,char bilinmeyenlerMatrisi[N],int yollar[5][4],int anaYollar[4][4]){
    if(haritaSecimi==1) {
        if (dugumNo == 1) {
            if(yollar[aYolu][aracYogunlugu]==-1){
                if(yollar[aYolu][son]==1) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'a')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'a')]+=1;
            }else{
                if(yollar[aYolu][son]==1) *matrisSatirSonuc-=yollar[aYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[aYolu][aracYogunlugu];
            }

            if(yollar[cYolu][aracYogunlugu]==-1){
                if(yollar[cYolu][son]==1) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'c')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'c')]+=1;
            }else{
                if(yollar[cYolu][son]==1) *matrisSatirSonuc-=yollar[cYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[cYolu][aracYogunlugu];
            }

            if(anaYollar[tYolu][aracYogunlugu]==-1){
                if(anaYollar[tYolu][son]==1) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'t')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'t')]+=1;
            }else{
                if(anaYollar[tYolu][son]==1) *matrisSatirSonuc-=anaYollar[tYolu][aracYogunlugu];
                else *matrisSatirSonuc+=anaYollar[tYolu][aracYogunlugu];
            }
        }

        else if (dugumNo == 2) {
            if(yollar[aYolu][aracYogunlugu]==-1){
                if(yollar[aYolu][son]==2) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'a')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'a')]+=1;
            }else{
                if(yollar[aYolu][son]==2) *matrisSatirSonuc-=yollar[aYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[aYolu][aracYogunlugu];
            }

            if(yollar[bYolu][aracYogunlugu]==-1){
                if(yollar[bYolu][son]==2) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'b')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'b')]+=1;
            }else{
                if(yollar[bYolu][son]==2) *matrisSatirSonuc-=yollar[bYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[bYolu][aracYogunlugu];
            }

            if(anaYollar[xYolu][aracYogunlugu]==-1){
                if(anaYollar[xYolu][son]==2) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'x')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'x')]+=1;
            }else{
                if(anaYollar[xYolu][son]==2) *matrisSatirSonuc-=anaYollar[xYolu][aracYogunlugu];
                else *matrisSatirSonuc+=anaYollar[xYolu][aracYogunlugu];
            }
        }

        else if (dugumNo == 3) {
            if(yollar[dYolu][aracYogunlugu]==-1){
                if(yollar[dYolu][son]==3) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'d')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'d')]+=1;
            }else{
                if(yollar[dYolu][son]==3) *matrisSatirSonuc-=yollar[dYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[dYolu][aracYogunlugu];
            }

            if(yollar[bYolu][aracYogunlugu]==-1){
                if(yollar[bYolu][son]==3) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'b')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'b')]+=1;
            }else{
                if(yollar[bYolu][son]==3) *matrisSatirSonuc-=yollar[bYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[bYolu][aracYogunlugu];
            }

            if(anaYollar[yYolu][aracYogunlugu]==-1){
                if(anaYollar[yYolu][son]==3) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'y')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'y')]+=1;
            }else{
                if(anaYollar[yYolu][son]==3) *matrisSatirSonuc-=anaYollar[yYolu][aracYogunlugu];
                else *matrisSatirSonuc+=anaYollar[yYolu][aracYogunlugu];
            }
        }
        else if (dugumNo ==4) {
            if(yollar[dYolu][aracYogunlugu]==-1){
                if(yollar[dYolu][son]==4) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'d')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'d')]+=1;
            }else{
                if(yollar[dYolu][son]==4) *matrisSatirSonuc-=yollar[dYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[dYolu][aracYogunlugu];
            }

            if(yollar[cYolu][aracYogunlugu]==-1){
                if(yollar[cYolu][son]==4) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'c')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'c')]+=1;
            }else{
                if(yollar[cYolu][son]==4) *matrisSatirSonuc-=yollar[cYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[cYolu][aracYogunlugu];
            }

            if(anaYollar[zYolu][aracYogunlugu]==-1){
                if(anaYollar[zYolu][son]==4) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'z')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'z')]+=1;
            }else{
                if(anaYollar[zYolu][son]==4) *matrisSatirSonuc-=anaYollar[zYolu][aracYogunlugu];
                else *matrisSatirSonuc+=anaYollar[zYolu][aracYogunlugu];
            }
        }


        else if (dugumNo ==5) {

            if(anaYollar[yYolu][aracYogunlugu]==-1){
                if(anaYollar[yYolu][son]==0) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'y')]+=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'y')]-=1;
            }else{
                if(anaYollar[yYolu][son]==0) *matrisSatirSonuc+=anaYollar[yYolu][aracYogunlugu];
                else *matrisSatirSonuc-=anaYollar[yYolu][aracYogunlugu];
            }

            if(anaYollar[xYolu][aracYogunlugu]==-1){
                if(anaYollar[xYolu][son]==0) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'x')]+=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'x')]-=1;
            }else{
                if(anaYollar[xYolu][son]==0) *matrisSatirSonuc+=anaYollar[xYolu][aracYogunlugu];
                else *matrisSatirSonuc-=anaYollar[xYolu][aracYogunlugu];
            }


            if(anaYollar[tYolu][aracYogunlugu]==-1){
                if(anaYollar[tYolu][son]==0) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'t')]+=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'t')]-=1;
            }else{
                if(anaYollar[tYolu][son]==0) *matrisSatirSonuc+=anaYollar[tYolu][aracYogunlugu];
                else *matrisSatirSonuc-=anaYollar[tYolu][aracYogunlugu];
            }


            if(anaYollar[zYolu][aracYogunlugu]==-1){
                if(anaYollar[zYolu][son]==0) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'z')]+=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'z')]-=1;
            }else{
                if(anaYollar[zYolu][son]==0) *matrisSatirSonuc+=anaYollar[zYolu][aracYogunlugu];
                else *matrisSatirSonuc-=anaYollar[zYolu][aracYogunlugu];
            }
        }


    }else {
        if (dugumNo == 1) {
            if(yollar[aYolu][aracYogunlugu]==-1){
                if(yollar[aYolu][son]==1) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'a')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'a')]+=1;
            }else{
                if(yollar[aYolu][son]==1) *matrisSatirSonuc-=yollar[aYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[aYolu][aracYogunlugu];
            }
            if(yollar[eYolu][aracYogunlugu]==-1){
                if(yollar[eYolu][son]==1) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'e')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'e')]+=1;
            }else{
                if(yollar[eYolu][son]==1) *matrisSatirSonuc-=yollar[eYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[eYolu][aracYogunlugu];
            }

            if(yollar[cYolu][aracYogunlugu]==-1){
                if(yollar[cYolu][son]==1) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'c')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'c')]+=1;
            }else{
                if(yollar[cYolu][son]==1) *matrisSatirSonuc-=yollar[cYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[cYolu][aracYogunlugu];
            }

            if(anaYollar[tYolu][aracYogunlugu]==-1){
                if(anaYollar[tYolu][son]==1) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'t')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'t')]+=1;
            }else{
                if(anaYollar[tYolu][son]==1) *matrisSatirSonuc-=anaYollar[tYolu][aracYogunlugu];
                else *matrisSatirSonuc+=anaYollar[tYolu][aracYogunlugu];
            }
        }

        else if (dugumNo == 2) {
            if(yollar[aYolu][aracYogunlugu]==-1){
                if(yollar[aYolu][son]==2) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'a')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'a')]+=1;
            }else{
                if(yollar[aYolu][son]==2) *matrisSatirSonuc-=yollar[aYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[aYolu][aracYogunlugu];
            }

            if(yollar[bYolu][aracYogunlugu]==-1){
                if(yollar[bYolu][son]==2) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'b')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'b')]+=1;
            }else{
                if(yollar[bYolu][son]==2) *matrisSatirSonuc-=yollar[bYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[bYolu][aracYogunlugu];
            }

            if(anaYollar[xYolu][aracYogunlugu]==-1){
                if(anaYollar[xYolu][son]==2) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'x')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'x')]+=1;
            }else{
                if(anaYollar[xYolu][son]==2) *matrisSatirSonuc-=anaYollar[xYolu][aracYogunlugu];
                else *matrisSatirSonuc+=anaYollar[xYolu][aracYogunlugu];
            }
        }

        else if (dugumNo == 3) {
            if(yollar[dYolu][aracYogunlugu]==-1){
                if(yollar[dYolu][son]==3) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'d')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'d')]+=1;
            }else{
                if(yollar[dYolu][son]==3) *matrisSatirSonuc-=yollar[dYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[dYolu][aracYogunlugu];
            }
            if(yollar[eYolu][aracYogunlugu]==-1){
                if(yollar[eYolu][son]==3) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'e')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'e')]+=1;
            }else{
                if(yollar[eYolu][son]==3) *matrisSatirSonuc-=yollar[eYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[eYolu][aracYogunlugu];
            }

            if(yollar[bYolu][aracYogunlugu]==-1){
                if(yollar[bYolu][son]==3) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'b')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'b')]+=1;
            }else{
                if(yollar[bYolu][son]==3) *matrisSatirSonuc-=yollar[bYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[bYolu][aracYogunlugu];
            }

            if(anaYollar[yYolu][aracYogunlugu]==-1){
                if(anaYollar[yYolu][son]==3) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'y')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'y')]+=1;
            }else{
                if(anaYollar[yYolu][son]==3) *matrisSatirSonuc-=anaYollar[yYolu][aracYogunlugu];
                else *matrisSatirSonuc+=anaYollar[yYolu][aracYogunlugu];
            }
        }
        else if (dugumNo ==4) {
            if(yollar[dYolu][aracYogunlugu]==-1){
                if(yollar[dYolu][son]==4) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'d')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'d')]+=1;
            }else{
                if(yollar[dYolu][son]==4) *matrisSatirSonuc-=yollar[dYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[dYolu][aracYogunlugu];
            }

            if(yollar[cYolu][aracYogunlugu]==-1){
                if(yollar[cYolu][son]==4) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'c')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'c')]+=1;
            }else{
                if(yollar[cYolu][son]==4) *matrisSatirSonuc-=yollar[cYolu][aracYogunlugu];
                else *matrisSatirSonuc+=yollar[cYolu][aracYogunlugu];
            }

            if(anaYollar[zYolu][aracYogunlugu]==-1){
                if(anaYollar[zYolu][son]==4) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'z')]-=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'z')]+=1;
            }else{
                if(anaYollar[zYolu][son]==4) *matrisSatirSonuc-=anaYollar[zYolu][aracYogunlugu];
                else *matrisSatirSonuc+=anaYollar[zYolu][aracYogunlugu];
            }
        }
        else if (dugumNo ==5) {

            if(anaYollar[yYolu][aracYogunlugu]==-1){
                if(anaYollar[yYolu][son]==0) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'y')]+=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'y')]-=1;
            }else{
                if(anaYollar[yYolu][son]==0) *matrisSatirSonuc+=anaYollar[yYolu][aracYogunlugu];
                else *matrisSatirSonuc-=anaYollar[yYolu][aracYogunlugu];
            }

            if(anaYollar[xYolu][aracYogunlugu]==-1){
                if(anaYollar[xYolu][son]==0) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'x')]+=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'x')]-=1;
            }else{
                if(anaYollar[xYolu][son]==0) *matrisSatirSonuc+=anaYollar[xYolu][aracYogunlugu];
                else *matrisSatirSonuc-=anaYollar[xYolu][aracYogunlugu];
            }


            if(anaYollar[tYolu][aracYogunlugu]==-1){
                if(anaYollar[tYolu][son]==0) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'t')]+=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'t')]-=1;
            }else{
                if(anaYollar[tYolu][son]==0) *matrisSatirSonuc+=anaYollar[tYolu][aracYogunlugu];
                else *matrisSatirSonuc-=anaYollar[tYolu][aracYogunlugu];
            }


            if(anaYollar[zYolu][aracYogunlugu]==-1){
                if(anaYollar[zYolu][son]==0) matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'z')]+=1;
                else matrisSatir[indexBul(bilinmeyenlerMatrisi,N,'z')]-=1;
            }else{
                if(anaYollar[zYolu][son]==0) *matrisSatirSonuc+=anaYollar[zYolu][aracYogunlugu];
                else *matrisSatirSonuc-=anaYollar[zYolu][aracYogunlugu];
            }
        }



    }

    (*matrisSatirSonuc)*=-1;
}
int dugumKontrol(int dugumNo,int yollar[5][4],int anaYollar[4][4]){
    int kontrol=0;
    if(haritaSecimi==1) {
        if (dugumNo == 1) {
            if (anaYollar[tYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[aYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[cYolu][aracYogunlugu] == -1)kontrol = 1;
        }
        else if (dugumNo == 2) {
            if (anaYollar[xYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[aYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[bYolu][aracYogunlugu] == -1)kontrol = 1;
        }
        else if (dugumNo == 3) {
            if (anaYollar[yYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[bYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[dYolu][aracYogunlugu] == -1)kontrol = 1;
        }
        else if (dugumNo == 4) {
            if (anaYollar[zYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[cYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[dYolu][aracYogunlugu] == -1)kontrol = 1;
        }
        else if (dugumNo == 5) {
            if (anaYollar[zYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (anaYollar[tYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (anaYollar[xYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (anaYollar[yYolu][aracYogunlugu] == -1)kontrol = 1;
        }


    }else{
        if (dugumNo == 1) {
            if (anaYollar[tYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[aYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[cYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[eYolu][aracYogunlugu] == -1)kontrol = 1;

        }
        if (dugumNo == 2) {
            if (anaYollar[xYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[aYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[bYolu][aracYogunlugu] == -1)kontrol = 1;
        }
        if (dugumNo == 3) {
            if (anaYollar[yYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[bYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[dYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[eYolu][aracYogunlugu] == -1)kontrol = 1;
        }
        if (dugumNo == 4) {
            if (anaYollar[zYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[cYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (yollar[dYolu][aracYogunlugu] == -1)kontrol = 1;
        }
        else if (dugumNo == 5) {
            if (anaYollar[zYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (anaYollar[tYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (anaYollar[xYolu][aracYogunlugu] == -1)kontrol = 1;
            else if (anaYollar[yYolu][aracYogunlugu] == -1)kontrol = 1;
        }



    }

    return kontrol;
}



void bilinmeyenlerMatrisiniOlustur(int N,char matris[N],int yollar[5][4],int anaYollar[4][4]){
    int j=0;
    if(haritaSecimi==1){
        for (int i = aYolu; i <=dYolu ; i++) {
            if(yollar[i][aracYogunlugu]==-1){
                matris[j]=(char)yollar[i][isim];j++;}

        }
        for (int i = tYolu; i <=zYolu ; i++) {
            if(anaYollar[i][aracYogunlugu]==-1){
                matris[j]=(char)anaYollar[i][isim];j++;}

        }


    }else {

        for (int i = aYolu; i <= eYolu; i++) {
            if (yollar[i][aracYogunlugu] == -1){
                matris[j]=(char)yollar[i][isim];j++;}

        }
        for (int i = tYolu; i <= zYolu; i++) {
            if (anaYollar[i][aracYogunlugu] == -1){
                matris[j]=(char)anaYollar[i][isim];j++;}

        }
    }
}

void isimleriGir(int a[5][4],int b[4][4]){
    a[aYolu][isim]=(int)'a';
    a[bYolu][isim]=(int)'b';
    a[cYolu][isim]=(int)'c';
    a[dYolu][isim]=(int)'d';
    a[eYolu][isim]=(int)'e';
    b[tYolu][isim]=(int)'t';
    b[xYolu][isim]=(int)'x';
    b[yYolu][isim]=(int)'y';
    b[zYolu][isim]=(int)'z';}

int indexBul(const char *dizi,int N,int aranan){
    for (int i = 0; i <N ; ++i) {
        if(dizi[i]==aranan){
            return i;
        }
    }
    return -1;
}




void allegroGiris(){

    int w = 880;
    int h = 480;

    ALLEGRO_DISPLAY *display = NULL;


    if (!al_init()) {
        al_show_native_message_box(display, NULL, "HATA", "Allegro baslatilamadi !", NULL,
                                   ALLEGRO_MESSAGEBOX_ERROR);
    }

    display = al_create_display(w, h);

    al_init_font_addon(); //font addon başlatıcı
    al_init_ttf_addon(); //ttf addon başlatıcı
    al_init_primitives_addon(); //primitives addon başlatıcı
    al_init_image_addon();//image addon başlatıcı

    al_clear_to_color(al_map_rgb(255, 255, 255));     //void al_clear_to_color(ALLEGRO_COLOR color)

    ALLEGRO_FONT *font24 = al_load_font("BalooBhai-Regular.ttf", 36,
                                        0); //ALLEGRO_FONT *al_load_font(char const *filename, int size, int flags)

    al_draw_text(font24, al_map_rgb(230, 24, 45), 160, 0, 0, "HARİTA-1"); /*void al_draw_text(const ALLEGRO_FONT *font,ALLEGRO_COLOR color, float x, float y, int flags,char const *text)
                                                                             *
                                                                                               =Flags=
                                                                                                ALLEGRO_ALIGN_LEFT - Draw the text left-aligned (same as 0).
                                                                                                ALLEGRO_ALIGN_CENTRE - Draw the text centered around the given position.
                                                                                                ALLEGRO_ALIGN_RIGHT - Draw the text right-aligned to the given position.
                                                                                     */
    al_draw_text(font24, al_map_rgb(230, 24, 45), 568, 0, 0, "HARİTA-2");
    ALLEGRO_BITMAP *image1 = al_load_bitmap("map.png");
    ALLEGRO_BITMAP *image2 = al_load_bitmap("map2.png");
    al_draw_bitmap(image1, 50, 50, 0);
    al_draw_bitmap(image2, 465, 50, 0);
    al_flip_display();

}
void allegroHarita(){
    ALLEGRO_BITMAP *harita;ALLEGRO_FONT *font24 = al_load_font("BalooBhai-Regular.ttf", 36, 0);
    if(haritaSecimi==1) harita= al_load_bitmap("map.png");
    else harita = al_load_bitmap("map2.png");
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_bitmap(harita, 261, 60.5, 0);
    if(haritaSecimi==1)
        al_draw_text(font24, al_map_rgb(250, 24, 45), 350, 0, 0, "HARİTA -1-");
    else al_draw_text(font24, al_map_rgb(250, 24, 45), 350, 0, 0, "HARİTA -2-");
    al_flip_display();


}

void allegroYonleriCiz(int aSon,int bSon,int cSon,int dSon,int eSon,int tSon,int xSon,int ySon,int zSon){
    ALLEGRO_BITMAP *aYon1,*aYon2,*aYon3;
    float aX1,aX2,aX3,aY1,aY2,aY3;
    ALLEGRO_BITMAP *bYon1,*bYon2,*bYon3;
    float bX1,bX2,bX3,bY1,bY2,bY3;
    ALLEGRO_BITMAP *cYon1,*cYon2,*cYon3;
    float cX1,cX2,cX3,cY1,cY2,cY3;
    ALLEGRO_BITMAP *dYon1,*dYon2,*dYon3;
    float dX1,dX2,dX3,dY1,dY2,dY3;
    ALLEGRO_BITMAP *eYon1,*eYon2,*eYon3;
    float eX1,eX2,eX3,eY1,eY2,eY3;
    ALLEGRO_BITMAP *tYon1,*tYon2,*tYon3;
    float tX1,tX2,tX3,tY1,tY2,tY3;
    ALLEGRO_BITMAP *xYon1,*xYon2,*xYon3;
    float xX1,xX2,xX3,xY1,xY2,xY3;
    ALLEGRO_BITMAP *yYon1,*yYon2,*yYon3;
    float yX1,yX2,yX3,yY1,yY2,yY3;
    ALLEGRO_BITMAP *zYon1,*zYon2,*zYon3;
    float zX1,zX2,zX3,zY1,zY2,zY3;

    ALLEGRO_BITMAP *harita;ALLEGRO_FONT *font24 = al_load_font("BalooBhai-Regular.ttf", 36, 0);
    if(haritaSecimi==1) harita= al_load_bitmap("map.png");
    else harita = al_load_bitmap("map2.png");
    ALLEGRO_BITMAP *a1_12 = al_load_bitmap("a1-12-x85y122.png");
    ALLEGRO_BITMAP *a2_12 = al_load_bitmap("a2-12-x99y99.png");
    ALLEGRO_BITMAP *a3_12 = al_load_bitmap("a3-12-x112y84.png");
    ALLEGRO_BITMAP *a1_21 = al_load_bitmap("a1-21-120_84.png");
    ALLEGRO_BITMAP *a2_21 = al_load_bitmap("a2-21-101_99.png");
    ALLEGRO_BITMAP *a3_21 = al_load_bitmap("a3-21-83_128.png");
    ALLEGRO_BITMAP *b23_1 = al_load_bitmap("b23_1_201_83.png");
    ALLEGRO_BITMAP *b23_2 = al_load_bitmap("b23_2_232_100.png");
    ALLEGRO_BITMAP *b23_3 = al_load_bitmap("b23_3_252_127.png");
    ALLEGRO_BITMAP *b32_1 = al_load_bitmap("b32_1_253_126.png");
    ALLEGRO_BITMAP *b32_2 = al_load_bitmap("b32_2_227_101.png");
    ALLEGRO_BITMAP *b32_3 = al_load_bitmap("b32_3_200_83.png");
    ALLEGRO_BITMAP *c14_1 = al_load_bitmap("c_1_85_201.png");
    ALLEGRO_BITMAP *c14_2 = al_load_bitmap("c_2_101_232.png");
    ALLEGRO_BITMAP *c14_3 = al_load_bitmap("c_3_128_252.png");
    ALLEGRO_BITMAP *c41_1 = al_load_bitmap("c41_1_125_255.png");
    ALLEGRO_BITMAP *c41_2 = al_load_bitmap("c41_2_105_225.png");
    ALLEGRO_BITMAP *c41_3 = al_load_bitmap("c41_3_89_196.png");
    ALLEGRO_BITMAP *d34_1 = al_load_bitmap("d34_1_254_177.png");
    ALLEGRO_BITMAP *d34_2 = al_load_bitmap("d34_2_234_214.png");
    ALLEGRO_BITMAP *d34_3 = al_load_bitmap("d34_3_207_240.png");
    ALLEGRO_BITMAP *d43_1 = al_load_bitmap("d43_1_205_244.png");
    ALLEGRO_BITMAP *d43_2 = al_load_bitmap("d43_2_233_213.png");
    ALLEGRO_BITMAP *d43_3 = al_load_bitmap("d43_3_205_183.png");
    ALLEGRO_BITMAP *e13_1 = al_load_bitmap("e13_1_142_168.png");
    ALLEGRO_BITMAP *e13_2 = al_load_bitmap("e13_2_166_168.png");
    ALLEGRO_BITMAP *e13_3 = al_load_bitmap("e13_3_188_168.png");
    ALLEGRO_BITMAP *e31_1 = al_load_bitmap("e31_1_188_168.png");
    ALLEGRO_BITMAP *e31_2 = al_load_bitmap("e31_2_166_168.png");
    ALLEGRO_BITMAP *e31_3 = al_load_bitmap("e31_3_142_168.png");
    ALLEGRO_BITMAP *t01_1 = al_load_bitmap("t01_1_0_165.png");
    ALLEGRO_BITMAP *t01_2 = al_load_bitmap("t01_2_22_165.png");
    ALLEGRO_BITMAP *t01_3 = al_load_bitmap("t01_3_46_165.png");
    ALLEGRO_BITMAP *t10_1 = al_load_bitmap("t10_1_46_165.png");
    ALLEGRO_BITMAP *t10_2 = al_load_bitmap("t10_2_22_165.png");
    ALLEGRO_BITMAP *t10_3 = al_load_bitmap("t10_3_0_165.png");
    ALLEGRO_BITMAP *x02_1 = al_load_bitmap("x02_1_0_166.png");
    ALLEGRO_BITMAP *x02_2 = al_load_bitmap("x02_2_22_166.png");
    ALLEGRO_BITMAP *x02_3 = al_load_bitmap("x02_3_43_166.png");
    ALLEGRO_BITMAP *x20_1 = al_load_bitmap("x20_1_0_166.png");
    ALLEGRO_BITMAP *x20_2 = al_load_bitmap("x20_2_22_166.png");
    ALLEGRO_BITMAP *x20_3 = al_load_bitmap("x20_3_43_166.png");
    ALLEGRO_BITMAP *y03_1 = al_load_bitmap("y03_1_332_165.png");
    ALLEGRO_BITMAP *y03_2 = al_load_bitmap("y03_2_310_165.png");
    ALLEGRO_BITMAP *y03_3 = al_load_bitmap("y03_3_289_165.png");
    ALLEGRO_BITMAP *y30_1 = al_load_bitmap("y30_1_289_165.png");
    ALLEGRO_BITMAP *y30_2 = al_load_bitmap("y30_2_310_165.png");
    ALLEGRO_BITMAP *y30_3 = al_load_bitmap("y30_3_332_165.png");
    ALLEGRO_BITMAP *z04_1 = al_load_bitmap("z04_1_333_166.png");
    ALLEGRO_BITMAP *z04_2 = al_load_bitmap("z04_2_312_166.png");
    ALLEGRO_BITMAP *z04_3 = al_load_bitmap("z04_3_290_166.png");
    ALLEGRO_BITMAP *z40_1 = al_load_bitmap("z40_1_290_166.png");
    ALLEGRO_BITMAP *z40_2 = al_load_bitmap("z40_2_312_166.png");
    ALLEGRO_BITMAP *z40_3 = al_load_bitmap("z40_3_333_166.png");


    if(haritaSecimi==1){

        if(aSon==2){
            aYon1=a1_12;
            aYon2=a2_12;
            aYon3=a3_12;
            aX1=85;
            aX2=99;
            aX3=112;
            aY1=122;
            aY2=99;
            aY3=94;
        }else{
            aYon1=a1_21;
            aYon2=a2_21;
            aYon3=a3_21;
            aX1=120;
            aX2=101;
            aX3=83;
            aY1=84;
            aY2=99;
            aY3=128;

        }

        if(bSon==3){
            bYon1=b23_1;
            bYon2=b23_2;
            bYon3=b23_3;
            bX1=201;
            bX2=232;
            bX3=252;
            bY1=83;
            bY2=100;
            bY3=127;
        }else{
            bYon1=b32_1;
            bYon2=b32_2;
            bYon3=b32_3;
            bX1=253;
            bX2=227;
            bX3=200;
            bY1=126;
            bY2=101;
            bY3=83;

        }

        if(cSon==4){
            cYon1=c14_1;
            cYon2=c14_2;
            cYon3=c14_3;
            cX1=85;
            cX2=101;
            cX3=128;
            cY1=201;
            cY2=232;
            cY3=252;
        }else{
            cYon1=c41_1;
            cYon2=c41_2;
            cYon3=c41_3;
            cX1=125;
            cX2=105;
            cX3=89;
            cY1=255;
            cY2=225;
            cY3=196;

        }

        if(dSon==4){
            dYon1=d34_1;
            dYon2=d34_2;
            dYon3=d34_3;
            dX1=254;
            dX2=234;
            dX3=207;
            dY1=177;
            dY2=214;
            dY3=240;
        }else{
            dYon1=d43_1;
            dYon2=d43_2;
            dYon3=d43_3;
            dX1=205;
            dX2=233;
            dX3=255;
            dY1=244;
            dY2=213;
            dY3=183;

        }

        if(tSon==1){
            tYon1=t01_1;
            tYon2=t01_2;
            tYon3=t01_3;
            tX1=0;
            tX2=22;
            tX3=46;
            tY1=165;
            tY2=165;
            tY3=165;
        }else{
            tYon1=t10_1;
            tYon2=t10_2;
            tYon3=t10_3;
            tX1=46;
            tX2=22;
            tX3=0;
            tY1=165;
            tY2=165;
            tY3=165;

        }

        if(xSon==2){
            xYon1=x02_1;
            xYon2=x02_2;
            xYon3=x02_3;
            xX1=166;
            xX2=166;
            xX3=166;
            xY1=0;
            xY2=22;
            xY3=43;
        }else{
            xYon1=x20_1;
            xYon2=x20_2;
            xYon3=x20_3;
            xX1=166;
            xX2=166;
            xX3=166;
            xY1=43;
            xY2=22;
            xY3=0;

        }

        if(ySon==3){
            yYon1=y03_1;
            yYon2=y03_2;
            yYon3=y03_3;
            yX1=322;
            yX2=310;
            yX3=289;
            yY1=165;
            yY2=165;
            yY3=165;
        }else{
            yYon1=y30_1;
            yYon2=y30_2;
            yYon3=y30_3;
            yX1=289;
            yX2=310;
            yX3=322;
            yY1=165;
            yY2=165;
            yY3=165;

        }


        if(zSon==4){
            zYon1=z04_1;
            zYon2=z04_2;
            zYon3=z04_3;
            zX1=166;
            zX2=166;
            zX3=166;
            zY1=333;
            zY2=312;
            zY3=290;
        }else{
            zYon1=z40_1;
            zYon2=z40_2;
            zYon3=z40_3;
            zX1=166;
            zX2=166;
            zX3=166;
            zY1=290;
            zY2=312;
            zY3=333;

        }

    }else{

        if(aSon==2){
            aYon1=a1_12;
            aYon2=a2_12;
            aYon3=a3_12;
            aX1=85;
            aX2=99;
            aX3=112;
            aY1=122;
            aY2=99;
            aY3=94;
        }else{
            aYon1=a1_21;
            aYon2=a2_21;
            aYon3=a3_21;
            aX1=120;
            aX2=101;
            aX3=83;
            aY1=84;
            aY2=99;
            aY3=128;

        }

        if(bSon==3){
            bYon1=b23_1;
            bYon2=b23_2;
            bYon3=b23_3;
            bX1=201;
            bX2=232;
            bX3=252;
            bY1=83;
            bY2=100;
            bY3=127;
        }else{
            bYon1=b32_1;
            bYon2=b32_2;
            bYon3=b32_3;
            bX1=253;
            bX2=227;
            bX3=200;
            bY1=126;
            bY2=101;
            bY3=83;

        }

        if(cSon==4){
            cYon1=c14_1;
            cYon2=c14_2;
            cYon3=c14_3;
            cX1=85;
            cX2=101;
            cX3=128;
            cY1=201;
            cY2=232;
            cY3=252;
        }else{
            cYon1=c41_1;
            cYon2=c41_2;
            cYon3=c41_3;
            cX1=125;
            cX2=105;
            cX3=89;
            cY1=255;
            cY2=225;
            cY3=196;

        }

        if(dSon==4){
            dYon1=d34_1;
            dYon2=d34_2;
            dYon3=d34_3;
            dX1=254;
            dX2=234;
            dX3=207;
            dY1=177;
            dY2=214;
            dY3=240;
        }else{
            dYon1=d43_1;
            dYon2=d43_2;
            dYon3=d43_3;
            dX1=205;
            dX2=233;
            dX3=255;
            dY1=244;
            dY2=213;
            dY3=183;

        }
        if(eSon==3){
            eYon1=e13_1;
            eYon2=e13_2;
            eYon3=e13_3;
            eX1=142;
            eX2=166;
            eX3=188;
            eY1=168;
            eY2=168;
            eY3=168;
        }else{
            eYon1=e31_1;
            eYon2=e31_2;
            eYon3=e31_3;
            eX1=188;
            eX2=166;
            eX3=142;
            eY1=168;
            eY2=168;
            eY3=168;

        }

        if(tSon==1){
            tYon1=t01_1;
            tYon2=t01_2;
            tYon3=t01_3;
            tX1=0;
            tX2=22;
            tX3=46;
            tY1=165;
            tY2=165;
            tY3=165;
        }else{
            tYon1=t10_1;
            tYon2=t10_2;
            tYon3=t10_3;
            tX1=46;
            tX2=22;
            tX3=0;
            tY1=165;
            tY2=165;
            tY3=165;

        }

        if(xSon==2){
            xYon1=x02_1;
            xYon2=x02_2;
            xYon3=x02_3;
            xX1=166;
            xX2=166;
            xX3=166;
            xY1=0;
            xY2=22;
            xY3=43;
        }else{
            xYon1=x20_1;
            xYon2=x20_2;
            xYon3=x20_3;
            xX1=166;
            xX2=166;
            xX3=166;
            xY1=43;
            xY2=22;
            xY3=0;

        }

        if(ySon==3){
            yYon1=y03_1;
            yYon2=y03_2;
            yYon3=y03_3;
            yX1=322;
            yX2=310;
            yX3=289;
            yY1=165;
            yY2=165;
            yY3=165;
        }else{
            yYon1=y30_1;
            yYon2=y30_2;
            yYon3=y30_3;
            yX1=289;
            yX2=310;
            yX3=322;
            yY1=165;
            yY2=165;
            yY3=165;

        }


        if(zSon==4){
            zYon1=z04_1;
            zYon2=z04_2;
            zYon3=z04_3;
            zX1=166;
            zX2=166;
            zX3=166;
            zY1=333;
            zY2=312;
            zY3=290;
        }else{
            zYon1=z40_1;
            zYon2=z40_2;
            zYon3=z40_3;
            zX1=166;
            zX2=166;
            zX3=166;
            zY1=290;
            zY2=312;
            zY3=333;

        }

    }


    if (haritaSecimi==1) {
        for (int i = 0; i < 20; ++i) {

            delay(400000);
            al_flip_display();
            al_clear_to_color(al_map_rgb(255, 255, 255));
            al_draw_bitmap(harita, 261, 60.5, 0);
            if (i % 3 == 0) {
                al_draw_bitmap(aYon1, aX1 + 261, aY1 + 60.5, 0);
                al_draw_bitmap(bYon1, bX1 + 261, bY1 + 60.5, 0);
                al_draw_bitmap(cYon1, cX1 + 261, cY1 + 60.5, 0);
                al_draw_bitmap(dYon1, dX1 + 261, dY1 + 60.5, 0);
                al_draw_bitmap(tYon1, tX1 + 261, tY1 + 60.5, 0);
                al_draw_bitmap(xYon1, xX1 + 261, xY1 + 60.5, 0);
                al_draw_bitmap(yYon1, yX1 + 261, yY1 + 60.5, 0);
                al_draw_bitmap(zYon1, zX1 + 261, zY1 + 60.5, 0);

            }else if (i % 3 == 1){
                al_draw_bitmap(aYon2, aX2 + 261, aY2 + 60.5, 0);
                al_draw_bitmap(bYon2, bX2 + 261, bY2 + 60.5, 0);
                al_draw_bitmap(cYon2, cX2 + 261, cY2 + 60.5, 0);
                al_draw_bitmap(dYon2, dX2 + 261, dY2 + 60.5, 0);
                al_draw_bitmap(tYon2, tX2 + 261, tY2 + 60.5, 0);
                al_draw_bitmap(xYon2, xX2 + 261, xY2 + 60.5, 0);
                al_draw_bitmap(yYon2, yX2 + 261, yY2 + 60.5, 0);
                al_draw_bitmap(zYon2, zX2 + 261, zY2 + 60.5, 0);


            }else {
                al_draw_bitmap(aYon3, aX3 + 261, aY3 + 60.5, 0);
                al_draw_bitmap(bYon3, bX3 + 261, bY3 + 60.5, 0);
                al_draw_bitmap(cYon3, cX3 + 261, cY3 + 60.5, 0);
                al_draw_bitmap(dYon3, dX3 + 261, dY3 + 60.5, 0);
                al_draw_bitmap(tYon3, tX3 + 261, tY3 + 60.5, 0);
                al_draw_bitmap(xYon3, xX3 + 261, xY3 + 60.5, 0);
                al_draw_bitmap(yYon3, yX3 + 261, yY3 + 60.5, 0);
                al_draw_bitmap(zYon3, zX3 + 261, zY3 + 60.5, 0);


            }

        }

        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_bitmap(harita, 261, 60.5, 0);
        al_draw_bitmap(aYon2, aX2 + 261, aY2 + 60.5, 0);
        al_draw_bitmap(bYon2, bX2 + 261, bY2 + 60.5, 0);
        al_draw_bitmap(cYon2, cX2 + 261, cY2 + 60.5, 0);
        al_draw_bitmap(dYon2, dX2 + 261, dY2 + 60.5, 0);
        al_draw_bitmap(tYon2, tX2 + 261, tY2 + 60.5, 0);
        al_draw_bitmap(xYon2, xX2 + 261, xY2 + 60.5, 0);
        al_draw_bitmap(yYon2, yX2 + 261, yY2 + 60.5, 0);
        al_draw_bitmap(zYon2, zX2 + 261, zY2 + 60.5, 0);
        al_flip_display();


    }else{
        for (int i = 0; i < 20; ++i) {

            delay(400000);
            al_flip_display();
            al_clear_to_color(al_map_rgb(255, 255, 255));
            al_draw_bitmap(harita, 261, 60.5, 0);
            if (i % 3 == 0) {
                al_draw_bitmap(aYon1, aX1 + 261, aY1 + 60.5, 0);
                al_draw_bitmap(bYon1, bX1 + 261, bY1 + 60.5, 0);
                al_draw_bitmap(cYon1, cX1 + 261, cY1 + 60.5, 0);
                al_draw_bitmap(dYon1, dX1 + 261, dY1 + 60.5, 0);
                al_draw_bitmap(eYon1, eX1 + 261, eY1 + 60.5, 0);
                al_draw_bitmap(tYon1, tX1 + 261, tY1 + 60.5, 0);
                al_draw_bitmap(xYon1, xX1 + 261, xY1 + 60.5, 0);
                al_draw_bitmap(yYon1, yX1 + 261, yY1 + 60.5, 0);
                al_draw_bitmap(zYon1, zX1 + 261, zY1 + 60.5, 0);

            }else if (i % 3 == 1){
                al_draw_bitmap(aYon2, aX2 + 261, aY2 + 60.5, 0);
                al_draw_bitmap(bYon2, bX2 + 261, bY2 + 60.5, 0);
                al_draw_bitmap(cYon2, cX2 + 261, cY2 + 60.5, 0);
                al_draw_bitmap(dYon2, dX2 + 261, dY2 + 60.5, 0);
                al_draw_bitmap(eYon2, eX2 + 261, eY2 + 60.5, 0);
                al_draw_bitmap(tYon2, tX2 + 261, tY2 + 60.5, 0);
                al_draw_bitmap(xYon2, xX2 + 261, xY2 + 60.5, 0);
                al_draw_bitmap(yYon2, yX2 + 261, yY2 + 60.5, 0);
                al_draw_bitmap(zYon2, zX2 + 261, zY2 + 60.5, 0);


            }else {
                al_draw_bitmap(aYon3, aX3 + 261, aY3 + 60.5, 0);
                al_draw_bitmap(bYon3, bX3 + 261, bY3 + 60.5, 0);
                al_draw_bitmap(cYon3, cX3 + 261, cY3 + 60.5, 0);
                al_draw_bitmap(dYon3, dX3 + 261, dY3 + 60.5, 0);
                al_draw_bitmap(eYon3, eX3 + 261, eY3 + 60.5, 0);
                al_draw_bitmap(tYon3, tX3 + 261, tY3 + 60.5, 0);
                al_draw_bitmap(xYon3, xX3 + 261, xY3 + 60.5, 0);
                al_draw_bitmap(yYon3, yX3 + 261, yY3 + 60.5, 0);
                al_draw_bitmap(zYon3, zX3 + 261, zY3 + 60.5, 0);


            }

        }
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_bitmap(harita, 261, 60.5, 0);
        al_draw_bitmap(aYon2, aX2 + 261, aY2 + 60.5, 0);
        al_draw_bitmap(bYon2, bX2 + 261, bY2 + 60.5, 0);
        al_draw_bitmap(cYon2, cX2 + 261, cY2 + 60.5, 0);
        al_draw_bitmap(dYon2, dX2 + 261, dY2 + 60.5, 0);
        al_draw_bitmap(eYon2, eX2 + 261, eY2 + 60.5, 0);
        al_draw_bitmap(tYon2, tX2 + 261, tY2 + 60.5, 0);
        al_draw_bitmap(xYon2, xX2 + 261, xY2 + 60.5, 0);
        al_draw_bitmap(yYon2, yX2 + 261, yY2 + 60.5, 0);
        al_draw_bitmap(zYon2, zX2 + 261, zY2 + 60.5, 0);
        al_flip_display();

    }


}


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();     //Kaynak : https://stackoverflow.com/questions/27447195/how-to-use-delay-function-in-c-using-codeblocks-13-12mingw
    while (goal > clock());
}
