//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI

/*#include <stdio.h>
#include <stdlib.h>

#define bool int

#define BALL_INITIAL_POS_X 12;
#define BALL_INITIAL_LEFT_POS_Y 39;
#define BALL_INITIAL_RIGHT_POS_Y 40;

void new_field(int x, int sl, int sr);
void field(int x, int y, int lh, int rh);

void init_ball();
void move_ball();
void process_wall_collision();
void process_racket_collision();
void process_boundary_collision();
void change_wall_ball_direction();
void change_racket_ball_direction();
bool is_ball_collided_with_wall();
bool is_ball_collided_with_racket();
bool is_ball_collided_with_boundary();

int posX; // Текущая позиция по X
int posY; // Текущая позиция по Y
int speedX; // Смещение по X
int speedY; // Смещение по Y
/*int scoreL; // Счёт слева
int scoreR; // Счёт справа

enum {
    LEFT_DOWN = 0,
    LEFT_UP,
    RIGHT_DOWN,
    RIGHT_UP
} direction;

int main() {
    init_ball();
    new_field(posY, 0, 0);
    char action;
    scanf("%c", &action);
    switch (action) {
    case 'A':
        break;
    case 'a':
        break;
    case 'Z':
        break;
    case 'z':
        break;
    case 'K':
        break;
    case 'k':
        break;
    case 'M':
        break;
    case 'm':
        break;
    case ' ':
        break;
    default:
        printf("n/a");
        break;
    };
    return 0;
}

// Вызывается при запуске программы
void init_ball() {
    direction = rand() % 2;
    posX = BALL_INITIAL_POS_X;

    if (direction == 0) {
        posY = BALL_INITIAL_LEFT_POS_Y;
        speedX = -1;
        speedY = 0;
    }
    else {
        posY = BALL_INITIAL_RIGHT_POS_Y;
        posX = 1;
        speedX = 1;
        speedY = 0;
    }
}

void move_ball() {
    if (is_ball_collided_with_wall()) {
        process_wall_collision();
    }
    else if (is_ball_collided_with_racket()) {
        process_racket_collision();
    }
    else if ((is_ball_collided_with_boundary())) {
        process_boundary_collision();
    }
    else {
        posX += speedX;
        posY += speedY;
    }
}

void process_wall_collision() {
    change_wall_ball_direction();
}

void process_racket_collision() {
    change_racket_ball_direction();
}

void process_boundary_collision() {
    //
}

// Изменение траектории шарика при столкновении с верхней или нижней стенкой
void change_wall_ball_direction() {
    switch (direction) {
    case LEFT_DOWN:
        posX += speedX;
        posY += speedY;
        speedX = -speedX;
        speedY = -1;
        direction = LEFT_UP;
        break;

    case LEFT_UP:
        posX += speedX;
        posY += speedY;
        speedX = -speedX;
        speedY = -1;
        direction = LEFT_DOWN;
        break;

    case RIGHT_UP:
        posX += speedX;
        posY += speedY;
        speedX = -speedX;
        speedY = 1;
        direction = RIGHT_DOWN;
        break;

    default:
        posX += speedX;
        posY += speedY;
        speedX = -speedX;
        speedY = 1;
        direction = RIGHT_DOWN;
        break;
    }
}

// Изменение траектории шарика при столкновении с ракеткой
void change_racket_ball_direction() {
    switch (direction) {
    case LEFT_DOWN:
        posX += speedX;
        posY += speedY;
        speedX = 1;
        speedY = -speedY;
        direction = RIGHT_DOWN;
        break;

    case LEFT_UP:
        posX += speedX;
        posY += speedY;
        speedX = -1;
        speedY = -speedY;
        direction = RIGHT_UP;
        break;

    case RIGHT_UP:
        posX += speedX;
        posY += speedY;
        speedX = -1;
        speedY = -speedY;
        direction = LEFT_UP;
        break;

    default:
        posX += speedX;
        posY += speedY;
        speedX = 1;
        speedY = -speedY;
        direction = LEFT_DOWN;
        break;
    }
}

bool is_ball_collided_with_wall() {
    return (posX == 0 || posX == 24);
}

bool is_ball_collided_with_racket(int racketCenterY) {
    // X = 2 77
    return ((posX == 2) && (posY == racketCenterY || posY == racketCenterY + 1 || posY == racketCenterY - 1)) ||
        ((posX == 77) && (posY == racketCenterY || posY == racketCenterY + 1 || posY == racketCenterY - 1));
}

bool is_ball_collided_with_boundary() {
    return (posY == 0 || posY == 79);
}

void new_field(int x, int sl, int sr) {
    int sl1 = sl / 10, sl2 = sl % 10, sr1 = sr / 10, sr2 = sr % 10;
    for (int i = 0; i < 80; i++)
        printf("=");
    printf("\n");

    for (int j = 1; j < 24; j++) {
        for (int i = 0; i < 80; i++) {
            switch (i) {
            case 30:
                if (j == 7)
                    printf("%d", sl2);
                else
                    printf(" ");
                break;
            case 29:
                if (j == 7) {
                    if (sl1 == 0)
                        printf(" ");
                    else
                        printf("%d", sl1);
                }
                else
                    printf(" ");
                break;
            case 49:
                if (j == 7) {
                    if (sr1 == 0) {
                        printf("%d ", sr2);
                        i++;
                    }
                    else {
                        printf("%d%d", sr1, sr2);
                        i++;
                    }
                }
                else
                    printf(" ");
                break;
            case 0:
                printf("|");
                break;
            case 79:
                printf("|\n");
                break;
            case 39:
                if (j == 12 && x == 39) {
                    printf("*[");
                    i++;
                }
                else
                    printf("]");
                break;
            case 40:
                if (j == 12 && x == 40)
                    printf("*");
                else
                    printf("[");
                break;
            case 2:
            case 77:
                if (j == 11)
                    printf("A");
                else if (j == 12)
                    printf("N");
                else if (j == 13)
                    printf("V");
                else
                    printf(" ");
                break;
            default:
                printf(" ");
            }
        }
    }

    for (int i = 0; i < 80; i++)
        printf("=");
    printf("=\n");

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

    for (int i = 0; i < 79; i++)
        printf("=");
    printf("= ");
}*/


