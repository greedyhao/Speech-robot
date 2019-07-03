#include "project.h"

int Picture_Player(intel_pjt_t *intel_pjt)
{
	// printf("启动电子相册！\n");

	if (intel_pjt->fun_sw.sw_pict)
	{
		// printf("P %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);

		if (intel_pjt->ts_info.ts_x > 700 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 300 && intel_pjt->ts_info.ts_y < 480)
		{
			intel_pjt->fun_sw.sw_pict = 0;
			goto_main_ui();
		}
	}

	return 0;
}