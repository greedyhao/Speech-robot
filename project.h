#ifndef _PROJECT_H_
#define _PROJECT_H_

/***包含项目函数接口所需的头文件***/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>
#include <linux/input.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/** 相关宏定义 */
#define LCD_DEV_PATH    "/dev/fb0"
#define TS_DEV_PATH     "/dev/input/event0"
#define KB_DEV_PATH     "/dev/input/event4"
#define MMAP_LENGTH     800*480*4

#define UI_MAIN_PIC_PATH    "./imgs/v1_0/main.bmp"
#define UI_EXIT_PIC_PATH    "./imgs/v1_0/exit.bmp"
#define UI_MUSIC_PIC_PATH   "./imgs/v1_0/music.bmp"
#define UI_VIDEO_PIC_PATH   "./imgs/v1_0/vedio.bmp"
#define UI_PICT_PIC_PATH   "./imgs/v1_0/moments.bmp"
#define UI_GAME_PIC_PATH   "./imgs/v1_0/game.bmp"
#define UI_MIC1_PIC_PATH   "1.bmp"
#define UI_MIC2_PIC_PATH   "2.bmp"
#define UI_MIC3_PIC_PATH   "3.bmp"

#define UI_PICT_L_PIC_PATH  "./imgs/v1_0/left.bmp"
#define UI_PICT_N_PIC_PATH  "./imgs/v1_0/next.bmp"
#define UI_PICT_C_PIC_PATH  "./imgs/v1_0/close.bmp"

#define PICTS_MAX_LEN       20
#define PICT_LOAD_PATH      "./imgs/show/"

typedef struct 
{
    int ts_x;
    int ts_y;
    int flag_press;
}ts_info_t;

typedef struct
{
    struct input_event touch;
}pjt_event_t;

typedef struct 
{
    int lcd;
    int *lcd_mmap;
    int ts;
    pjt_event_t event;
    ts_info_t ts_info;
}intel_pjt_t;


/***函数的申明***/

/***music_player.c***/
int Music_Player(intel_pjt_t *intel_pjt);

/***video_player.c***/
int Video_Player(intel_pjt_t *intel_pjt);

/***pic.c***/
int Picture_Player(intel_pjt_t *intel_pjt);

/***game.c***/
int Game(intel_pjt_t *intel_pjt);
// void *Game(void *intel_pjt);

/***sournd.c***/
int Sound(intel_pjt_t *intel_pjt);

/***project_set.c***/
int Init_Pro();
int End_Pro();
int main_pjt();
int Get_ts_info();
int goto_main_ui();
int Display_Pic(char * pic_path, int dis_x, int dis_y);


#endif