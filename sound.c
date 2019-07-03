#include "project.h"


void * Pic_Go(void * arg)
{
	while(1)
	{
		usleep(50000);  
		Display_Pic("./1.bmp",700,0);
		usleep(50000);
		Display_Pic("./2.bmp",700,0);
		usleep(50000);
		Display_Pic("./3.bmp",700,0);
	}

	return NULL;
}

int Sound(intel_pjt_t *intel_pjt)
{
	pthread_t sound_id;
	// printf("启动语音识别！\n");
	// printf("sound in\n");
	// extern intel_pjt_t intel_pjt;

	while (1)
	{
		Get_ts_info();
		// printf("%d ", intel_pjt->ts_info.flag_press);
		if (intel_pjt->ts_info.flag_press)
		{
			pthread_create(&sound_id,NULL,Pic_Go,NULL);
			// printf("S: ");
			// printf("%d ", intel_pjt->ts_info.flag_press);
		}
		else
		{
			// printf("sound exit\n");
			pthread_cancel(sound_id);
			goto_main_ui();
			
			break;
		}
		
	}

	return 0;
}
