#include "project.h"


int Music_Player(intel_pjt_t *intel_pjt)
{
	// printf("启动音乐播放器！\n");

	while (1)
	{
		Get_ts_info();
		if (intel_pjt->ts_info.flag_press)
		{
			// printf("M %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);
			if (intel_pjt->ts_info.ts_x > 551 && intel_pjt->ts_info.ts_x < 800 &&
				intel_pjt->ts_info.ts_y > 0 && intel_pjt->ts_info.ts_y < 480)
			{
				
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