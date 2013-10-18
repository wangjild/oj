#include <cstdio>
#include <cstring>

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

void print();

// hand[14][0-3] 记录的是黑红梅方的数量
// hand[1-13][4] 记录的是每张牌不分花色的数量
char hand[14][5];
char deck[14][5];

char map[256];
char rmap[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 
    'T', 'J', 'Q', 'K', 'A'};
char cmap[4] = {'C', 'D', 'H', 'S'};

inline int min(int a, int b) {
    return a < b ? a : b;
}

void init() {
    for (char c = '2'; c <= '9'; ++c) {
        map[c] = c - '2';
    }
    map['T'] = 8; map['J'] = 9; map['Q'] = 10; map['K'] = 11;
    map['A'] = 12;
    map['C'] = 0; map['D'] = 1; map['H'] = 2; map['S'] = 3;
}

int judgeBest() {
    for(int i = 0; i < 13; ++i) {
        int sum = 0;
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
            if (num == 5 && 
                    ((hand[i][4] == 1 && hand[i-1][4] == 1 && hand[i-2][4] == 1 
                      && hand[i-3][4] == 1 && hand[i-4][4] == 1) 
                     || (hand[0][4] == 1 && hand[1][4] == 1 && hand[2][4] == 1
                         && hand[3][4] == 1 && hand[12][4] == 1))) {

                if (hand[13][0] == 5 || hand[13][1] == 5
                        || hand[13][2] == 5 || hand[13][3] == 5) {
                    return 0;
                } 

                return 4;
            }
        }
        if (hand[i][4] == 3) {
            for(int i = 0; i < 13; ++i) {
                if (hand[i][4] == 2) {
                    return 2;
                }
            }
        }
    }

    for(int j = 0; j < 4; ++j) {
        if (hand[13][j] == 5) {
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

void print() {
    for (int i = 0; i < 13; ++i) {
        for(int j = 0; j < 4; ++j) {
            if (hand[i][j] != 0)
                printf("%c%c ", rmap[i], cmap[j]);
        }
    }
    printf("\nColor: ");
    for (int i = 0; i < 4; ++i) {
        if (hand[13][i] != 0)
            printf("%d%c ", hand[13][i], cmap[i]);
    }
    printf("\nCard:  ");
    for (int i = 0; i < 13; ++i) {
        if (hand[i][4] != 0)
            printf("%d%c ", hand[i][4], rmap[i]);
    }
    printf("\n");
}

int solve(char *str) {
    int ans = 10;

    for (int i = 0; i < (1<<5); ++i) {
        int num = 0; 
        for (int j = 0; j < 5; ++j) {
            if (i & (1 << j)) {
                hand[map[str[j*3]]][map[str[j*3+1]]] = 0;
                hand[map[str[15 + num*3]]][map[str[15 + num*3 + 1]]] = 1;
                num ++;	
            }
        }

        ans = min(ans, judgeBest());

        num = 0;
        for (int j = 0; j < 5; ++j) {
            if (i & (1 << j)) {
                hand[map[str[j*3]]][map[str[j*3+1]]] = 1;
                hand[map[str[15 + num*3]]][map[str[15 + num*3 + 1]]] = 0;
                num ++;
            }
        }
    }

    return ans;
}

int main() {
    init();

    char str[64];
    memset(str, 0, sizeof(char) * 64);
    while (gets(str) != NULL) {
        memset(hand, 0, sizeof(char) * 14 * 5);
        str[29] = ' '; str[30] = '\0';
        for (int i = 2; i < 15; i += 3) {
            hand[map[str[i-2]]][map[str[i-1]]] = 1;
        }

        int ans = solve(str);
        printf("Hand: ");
        for (int i = 0; i < 15; ++i) {
            printf("%c", str[i]);
        }
        printf("Deck: ");
        for (int i = 15; i < 30; ++i) {
            printf("%c", str[i]);
        }
        printf("Best hand: %s\n", word[ans]);
    }
}
