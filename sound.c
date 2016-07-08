#include "project.h"
#include "common.h"

#define REC_CMD  "arecord -d3 -c1 -r16000 -traw -fS16_LE cmd.pcm"
#define PCM_FILE "./cmd.pcm"

void * Pic_Go(void * arg)
{
	while(1)
	{
		usleep(50000);  
		Display_Pic("./1.bmp",362,360);
		usleep(50000);
		Display_Pic("./2.bmp",362,360);
		usleep(50000);
		Display_Pic("./3.bmp",362,360);
	}

	return NULL;
}

int Sound(intel_pjt_t *intel_pjt)
{
	int flag_sound = 0;
	pthread_t sound_id;
	// printf("启动语音识别！\n");
	int id_num=0;
	xmlChar *id;
	

	while (1)
	{
		Get_ts_info();
		// printf("%d ", intel_pjt->ts_info.flag_press);
		if (intel_pjt->ts_info.flag_press)
		{
			flag_sound = 1;
			pthread_create(&sound_id,NULL,Pic_Go,NULL);
			// printf("S: ");
			// printf("%d ", intel_pjt->ts_info.flag_press);

			printf("waiting for result...\n");
			system(REC_CMD);
			send_pcm(intel_pjt->socket_fd, PCM_FILE);
		}
		else
		{
			// printf("sound exit\n");
			if (flag_sound)
			{
				flag_sound = 0;
				pthread_cancel(sound_id);

				// 3，等待对方回送识别结果（字符串ID）
				// xmlChar *id = wait4id(intel_pjt->socket_fd);
				id = wait4id(intel_pjt->socket_fd);
				if(id == NULL)
				{
					printf("识别不了你的话！\n");
					return 0;
				}
				
				//将字符串的id转化成为整形的id
				id_num=atoi((char *)id);
				if(id_num == 1)
				{
					Music_Player(intel_pjt);
				}

				if(id_num == 2)
				{
					Game(intel_pjt);
				}
				if(id_num == 3)
				{
					Video_Player(intel_pjt);
				}
				
				printf("%d\n", id_num);
			}
			
			goto_main_ui();
			
			break;
		}
		
	}

	return 0;
}
