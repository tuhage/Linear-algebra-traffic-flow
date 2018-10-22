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
char a[10];
void bilinmeyenlerMatrisiniOlustur(int N,char matris[N],int yollar[5][4],int anaYollar[4][4]);

void aracSayisiAl(char yolAdi,int *aracsayisi,int * bilinmeyenSayisi);

void matrisSifirla(int R,int N,int matris[R][N],int sonucMatrisi[R]);

void matrisOlustur(int R,int N,int matris[R][N],int sonucMatrisi[R],char bilinmeyenlerMatrisi[N],int yollar[5][4],int anaYollar[4][4]);

void matrisCiz(int R,int N,int matris[R][N],int sonucMatrisi[R],char bilinmeyenlerMatrisi[N]);

void yonSorgula(char Yoladi,int *yol);

void GirisCikisAl(char Yoladi,int* girisSayisi,int* cikisSayisi,int* anayol);

void isimleriGir(int a[5][4],int b[4][4]);

//dugumCoz(N,i,matris[k],&sonucMatrisi[k],bilinmeyenlerMatrisi,yollar,anaYollar);
void dugumCoz(int N,int dugumNo,int *matrisSatir,int *matrisSatirSonuc,char bilinmeyenlerMatrisi[N],int yollar[5][4],int anaYollar[4][4]);

int dugumKontrol(int dugumNo,int yollar[5][4],int anaYollar[4][4]);

int indexBul(const char *dizi,int N,int aranan);


int main(void) {
    int w = 880;
    int h = 480;

    ALLEGRO_DISPLAY *display = NULL;


    if (!al_init()) {

        /*int al_show_native_message_box(ALLEGRO_DISPLAY *display,* char const *title, char const *heading, char const *text,char const *buttons, int flags)*/

        /*The flags available are:
              ALLEGRO_MESSAGEBOX_WARN
                The message is a warning. This may cause a different icon (or other effects).
              ALLEGRO_MESSAGEBOX_ERROR
                The message is an error.
              ALLEGRO_MESSAGEBOX_QUESTION
                The message is a question.
              ALLEGRO_MESSAGEBOX_OK_CANCEL
                Display a cancel button alongside the "OK" button. Ignored if buttons is not NULL.
              ALLEGRO_MESSAGEBOX_YES_NO
                Display Yes/No buttons instead of the "OK" button. Ignored if buttons is not NULL. */

        al_show_native_message_box(display, NULL, "HATA", "Allegro baslatilamadi !", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    } else {

        //ALLEGRO_DISPLAY *al_create_display(int w, int h)

        //al_set_new_display_flags(ALLEGRO_RESIZABLE);//Sets various flags to be used when creating new displays on the calling thread. flags is a bitfield containing any reasonable combination of the following:
        display = al_create_display(w, h);

        al_init_font_addon(); //font addon başlatıcı
        al_init_ttf_addon(); //ttf addon başlatıcı
        al_init_primitives_addon(); //primitives addon başlatıcı
        al_init_image_addon();//image addon başlatıcı

        al_clear_to_color(al_map_rgb(255, 255, 255));     //void al_clear_to_color(ALLEGRO_COLOR color)

        ALLEGRO_FONT *font24 = al_load_font("/home/tuhage/CLionProjects/LabProje/BalooBhai-Regular.ttf", 36,
                                            0); //ALLEGRO_FONT *al_load_font(char const *filename, int size, int flags)

        al_draw_text(font24, al_map_rgb(230, 24, 45), 160, 0, 0, "HARİTA-1"); /*void al_draw_text(const ALLEGRO_FONT *font,ALLEGRO_COLOR color, float x, float y, int flags,char const *text)
                                                                             *
                                                                                               =Flags=
                                                                                                ALLEGRO_ALIGN_LEFT - Draw the text left-aligned (same as 0).
                                                                                                ALLEGRO_ALIGN_CENTRE - Draw the text centered around the given position.
                                                                                                ALLEGRO_ALIGN_RIGHT - Draw the text right-aligned to the given position.
                                                                                     */
        al_draw_text(font24, al_map_rgb(230, 24, 45), 568, 0, 0, "HARİTA-2");

        ALLEGRO_BITMAP *image1 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/map.png");
        ALLEGRO_BITMAP *image2 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/map2.png");

        al_draw_bitmap(image1, 50, 50, 0);
        al_draw_bitmap(image2, 465, 50, 0);
        al_flip_display(); //işlemleri ekrana yazıyor.


        while(1){
            printf("Bir harita secin: ");
            scanf("%s", a);
            haritaSecimi=atoi(a);
            if(haritaSecimi!=2&&haritaSecimi!=1){
                printf("Lutfen gecerli bir harita numarası girin : (1 veya 2)\n");
                continue;
            }

            break;      }


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

        printf("\n--- Yonler basarili bir sekilde alindi---\n\n\nYonler harita uzerinde gosteriliyor...");

        /*burada gosterim yapılacak*/

        printf("\n\n%d-->%d   %d-->%d \n\n", yollar[aYolu][bas], yollar[aYolu][son], yollar[bYolu][bas],
               yollar[bYolu][son]);

        if (haritaSecimi == 1) {
            aracSayisiAl((char) yollar[aYolu][isim], &yollar[aYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) yollar[bYolu][isim], &yollar[bYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) yollar[dYolu][isim], &yollar[dYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) yollar[cYolu][isim], &yollar[cYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[tYolu][isim], &anaYollar[tYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[xYolu][isim], &anaYollar[xYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[yYolu][isim], &anaYollar[yYolu][aracYogunlugu], &bilinmeyenSayisi);
            aracSayisiAl((char) anaYollar[zYolu][isim], &anaYollar[zYolu][aracYogunlugu], &bilinmeyenSayisi);

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


        }

        int N = bilinmeyenSayisi,R=5;
        int matris[R][N], sonucMatrisi[R];
        char bilinmeyenlerMatrisi[N];



        bilinmeyenlerMatrisiniOlustur(N, bilinmeyenlerMatrisi, yollar, anaYollar);
        matrisSifirla(R,N, matris, sonucMatrisi);
        matrisOlustur(R,N, matris, sonucMatrisi, bilinmeyenlerMatrisi, yollar, anaYollar);
        matrisCiz(R,N, matris, sonucMatrisi, bilinmeyenlerMatrisi);
        printf("\n\n");
        gauss(R,N,matris,sonucMatrisi);
        matrisCiz(R,N, matris, sonucMatrisi, bilinmeyenlerMatrisi);
        al_rest(5.0);
        return 0;

    }
}


void GirisCikisAl(char Yoladi,int* girisSayisi,int* cikisSayisi,int* anayol){
    int girisCikis,yolNum=0;
    while(1){
        printf("\n%c yolu : ",Yoladi);
        scanf("%s", a);
        girisCikis=atoi(a);
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
        scanf("%c", &baslangicnoktasi);
        scanf("%c", &baslangicnoktasi);
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
        scanf("%c", &Yonu);
        scanf("%c", &Yonu);
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

void aracSayisiAl(char yolAdi,int *aracsayisi,int * bilinmeyenSayisi){

    while(1) {
        printf("\n%c yolundaki arac yogunlugunu giriniz(bilgi yok ise : -1 girin) : ", yolAdi);
        scanf("%s", a);
        *aracsayisi = atoi(a);
        if (*aracsayisi == 0){
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
void matrisOlustur(int R,int N,int matris[R][N],int sonucMatrisi[R],char bilinmeyenlerMatrisi[N],int yollar[5][4],int anaYollar[4][4]){
    int k=0;
    for (int i = 1; i <6 ; ++i) {
        if(dugumKontrol(i,yollar,anaYollar)==0)continue;
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




void gauss(int R,int N,int matris[R][N],int sonucMatrisi[R]){

    int temp;float a;

    for (int i = 0; i <N ; ++i) {

        if(matris[i][i]!=0){
            a=(float)1/matris[i][i];
            for (int j = 0; j <N ; ++j) {
                matris[i][j]*=a;


            }
            sonucMatrisi[i]*=a;
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


            }



        }


    }

    for (int n = 0; n <R-1 ; ++n) {


        for (int i = n+1; i <N ; ++i) {
            if(matris[n][i]==0)continue;
            if(matris[i][i]==0)continue;
            a=matris[n][i];
            for (int j = 0; j <N ; ++j) {
                matris[n][j]-=a*matris[i][j];

            }
            sonucMatrisi[n]-=a*sonucMatrisi[i];



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



