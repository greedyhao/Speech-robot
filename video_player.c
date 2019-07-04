#include "project.h"

int Video_Player(intel_pjt_t *intel_pjt)
{
	// printf("启动视频播放器！\n");

	while (1)
	{
		Get_ts_info();
		// printf("V %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);

		if (intel_pjt->ts_info.ts_x > 770 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 0 && intel_pjt->ts_info.ts_y < 45)
		{
			goto_main_ui();
			break;
		}
	}

	return 0;
}