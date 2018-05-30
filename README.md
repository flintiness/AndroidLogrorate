# AndroidLogrorate
    将优秀的切割工具logrorate移植到android操作系统下，此代码是popt和logrorate源代码的结合版，不需要在使用logrorate时候移植popt。
# Logrorate README.md:
    The logrotate utility is designed to simplify the administration of log files on a system which generates a lot of log files. Logrotate 
allows for the automatic rotation compression, removal and mailing of log files. Logrotate can be set to handle a log file daily, weekly, 
monthly or when the log file gets to a certain size.

# Usage:
    step 1: 将 AndroidLogrorate 源码下载到android操作系统的external目录下
            git clone https://github.com/flintiness/AndroidLogrorate.git

    step 2: 进入 AndroidLogrorate 源码，执行命令：
            mm
            生成logrorate 和 logdate 
            
            logrorate 是切割系统日志的工具
            logdate 是使用logrorate获取相应log的守护程序
            logrorate.conf 是如何切割log的规则

