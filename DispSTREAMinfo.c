#include "Nextion.h"
#define	SLEEPTIME	300000

// 未使用
int dispstreaminfo(void)
{
	FILE	*fp;
	char	*ret;
	char	cmdline[32] = {'\0'};
	char	line[512]   = {'\0'};

	/*
	 * 設定ファイルをオープンする
	 */

	/* パケット取得するシステムコマンド */
	sprintf(cmdline, "tcpdump -i %s -A -vv udp port 20010 -c1", ifname);
	if ((fp = popen(cmdline, "r")) != NULL )
	{
		/* 接続リフレクタに関する標準出力を配列に取得 */
		fgets(line, sizeof(line), fp);

printf("%s\n", line);

//		usleep(SLEEPTIME);

		/* 標準出力クローズ */
		pclose(fp);
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
