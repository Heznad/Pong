/*#include <stdio.h>
void field(int x, int y, int lh, int rh);


int main() {
    int x, y, rh, lh;
    scanf("%d%d%d%d", &x, &y, &rh, &lh);
    field(x, y, rh, lh);


}

void field(int x, int y, int lh, int rh) {
    for (int i = 0; i < 80; i++)
        printf("=");
    printf("\n");

    for (int j = 1; j < 24; j++) {
        printf("|");
        for (int i = 1; i < 79; i++) {
            if (i == x) {
                if (j == y)
                    printf("*");
                else
                    printf(" ");
            }
            else
                switch (i) {
                case 2:
                    if (j == lh - 1)
                        printf("A");
                    else if (j == lh)
                        printf("N");
                    else if (j == lh + 1)
                        printf("V");
                    else
                        printf(" ");
                    break;
                case 77:
                    if (j == rh - 1)
                        printf("A");
                    else if (j == rh)
                        printf("N");
                    else if (j == rh + 1)
                        printf("V");
                    else
                        printf(" ");
                    break;
                case 39:
                    if (x == 39)
                        printf("*");
                    else
                        printf("]");
                    break;
                case 40:
                    if (x == 40)
                        printf("*");
                    else
                        printf("[");
                    break;
                default:
                    printf(" ");
                }
        }
        printf("|\n");
    }

    for (int i = 0; i < 80; i++)
        printf("=");
}*/
