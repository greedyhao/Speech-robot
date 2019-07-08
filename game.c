#include "project.h"

void *game_thread(void *arg)
{
	system("./2048");
}

int Game(intel_pjt_t *intel_pjt)
{
	// printf("启动游戏！\n");
	pthread_t game_id;
	int flag_game = 0;

	while (1)
	{
		Get_ts_info();
		// printf("G %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);
		// printf("%d ", intel_pjt->ts_info.flag_press);
		if (intel_pjt->ts_info.ts_x > 600 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 400 && intel_pjt->ts_info.ts_y < 480)
		{
			flag_game = 1;
			pthread_create(&game_id, NULL, game_thread, NULL);
		}
		if (intel_pjt->ts_info.ts_x > 775 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 0 && intel_pjt->ts_info.ts_y < 30)
		{
			if (flag_game)
			{
				pthread_cancel(game_id);
			}
			
			system("killall -9 2048");
			goto_main_ui();
			break;
		}
	}
	
}
