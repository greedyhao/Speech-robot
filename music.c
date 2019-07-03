#include "project.h"


int Music_Player(intel_pjt_t *intel_pjt)
{
	// printf("启动音乐播放器！\n");

	if (intel_pjt->fun_sw.sw_music)
	{
		// printf("M %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);

		if (intel_pjt->ts_info.ts_x > 551 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 0 && intel_pjt->ts_info.ts_y < 480)
		{
			intel_pjt->fun_sw.sw_music = 0;
			goto_main_ui();
		}
	}

	return 0;
}