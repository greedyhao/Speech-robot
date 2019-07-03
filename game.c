#include "project.h"

int Game(intel_pjt_t *intel_pjt)
{
	// printf("启动游戏！\n");

	while (1)
	{
		Get_ts_info();
		// printf("G %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);
		// printf("%d ", intel_pjt->ts_info.flag_press);
		
		if (intel_pjt->ts_info.ts_x > 700 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 300 && intel_pjt->ts_info.ts_y < 480)
		{
			goto_main_ui();
			break;
		}
	}
	
}