/* 
 * (C) Copyright 1992, ..., 2004 the "DOSEMU-Development-Team".
 *
 * for details see file COPYING in the DOSEMU distribution
 */

/* definitions for updating text modes */

#define CONFIG_SELECTION 1

extern Boolean have_focus;
extern int use_bitmap_font;

struct text_system
{
   /* update the screen */
   void (*Update)(void);
   /* function to draw a string in text mode using attribute attr */
   void (*Draw_string)(int x, int y , unsigned char *s, int len, Bit8u attr); 
   void (*Draw_line)(int x, int y , int len); 
   void (*Draw_cursor)(int x, int y, Bit8u attr, int first, int last, Boolean focus);
   void (*SetPalette) (DAC_entry color);
   void (*Resize_text_screen)(void);

};

struct RemapObjectStruct;
struct RectArea;

int register_text_system(struct text_system *text_system);
void blink_cursor(void);
void reset_redraw_text_screen(void);
void update_cursor(void);
void resize_text_mapper(int image_mode);
struct RectArea convert_bitmap_string(int x, int y, unsigned char *text,
				      int len, Bit8u attr);
int update_text_screen(void);
void redraw_text_screen(void);
void text_gain_focus(void);
void text_lose_focus(void);
void set_textsize(int, int);

#ifdef CONFIG_SELECTION
/* for selections */
char* end_selection(void);
void clear_if_in_selection(void);
void start_selection(int col, int row);
void start_extend_selection(int col, int row);
void clear_selection_data(void);
void extend_selection(int col, int row);
#endif
