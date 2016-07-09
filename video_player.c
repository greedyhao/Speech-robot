#include "project.h"

static int flag_start = 0;

int fifo_fd;

int Init_Player()
{
	//先判断管道文件有没有被创建，如果没有在创建管道文件
	if(access("/fifo",F_OK))
	{
		//创建管道文件
		mkfifo("/fifo",777);
	}

	fifo_fd = open("/fifo",O_RDWR);
	if(fifo_fd == -1)
	{
		perror("打开管道文件失败！");
	}
	return 0;
}

int Send_Cmd(char * cmd)
{
	write(fifo_fd,cmd,strlen(cmd));
	return 0;
}

int Video_Player(intel_pjt_t *intel_pjt)
{
	// printf("启动视频播放器！\n");
	Display_Pic(UI_VIDEO_PIC_PATH,0,0);
	Display_Pic(UI_VIDEO_CNTL_PATH,100,380);
	// pthread_t video_id;

	while (1)
	{
		Get_ts_info();
		if (intel_pjt->ts_info.ts_x > 100 && intel_pjt->ts_info.ts_x < 200 &&
			intel_pjt->ts_info.ts_y > 380 && intel_pjt->ts_info.ts_y < 480)
		{
			Send_Cmd("seek -10\n");
		}
		if (intel_pjt->ts_info.ts_x > 200 && intel_pjt->ts_info.ts_x < 300 &&
			intel_pjt->ts_info.ts_y > 380 && intel_pjt->ts_info.ts_y < 480)
		{
			flag_start = 1;
			system("mplayer -slave -quiet -input file=/fifo -geometry 0:0 -zoom -x 600 -y 350 ./videos/Faded3.avi &");
		}
		if (intel_pjt->ts_info.ts_x > 300 && intel_pjt->ts_info.ts_x < 400 &&
			intel_pjt->ts_info.ts_y > 380 && intel_pjt->ts_info.ts_y < 480)
		{
			system("killall -19 mplayer");
		}
		if (intel_pjt->ts_info.ts_x > 400 && intel_pjt->ts_info.ts_x < 500 &&
			intel_pjt->ts_info.ts_y > 380 && intel_pjt->ts_info.ts_y < 480)
		{
			flag_start = 0;
			system("killall -9 mplayer");
		}
		if (intel_pjt->ts_info.ts_x > 500 && intel_pjt->ts_info.ts_x < 600 &&
			intel_pjt->ts_info.ts_y > 380 && intel_pjt->ts_info.ts_y < 480)
		{
			system("killall -18 mplayer");
		}
		if (intel_pjt->ts_info.ts_x > 600 && intel_pjt->ts_info.ts_x < 700 &&
			intel_pjt->ts_info.ts_y > 380 && intel_pjt->ts_info.ts_y < 480)
		{
			Send_Cmd("seek +10\n");
		}
		if (intel_pjt->ts_info.ts_x > 770 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 0 && intel_pjt->ts_info.ts_y < 45)
		{
			if (flag_start)
			{
				flag_start = 0;
				// pthread_cancel(video_id);
				system("killall -9 mplayer");
			}
			goto_main_ui();
			break;
		}
		
	}

	return 0;
}