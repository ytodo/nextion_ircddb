#include "Nextion.h"

/**************************************************
 * 環境設定ファイル/etc/ircddbgateway の内容を読む
 **************************************************/

FILE    *fp;

int getconfig(void)
{
    char    *ret;
    char    *cmdline;
    char    tmpstr[32]  = {'\0'};
    char    line[64]    = {'\0'};
    char    ifaddr[20]  = {'\0'};
    char    band[10]    = {'\0'};
    char    command[64] = {'\0'};
    int     i = 0;

    /*
     * 設定ファイルをオープンする
     */
    if ((fp = fopen(CONFFILE, "r")) != NULL) {

        /* テーブルを読み込み変数に格納する */
        while ((fgets(line, sizeof(line), fp)) != NULL) {
            /* ircDDB.net */
            if ((ret = strstr(line, "ircddbEnabled=1")) != NULL) sendcmd("MAIN.ircddbsw.val=1");
            if ((ret = strstr(line, "ircddbHostname"))  != NULL) {
                sscanf(line, "ircddbHostname=%[^\n]", tmpstr);
                sprintf(command, "MAIN.ircddbhost.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }
            /* aprs.fi */
            if ((ret = strstr(line, "aprsEnabled=1"))   != NULL) sendcmd("MAIN.aprssw.val=1");
            if ((ret = strstr(line, "aprsHostname"))    != NULL) {
                sscanf(line, "aprsHostname=%[^\n]", tmpstr);
                sprintf(command, "MAIN.aprshost.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }
            if ((ret = strstr(line, "dextraEnabled=1")) != NULL) sendcmd("MAIN.xrf.val=1");
            if ((ret = strstr(line, "dplusEnabled=1"))  != NULL) sendcmd("MAIN.dplus.val=1");
            if ((ret = strstr(line, "dcsEnabled=1"))    != NULL) sendcmd("MAIN.dcs.val=1");
            if ((ret = strstr(line, "xlxEnabled=1"))    != NULL) sendcmd("MAIN.xlx.val=1");
            if ((ret = strstr(line, "infoEnabled=1"))   != NULL) sendcmd("MAIN.info.val=1");
            if ((ret = strstr(line, "echoEnabled=1"))   != NULL) sendcmd("MAIN.echo.val=1");
            if ((ret = strstr(line, "logEnabled=1"))    != NULL) sendcmd("MAIN.log.val=1");
            if ((ret = strstr(line, "dratsEnabled=1"))  != NULL) sendcmd("MAIN.drats.val=1");
            /* 接続リピータの情報取得 */
            if ((ret = strstr(line, "repeaterBand1"))   != NULL) {
                sscanf(line, "repeaterBand1=%[^\n]", tmpstr);
                sprintf(command, "STATUS1.mod1.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }
            if ((ret = strstr(line, "frequency1"))      != NULL) {
                sscanf(line, "frequency1=%[^\n]", tmpstr);
                sprintf(command, "STATUS1.freq1.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }
            if ((ret = strstr(line, "repeaterBand2"))   != NULL) {
                sscanf(line, "repeaterBand2=%[^\n]", tmpstr);
                sprintf(command, "STATUS1.mod2.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }
            if ((ret = strstr(line, "frequency2"))      != NULL) {
                sscanf(line, "frequency2=%[^\n]", tmpstr);
                sprintf(command, "STATUS1.freq2.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }
            if ((ret = strstr(line, "repeaterBand3"))   != NULL) {
                sscanf(line, "repeaterBand3=%[^\n]", tmpstr);
                sprintf(command, "STATUS1.mod3.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }
            if ((ret = strstr(line, "frequency3"))      != NULL) {
                sscanf(line, "frequency3=%[^\n]", tmpstr);
                sprintf(command, "STATUS1.freq3.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }
            if ((ret = strstr(line, "repeaterBand41"))   != NULL) {
                sscanf(line, "repeaterBand4=%[^\n]", tmpstr);
                sprintf(command, "STATUS1.mod4.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }
            if ((ret = strstr(line, "frequency4"))      != NULL) {
                sscanf(line, "frequency4=%[^\n]", tmpstr);
                sprintf(command, "STATUS1.freq4.txt=\"%s\"", tmpstr);
                sendcmd(command);
            }

        }

        /* ファイルクローズ */
        fclose(fp);
    }

    /*
     * コマンドの標準出力オープン（ネットワークインターフェース名取得）
     */
    cmdline = "for DEV in `find /sys/devices -name net | grep -v virtual`; do ls $DEV/; done";
    if ((fp = popen(cmdline, "r")) != NULL) {
        fgets(ifname, sizeof(ifname), fp);
        ifname[strlen(ifname) - 1] = '\0';

        /* 標準出力クローズ */
        pclose(fp);
    }

    /*
     * コマンドの標準出力オープン（IPアドレスの取得）
     */
    cmdline = "hostname -I | cut -f1 -d' '";
    if ((fp = popen(cmdline, "r")) != NULL) {
        fgets(ifaddr, sizeof(ifaddr), fp);

        /* 標準出力クローズ */
        pclose(fp);
    }

    sendcmd("page MAIN");
    sendcmd("dim=30");
    sprintf(command, "MAIN.ipaddr.txt=\"%s:%s\"", ifname, ifaddr);
    sendcmd(command);

    return (0);
}

