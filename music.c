#include "project.h"

char *music_list = "anjing.mp3";

static int flag_start = 0;
static int flag_stop = 0;
static int flag_status = 0;

int Music_Player(intel_pjt_t *intel_pjt)
{
	// printf("启动音乐播放器！\n");

	while (1)
	{
		Get_ts_info();
		if (intel_pjt->ts_info.flag_press)
		{
			// printf("M %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);
			if (intel_pjt->ts_info.ts_x > 350 && intel_pjt->ts_info.ts_x < 445 &&
				intel_pjt->ts_info.ts_y > 355 && intel_pjt->ts_info.ts_y < 400)
			{
				flag_status = !flag_status;
				if (flag_start == 0)
				{
					flag_start = 1;
					system("/usr/bin/madplay /IOT/mp3/anjing.mp3 &");
				}
				
				if (flag_status)
				{
					system("killall -18 madplay");
				}
				else
				{
					system("killall -19 madplay");
				}
			}
			if (intel_pjt->ts_info.ts_x > 0 && intel_pjt->ts_info.ts_x < 70 &&
				intel_pjt->ts_info.ts_y > 0 && intel_pjt->ts_info.ts_y < 45)
			{
				goto_main_ui();
				break;
			}
		}
	}

	return 0;
}