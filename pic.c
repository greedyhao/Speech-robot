#include "project.h"

int searchdir(const char *path, char *filename[],const char *split)
{
    DIR *dp;
    struct dirent *dirp;

    if ((dp = opendir(path)) == NULL)
    {
        perror("imgs dir open error!");
    }

    int strL = 0;

    while ((dirp = readdir(dp)) != NULL)
    {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;

        int size = strlen(dirp->d_name);

        if (strcmp((dirp->d_name + ( size - 4)), ".bmp")!=0)
            continue;

		filename[strL++] = strtok(dirp->d_name, split);
    }

    closedir(dp);
    return strL;
}

int Picture_Player(intel_pjt_t *intel_pjt)
{
	// printf("启动电子相册！\n");
	char *path = PICT_LOAD_PATH;
    char *filename[PICTS_MAX_LEN] = {0};
    char *split = "";
	char buff[30];
	int length = searchdir(path, filename, split);
	int cur = 0;

	printf("total of the imgs is %d\n", length);

	while (1)
	{
		Get_ts_info();
		// printf("P %d %d\n",intel_pjt->ts_info.ts_x, intel_pjt->ts_info.ts_y);
		if (intel_pjt->ts_info.ts_x > 0 && intel_pjt->ts_info.ts_x < 80 &&
			intel_pjt->ts_info.ts_y > 200 && intel_pjt->ts_info.ts_y < 280)
		{
			if (cur <= 0) continue;
			sprintf(buff, "%s%s", path, filename[(cur--)%length]);
			Display_Pic(buff, 0, 0);
			Display_Pic(UI_PICT_L_PIC_PATH, 0, 200);
			Display_Pic(UI_PICT_N_PIC_PATH, 720, 200);
			Display_Pic(UI_PICT_C_PIC_PATH, 750, 0);
		}
		if (intel_pjt->ts_info.ts_x > 720 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 200 && intel_pjt->ts_info.ts_y < 280)
		{
			sprintf(buff, "%s%s", path, filename[(cur++)%length]);
			Display_Pic(buff, 0, 0);
			Display_Pic(UI_PICT_L_PIC_PATH, 0, 200);
			Display_Pic(UI_PICT_N_PIC_PATH, 720, 200);
			Display_Pic(UI_PICT_C_PIC_PATH, 750, 0);
		}
		if (intel_pjt->ts_info.ts_x > 750 && intel_pjt->ts_info.ts_x < 800 &&
			intel_pjt->ts_info.ts_y > 0 && intel_pjt->ts_info.ts_y < 50)
		{
			goto_main_ui();
			break;
		}
	}

	return 0;
}