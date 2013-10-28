#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cfloat>

using namespace std;

typedef struct point {
    int x, y;
}point_t;

int cpt[8] = {0,1,2,3,4,5,6,7};
point_t pts[8];
int path[8];
double res[8];

int V;

#define PF(x) ((x) * (x)) 

int main() {

    int t = 1;
    while (scanf("%d", &V), V) {
        double maxval = FLT_MAX;
        printf("**********************************************************\nNetwork #%d\n", t++);
        for (int i = 0; i < V; ++i) {
            scanf("%d%d", &pts[i].x, &pts[i].y);
        }

        do {
            double sum = 0;
            double tmp[8];
            for (int i = 1; i < V; ++i) {
                tmp[i] = sqrt(PF(abs(pts[cpt[i]].x - pts[cpt[i-1]].x)) 
                        + PF(abs(pts[cpt[i]].y - pts[cpt[i-1]].y))) + 16;
                sum += tmp[i];
                if (sum > maxval)
                    break;
            }

            if (maxval > sum) {
                maxval = sum;
                for (int i = 0; i < V; ++i) {
                    path[i] = cpt[i];
                    res[i] = tmp[i];
                }
            }
        } while(next_permutation(cpt, cpt + V));

        for(int i = 1; i < V; ++i) {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", pts[path[i-1]].x, pts[path[i-1]].y, pts[path[i]].x, pts[path[i]].y, res[i]);
        }
        printf("Number of feet of cable required is %.2f.\n", maxval);
    }

}
