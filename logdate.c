#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>


unsigned long get_file_size(const char * path_file)
{
	struct stat buf;
	if(stat(path_file, &buf) < 0){
		return -1;
	}
	return (unsigned long)buf.st_size;
}

void logrorate_handler()
{
	int status = 0;
	printf("start logrorate 4g log ...\n");
	alarm(60);
	/* if log greater than 40M start logratate */
	if(get_file_size("/cache/4g_log/fourG.log") > (1024 * 1024 * 40)){
		status = system("/system/bin/logrorate -vf /system/etc/logrorate.conf");
		if(status < 0){
			printf("error : system execute faild ... \n");
			exit(-1);
		}
	}
}

int main(int argc, char * *argv)
{
	int status = 0;
	
	if(access("/cache/4g_log/fourG.log", F_OK) == 0)
		printf("/cache/4g_log/fourG.log file exist\n");
	else{
		int mkt = mkdir("/cache/4g_log", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		if(mkt < 0){
			printf("error : create directory failed ... \n");
			return -1;
		}
	}
	/* wait 10s*/
	sleep(10);
	
	signal(SIGALRM, logrorate_handler);
	alarm(60);
	
	status = system("/system/bin/logcat -b radio -v time >> /cache/4g_log/fourG.log");
	if(status < 0){
		printf("error : logcat run faild ... \n");
		exit(-1);
	}
	
	while(1){
		/* progress start slepp and start alarm (1 minute)*/
		sleep(2592000);
	}
	return 0;
}
