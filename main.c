#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>	
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

int main(void)
{
	int w= 640;
	int h = 480;

	ALLEGRO_DISPLAY *display = NULL;
    
        
        if(!al_init()){
            
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
            
            al_show_native_message_box(display,NULL,"HATA","Allegro baslatilamadi !",NULL,ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }
        
        //ALLEGRO_DISPLAY *al_create_display(int w, int h)
        
//        al_set_new_display_flags(ALLEGRO_RESIZABLE);//Sets various flags to be used when creating new displays on the calling thread. flags is a bitfield containing any reasonable combination of the following:
        display = al_create_display(w,h);
        
        
        al_init_font_addon();//addon başlatıcı
        al_init_ttf_addon();//addon başlatıcı
        ALLEGRO_FONT *font =al_load_font("YARDSALE.ttf",24,0);//ALLEGRO_FONT *al_load_font(char const *filename, int size, int flags)
        al_clear_to_color(al_map_rgb(170,0,0));//void al_clear_to_color(ALLEGRO_COLOR color)
        al_draw_text(font,al_map_rgb(0,24,45),250,50,0,"Hello World");/*void al_draw_text(const ALLEGRO_FONT *font,ALLEGRO_COLOR color, float x, float y, int flags,char const *text)         
        =Flags=
            ALLEGRO_ALIGN_LEFT - Draw the text left-aligned (same as 0).
            ALLEGRO_ALIGN_CENTRE - Draw the text centered around the given position.
            ALLEGRO_ALIGN_RIGHT - Draw the text right-aligned to the given position.
 */       
                
        
        al_flip_display();//işlemleri ekrana yazıyor.
        al_rest(15.0);
	al_destroy_display(display);						//destroy our display object
	return 0;
}

