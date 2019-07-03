#include "project.h"

int Video_Player(intel_pjt_t *intel_pjt)
{
	// printf("启动视频播放器！\n");

	if (intel_pjt->fun_sw.sw_vedio)
	{
		// printf("V %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);

		if (intel_pjt->ts_info.ts_x > 706 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 405 && intel_pjt->ts_info.ts_y < 480)
		{
			intel_pjt->fun_sw.sw_vedio = 0;
			goto_main_ui();
		}
	}

	return 0;
}