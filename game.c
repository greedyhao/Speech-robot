#include "project.h"

int Game(intel_pjt_t *intel_pjt)
{
	// printf("启动游戏！\n");

	if (intel_pjt->fun_sw.sw_game)
	{
		// if (intel_pjt->ts_info.flag_press)
		// {
		// printf("G %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);
		printf("%d ", intel_pjt->ts_info.flag_press);
		
		if (intel_pjt->ts_info.ts_x > 700 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 300 && intel_pjt->ts_info.ts_y < 480)
		{
			intel_pjt->fun_sw.sw_game = 0;
			goto_main_ui();
		}
		// }
	}
	
}