#include <cstdio>

char word[9][32] = {
    "straight-flush\0",
    "four-of-a-kind\0",
    "full-house\0",
    "flush\0",
    "straight\0",
    "three-of-a-kind\0",
    "two-pairs\0",
    "one-pair\0",
    "highest-card\0"
};

// hand[14][0-3] 记录的是黑红梅方的数量
// hand[1-13][4] 记录的是每张牌不分花色的数量
char hand[14][5];

char deck[14][5];

char map[256];

void init() {
    for (char c = '2'; c < '9'; ++c) {
        map[c] = c - '2';
    }
    map['T'] = 8; map['J'] = 9; map['Q'] = 10; map['K'] = 11;
    map['A'] = 12;
    map['C'] = 0; map['D'] = 1; map['H'] = 2; map['S'] = 3;
}

int judgeBest() {
    for(int i = 0; i < 13; ++i) {
        int sum = 0
        for(int j = 0; j < 4; ++j) {
            sum += hand[i][j];
        }
        hand[i][4] = sum;
    }

    for (int j = 0; j < 4; ++j) {
        int sum = 0;
        for(int i = 0; i< 13; ++i) {
            sum += hand[i][j];
        }
        hand[13][j] = sum;
    }

    int p = 0;
    int num = 0;
    for(int i = 0; i < 13; ++i) {
        if (hand[i][4] == 4) {
            return 1;
        }
        if (hand[i][4] == 1) {
            num ++;
            if (num == 5 && hand[i][4] == hand[i-1][4] 
                    && hand[i-1][4] == hand[i-2][4] 
                    && hand[i-2][4] == hand[i-3][4] 
                    && hand[i-3][4] == hand[i-4][4]) {
                if (hand[13][0] == 5 && hand[13][1] == 5
                        && hand[13][2] == 5 && hand[13][3] == 5) {
                    return 0;
                } 

                return 4;
            }
        }
        if (hand[i][4] == 3) {
            for(int i = 0; i < 13; ++i) {
                if (hand[i][4] == 2)
                    return 2;
            }
        }
    }

    for(int j = 0; j < 4; ++j) {
        if (hand[13][i] == 5){
            return 3;
        }
    }

    int s = 1;
    for(int i = 0; i < 13; ++i) {
        if (hand[i][4] != 0) {
            s *= hand[i][4];
        }
    }

    if (s == 3)
        return 5;
    if (s == 4)
        return 6;
    if (s == 2)
        return 7;
    return 8;
}

int main() {
    
}
