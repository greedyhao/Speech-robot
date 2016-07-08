#include "project.h"

static int flag_start = 0;
static int flag_status = 0;

static void *player(void *arg)
{
	system("mplayer -vo fbdev -zoom -x 800 -y 480 ./videos/1.mp4");
	return 0;
}

int Video_Player(intel_pjt_t *intel_pjt)
{
	// printf("启动视频播放器！\n");
	Display_Pic(UI_VIDEO_PIC_PATH,0,0);
	pthread_t video_id;

	while (1)
	{
		Get_ts_info();

		if (intel_pjt->ts_info.ts_x > 235 && intel_pjt->ts_info.ts_x < 270 &&
			intel_pjt->ts_info.ts_y > 435 && intel_pjt->ts_info.ts_y < 480)
		{
			flag_status = !flag_status;
			if (flag_start == 0)
			{
				flag_start = 1;
				pthread_create(&video_id,NULL,player,NULL);
			}
			
		}
		if (intel_pjt->ts_info.ts_x > 120 && intel_pjt->ts_info.ts_x < 720 &&
			intel_pjt->ts_info.ts_y > 130 && intel_pjt->ts_info.ts_y < 430)
		{
			flag_status = !flag_status;

			if (flag_status)
			{
				system("killall -18 mplayer");
			}
			else
			{
				system("killall -19 mplayer");
				Display_Pic(UI_PICT_N_PIC_PATH, 400, 240);
			}
		}
		if (intel_pjt->ts_info.ts_x > 770 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 0 && intel_pjt->ts_info.ts_y < 45)
		{
			if (flag_start)
			{
				flag_start = 0;
				pthread_cancel(video_id);
				system("killall -9 mplayer");
			}
			goto_main_ui();
			break;
		}
		
	}

	return 0;
}