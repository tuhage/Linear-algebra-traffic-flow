#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>

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
    }

    //ALLEGRO_DISPLAY *al_create_display(int w, int h)

    //al_set_new_display_flags(ALLEGRO_RESIZABLE);//Sets various flags to be used when creating new displays on the calling thread. flags is a bitfield containing any reasonable combination of the following:
    display = al_create_display(w, h);
    
    al_init_font_addon(); //font addon başlatıcı
    al_init_ttf_addon(); //ttf addon başlatıcı
    al_init_primitives_addon(); //primitives addon başlatıcı
    al_init_image_addon();//image addon başlatıcı
    
   al_clear_to_color(al_map_rgb(255,255,255));
   ALLEGRO_FONT *font24 = al_load_font("BalooBhai-Regular.ttf", 36, 0); //ALLEGRO_FONT *al_load_font(char const *filename, int size, int flags)
     //void al_clear_to_color(ALLEGRO_COLOR color)

    al_draw_text(font24, al_map_rgb(0, 24, 45), 160, 0, 0, "HARİTA-1"); /*void al_draw_text(const ALLEGRO_FONT *font,ALLEGRO_COLOR color, float x, float y, int flags,char const *text)   
                                                                         *       
                                                                                           =Flags=
                                                                                            ALLEGRO_ALIGN_LEFT - Draw the text left-aligned (same as 0).
                                                                                            ALLEGRO_ALIGN_CENTRE - Draw the text centered around the given position.
                                                                                            ALLEGRO_ALIGN_RIGHT - Draw the text right-aligned to the given position.
                                                                                 */
    al_draw_text(font24, al_map_rgb(0, 24, 45),568 , 0, 0, "HARİTA-2"); 

    ALLEGRO_BITMAP  *image1  = al_load_bitmap("map1.png");
     ALLEGRO_BITMAP  *image2 = al_load_bitmap("map2.png");
     
     al_draw_bitmap(image1,50,50,0);al_draw_bitmap(image2,465,50,0);
     al_flip_display(); //işlemleri ekrana yazıyor.
     al_rest(15.0);
   
    //  al_draw_pixel(100,100,al_map_rgb(6,7,123)); void al_draw_pixel(float x, float y, ALLEGRO_COLOR color)    
    //al_draw_line(300, 300, 350, 350, al_map_rgb(255, 0, 255), 2); //void al_draw_line(float x1, float y1, float x2, float y2,ALLEGRO_COLOR color, float thickness)
    //al_draw_triangle(100, 100, 150, 150, 100, 150, al_map_rgb(255, 0, 255), 3); //void al_draw_triangle(float x1, float y1, float x2, float y2,float x3, float y3, ALLEGRO_COLOR color, float thickness)
    //al_flip_display(); //işlemleri ekrana yazıyor.
    //al_rest(15.0);
    //al_destroy_display(display); //destroy our display object




    return 0;

}

