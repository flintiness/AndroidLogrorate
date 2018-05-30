#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(/*int argc, char **argv*/)
{
	struct tm *ptm;	
	time_t now;
	int h,m,s;
	system("/system/bin/logcat -b radio -v time > /data/media/fourG.log&");
        //exit(0);
	printf("enter log test mode!!!\n");
	for(;;){
		time(&now); 
		ptm = localtime(&now);
		h = ptm->tm_hour;
		m = ptm->tm_min;
		s = ptm->tm_sec; 
		if(h == 0 && m == 0 && s == 0){
			sleep(10);
			system("busybox1.11 killall logcat");
			system("/system/bin/logrorate -vf /system/etc/logrorate.conf");
			system("/system/bin/logcat -b radio -v time > /data/media/fourG.log&");
		}
	}
	return 0;
}
