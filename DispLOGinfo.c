/********************************************************
 * dstarrepeaterd-yyyy-mm-dd.log を読み込み、
 * 処理の結果情報を取得する
 ********************************************************/

#include "Nextion.h"

int disploginfo(void)
{
    FILE    *fp;
    char    *tmpptr;
    char    tmpstr[32]          = {'\0'};
    char    cmdline[64]         = {'\0'};
    char    line[256]           = {'\0'};
    char    command[32]         = {'\0'};
    char    fname[32]           = {'\0'};
    char    mycall[10]          = {'\0'};
    char    urcall[10]          = {'\0'};
    char    ircddblogpath[64]   = {'\0'};
    /*
     * ログファイルからリフレクタへのリンク情報を抽出する
     */

    /* 日付入りログファイル名の作成 */

    timer = time(NULL);
    timeptr = gmtime(&timer);
    strftime(fname, sizeof(fname), "ircDDBGateway-%Y-%m-%d.log", timeptr);
    sprintf(ircddblogpath, "%s%s", LOGDIR, fname);

    /* コマンドの標準出力オープン */
    sprintf(cmdline, "tail -n1 %s", ircddblogpath);
    if ((fp = popen(cmdline, "r")) != NULL ) {
        fgets(line,  sizeof(line),  fp);

        /*
         * ゲートウェイのバージョン情報を取得
         * M: 2019-06-02 06:04:37: Version text set to "ircDDB GW - 20190402"
         */
        if ((tmpptr = strstr(line, "Version text")) != NULL) {

            /* 一巡して全く同じ内容ならパス */
            if (strncmp(tmpptr, chkversion, 41) != 0) {

                /* 一旦ダブりチェック用変数をクリアして新たに代入 */
                chkversion[0] = '\0';
                strncpy(chkversion, tmpptr, 41);

                /* リンク先リフレクタを取得 */
                tmpstr[0] = '\0';
                strncpy(tmpstr, tmpptr + 21, 20);

                /* Nextion グローバル変数ircver.txt にバージョン情報を代入 */
                sprintf(command, "STATUS1.ircver.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }
        }

        /* 標準出力クローズ */
        pclose(fp);

    } else {
        exit(EXIT_FAILURE);
    }

	return (EXIT_SUCCESS);
}
