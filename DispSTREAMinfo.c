#include "Nextion.h"
#define SLEEPTIME   300000

int dispstreaminfo(void)
{
    FILE    *fp;
    char    *ret;
    char    cmdline[32] = {'\0'};
    char    line[256]   = {'\0'};

    /*
     * 設定ファイルをオープンする
     */

    /* CPU 温度を取得するシステムコマンド */
//    sprintf(cmdline, "tcpdump -i %s -A udp port %s -c1", ifname, localport);

//    if ((fp = popen(cmdline, "r")) != NULL ) {

        /* 接続リフレクタに関する標準出力を配列に取得 */
//        fgets(line, sizeof(line), fp);

//printf("%s\n", line);

//        usleep(SLEEPTIME);

        /* 標準出力クローズ */
//        pclose(fp);

//    } else {
//        exit(EXIT_FAILURE);
//    }

    return (EXIT_SUCCESS);
}


/* sample
16:28:14.561199 IP (tos 0x0, ttl 64, id 45973, offset 0, flags [DF], proto UDP (17), length 77)
    10.0.0.4.20010 > 10.0.0.15.vboxd: [bad udp cksum 0x145d -> 0x3d2e!] UDP, length 49
        0x0000:  4500 004d b395 4000 4011 72f8 0a00 0004  E..M..@.@.r.....
        0x0010:  0a00 000f 4e2a 4e2c 0039 145d 4453 5250  ....N*N,.9.]DSRP
        0x0020:  201c 6b00 0000 004a 4c33 5a42 5320 424a  ..k....JL3ZBS.BJ
        0x0030:  4c33 5a42 5320 4743 5143 5143 5120 2041  L3ZBS.GCQCQCQ..A
        0x0040:  4736 5446 2020 2047 5245 470f ea         G6TF...GREG..
16:28:14.561535 IP (tos 0x0, ttl 64, id 45974, offset 0, flags [DF], proto UDP (17), length 49)
    10.0.0.4.20010 > 10.0.0.15.vboxd: [bad udp cksum 0x1441 -> 0x12c6!] UDP, length 21
        0x0000:  4500 0031 b396 4000 4011 7313 0a00 0004  E..1..@.@.s.....
        0x0010:  0a00 000f 4e2a 4e2c 001d 1441 4453 5250  ....N*N,...ADSRP
        0x0020:  211c 6b00 006a 4286 234a 438c c5a8 5555  !.k..jB.#JC...UU
        0x0030:  55                                       U
16:28:14.572998 IP (tos 0x0, ttl 64, id 45975, offset 0, flags [DF], proto UDP (17), length 49)
    10.0.0.4.20010 > 10.0.0.15.vboxd: [bad udp cksum 0x1441 -> 0x06d7!] UDP, length 21
        0x0000:  4500 0031 b397 4000 4011 7312 0a00 0004  E..1..@.@.s.....
        0x0010:  0a00 000f 4e2a 4e2c 001d 1441 4453 5250  ....N*N,...ADSRP
        0x0020:  211c 6b41 0055 5555 55c8 7a00 0000 0000  !.kA.UUUU.z.....
        0x0030:  00                                       .
16:28:57.533288 IP (tos 0x0, ttl 64, id 36975, offset 0, flags [DF], proto UDP (17), length 61)
    10.0.0.15.vboxd > 10.0.0.4.20010: [udp sum ok] UDP, length 33
        0x0000:  4500 003d 906f 4000 4011 962e 0a00 000f  E..=.o@.@.......
        0x0010:  0a00 0004 4e2c 4e2a 0029 9d06 4453 5250  ....N,N*.)..DSRP
        0x0020:  0a6c 696e 7578 5f67 6d73 6b2d 3230 3138  .linux_gmsk-2018
        0x0030:  3039 3131 2d2d 2d64 6562 7567 00         0911---debug.
16:29:02.708216 IP (tos 0x0, ttl 64, id 26526, offset 0, flags [DF], proto UDP (17), length 61)
    10.0.0.14.20013 > 10.0.0.4.20010: [udp sum ok] UDP, length 33
        0x0000:  4500 003d 679e 4000 4011 bf00 0a00 000e  E..=g.@.@.......
        0x0010:  0a00 0004 4e2d 4e2a 0029 9d06 4453 5250  ....N-N*.)..DSRP
        0x0020:  0a6c 696e 7578 5f67 6d73 6b2d 3230 3138  .linux_gmsk-2018
        0x0030:  3039 3131 2d2d 2d64 6562 7567 00         0911---debug.
16:29:04.274768 IP (tos 0x0, ttl 64, id 23996, offset 0, flags [DF], proto UDP (17), length 63)
    10.0.0.10.isdnlog > 10.0.0.4.20010: [udp sum ok] UDP, length 35
        0x0000:  4500 003f 5dbc 4000 4011 c8e4 0a00 000a  E..?].@.@.......
        0x0010:  0a00 0004 4e2b 4e2a 002b 38aa 4453 5250  ....N+N*.+8.DSRP
        0x0020:  0a6c 696e 7578 5f64 766d 6567 612d 3230  .linux_dvmega-20
        0x0030:  3138 3039 3131 2d2d 2d64 6562 7567 00    180911---debug.
*/
