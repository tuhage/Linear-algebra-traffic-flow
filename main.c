
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
#include "time.h"



    int haritaSecimi;
    char a[10];


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

            al_show_native_message_box(display, NULL, "HATA", "Allegro baslatilamadi !", NULL,
                                       ALLEGRO_MESSAGEBOX_ERROR);
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
            ALLEGRO_BITMAP *a1_12 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/a1-12-x85y122.png");
            ALLEGRO_BITMAP *a2_12 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/a2-12-x99y99.png");
            ALLEGRO_BITMAP *a3_12 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/a3-12-x112y84.png");
            ALLEGRO_BITMAP *a1_21 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/a1-21-120_84.png");
            ALLEGRO_BITMAP *a2_21 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/a2-21-101_99.png");
            ALLEGRO_BITMAP *a3_21 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/a3-21-83_128.png");
            ALLEGRO_BITMAP *b23_1 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/b23_1_201_83.png");
            ALLEGRO_BITMAP *b23_2 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/b23_2_232_100.png");
            ALLEGRO_BITMAP *b23_3 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/b23_3_252_127.png");
            ALLEGRO_BITMAP *b32_1 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/b32_1_253_126.png");
            ALLEGRO_BITMAP *b32_2 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/b32_2_227_101.png");
            ALLEGRO_BITMAP *b32_3 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/b32_3_200_83.png");
            ALLEGRO_BITMAP *c14_1 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/c_1_85_201.png");
            ALLEGRO_BITMAP *c14_2 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/c_2_101_232.png");
            ALLEGRO_BITMAP *c14_3 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/c_3_128_252.png");
            ALLEGRO_BITMAP *c41_1 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/c41_1_125_255.png");
            ALLEGRO_BITMAP *c41_2 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/c41_2_105_225.png");
            ALLEGRO_BITMAP *c41_3 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/c41_3_89_196.png");
            ALLEGRO_BITMAP *d34_1 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/d34_1_254_177.png");
            ALLEGRO_BITMAP *d34_2 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/d34_2_234_214.png");
            ALLEGRO_BITMAP *d34_3 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/d34_3_207_240.png");
            ALLEGRO_BITMAP *d43_1 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/d43_1_205_244.png");
            ALLEGRO_BITMAP *d43_2 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/d43_2_233_213.png");
            ALLEGRO_BITMAP *d43_3 = al_load_bitmap("/home/tuhage/CLionProjects/LabProje/d43_3_205_183.png");

            for (int i = 0; i <100 ; ++i) {

                delay(400000);
                al_draw_bitmap(image1, 50, 50, 0);
                al_draw_bitmap(image2, 465, 50, 0);

                if(i%3==0){
                    al_draw_bitmap(c14_1, 85+50, 201+50, 0);
                    al_draw_bitmap(d34_1, 254+50, 177+50, 0);

                    al_flip_display();
                al_clear_to_color(al_map_rgb(255, 255, 255));
                    }

                else if(i%3==1){
                    al_draw_bitmap(c14_2, 101+50, 232+50, 0);
                    al_draw_bitmap(d34_2, 234+50, 214+50, 0);

                    al_flip_display();
                    al_clear_to_color(al_map_rgb(255, 255, 255));
                    }else{
                    al_draw_bitmap(c14_3, 128+50, 252+50, 0);
                    al_draw_bitmap(d34_3, 207+50, 240+50, 0);

                    al_flip_display();
                    al_clear_to_color(al_map_rgb(255, 255, 255));
                }


                }



            al_draw_filled_pieslice(50,50,5,3,15,al_map_rgb(4,145,90));
            al_flip_display(); //işlemleri ekrana yazıyor.

            while (1) {
                printf("Bir harita secin: ");
                scanf("%s", a);
                haritaSecimi = atoi(a);
                if (haritaSecimi != 2 && haritaSecimi != 1) {
                    printf("Lutfen gecerli bir harita numarası girin : (1 veya 2)\n");
                    continue;
                }

                break;
            }

            al_rest(5.0);
            return 0;


        }


    }


void delay(unsigned int mseconds)
{                                           //Bu fonksiyon kaynak üzerinden eklendi.
    clock_t goal = mseconds + clock();     //Kaynak : https://stackoverflow.com/questions/27447195/how-to-use-delay-function-in-c-using-codeblocks-13-12mingw
    while (goal > clock());
}