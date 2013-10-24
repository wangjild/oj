#include <iostream>
#include <string>
using namespace std;

int aStks[25][25];
int aPos[25]; //表示每一块积木的位置，所在栈的编号*所在高度
int aStkLen[25];
int nStkCnt;

struct COMMAND{
    int nCom;
    int nA;
    int nB;
};
bool ParseCommand(const char *pComStr, COMMAND &cmd) {
    int nPos = 0, i, j;
    static char *pCom[] = {"move ", "pile ", "quit", "dump"};
    for (i = 0; i < sizeof(pCom) / sizeof(pCom[0]); ++i) {
        for(j = 0; pComStr[j] == pCom[i][j] && pCom[i][j] != 0; ++j);
        if (pCom[i][j] == 0) break;
    }
    if (i >= sizeof(pCom) / sizeof(pCom[0])) {
        return false;
    }
    cmd.nCom = i * 2;
    if (cmd.nCom >= 4) {
        return true;
    }
    if (pComStr[j] < '1' || pComStr[j] > '9') {
        return false;
    }
    for (cmd.nA = 0; pComStr[j] >= '0' && pComStr[j] <= '9'; ++j) {
        cmd.nA = cmd.nA * 10 + pComStr[j] - '0';
    }
    static char *pDir[2] = {" onto ", " over "};
    for (i = 0, pComStr += j; i < 2; ++i) {
        for(j = 0; pComStr[j] == pDir[i][j] && pDir[i][j] != 0; ++j);
        if (pDir[i][j] == 0) {
            break;
        }
    }
    if (i >= 2) {
        return false;
    }
    cmd.nCom += i;
    if (pComStr[j] < '1' || pComStr[j] > '9') {
        return false;
    }
    for (cmd.nB = 0; pComStr[j] >= '0' && pComStr[j] <= '9'; ++j) {
        cmd.nB = cmd.nB * 10 + pComStr[j] - '0';
    }
    if (pComStr[j] != 0 || cmd.nA == cmd.nB) {
        return false;
    }
    return true;
}

void ReturnUpperBlock(int nBaseBlk) {
    //计算出积木所在的栈和高度。nStk为栈的编号，nHei为栈的高度
    int nStk = aPos[nBaseBlk] / nStkCnt, nHei = aPos[nBaseBlk] % nStkCnt + 1;
    //循环将指定积木以上的所有积木归位
    for (int &nStkLen = aStkLen[nStk]; nStkLen > nHei; --nStkLen) {
        int nUpperBlk = aStks[nStk][nStkLen - 1]; //最顶的积木编号
        aStks[nUpperBlk][0] = nUpperBlk; //将其归原位
        aPos[nUpperBlk] = nUpperBlk * nStkCnt; //重新计算合成该积木位置
        aStkLen[nUpperBlk] = 1; //归位的目标栈的高度置1(只有归位的积木)
    }
}

void Dump(void) {
    for (int i = 0; i < nStkCnt; ++i, cout << endl) {
        cout << i << ':';
        for (int j = 0; j < aStkLen[i]; ++j) {
            cout << ' ' << aStks[i][j];
        }
    }
}
int main(void) {
    COMMAND cmd;
    cin >> nStkCnt;
    for (int i = 0; i < nStkCnt; ++i) {
        aStks[i][0] = i; aPos[i] = i * nStkCnt; aStkLen[i] = 1;
    }
    for (string strLine; getline(cin, strLine);) {
        if (!ParseCommand(strLine.c_str(), cmd)) {
            continue;
        }
        if (cmd.nCom == 4) {
            break; //quit
        }
        if (cmd.nCom == 6) {
            Dump();
            continue;
        }
        int nStkA = aPos[cmd.nA] / nStkCnt, nStkB = aPos[cmd.nB] / nStkCnt;
        if (nStkA == nStkB) {
            continue;
        }
        if (cmd.nCom % 2 == 0) {
            ReturnUpperBlock(cmd.nB); //onto
        }
        if (cmd.nCom / 2 == 0) {
            ReturnUpperBlock(cmd.nA); //move
        }
        int nHeiA = aPos[cmd.nA] % nStkCnt;
        int nStkLenA = aStkLen[nStkA], &nStkLenB = aStkLen[nStkB];
        for (aStkLen[nStkA] = nHeiA; nHeiA < nStkLenA; ++nHeiA) {
            int nBlk = aStks[nStkA][nHeiA];
            aPos[nBlk] = nStkB * nStkCnt + nStkLenB;
            aStks[nStkB][nStkLenB++] = nBlk;
        }
    }
    Dump();
    return 0;
}
