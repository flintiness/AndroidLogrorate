#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
static void *fourG_log(void * arg)
{
	while(1)
	{
                if (system("/system/bin/logcat -v time -b radio >> /data/media/fourG.log") < 0) {
                        printf("main_log command error!\nExit process...\n");
                       exit(EXIT_FAILURE);	
                }
                sleep(1);

	}
	return NULL;
}
#if 1
static void *rorate_log(void * arg)
{
	struct tm *ptm;
	time_t now;
	int h,m,s;
	while(1)
	{
		time(&now);
		ptm = localtime(&now);
		h = ptm->tm_hour;
		m = ptm->tm_min;
		s = ptm->tm_sec;
		if(h==0 && m==0 && s==0)
		{
			sleep(10);
                        system("/system/bin/logrorate -vf /system/etc/logrorate.conf");

		}
	}
	return NULL;
}
#endif
int main(/*int argc, char **argv*/)
{
    struct tm *ptm;
    time_t now;
    int h,m,s;
    int err;
    pthread_t fourG_id;
    pthread_t rorate_id;
    err = pthread_create(&fourG_id, NULL, fourG_log, NULL);
    err = pthread_create(&rorate_id,NULL,rorate_log,NULL);
    printf("enter log test mode!!!\n");
    pthread_join(fourG_id, NULL);
    pthread_join(rorate_id, NULL);
    return 0;
}

