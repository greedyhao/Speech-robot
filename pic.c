#include "project.h"

int Picture_Player(intel_pjt_t *intel_pjt)
{
	// printf("启动电子相册！\n");

	while (1)
	{
		Get_ts_info();
		// printf("P %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);

		if (intel_pjt->ts_info.ts_x > 715 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 0 && intel_pjt->ts_info.ts_y < 50)
		{
			intel_pjt->fun_sw.sw_pict = 0;
			goto_main_ui();
			break;
		}
	}

	return 0;
}