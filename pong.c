#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void Started_Field(); // прорисовки поля в начале игры
void Field(); // прорисовка поля с изменениями
void init_ball(); // начальная траектория движения мячика
void move_ball(); // изменение координаты мячика
void process_wall_collision(); // удар об стены
void process_racket_collision(); // удар об ракетку
void process_boundary_collision(); // достижение боковых границ
void change_wall_ball_direction(); // изменение направления от удара об стены
void change_racket_ball_direction(); // изменение направления от удара об ракетку
void change_score(); // изменение счёт и прорисовка поля в начальное положение
_Bool is_ball_collided_with_wall(); // проверка на столкновение со стенами
_Bool is_ball_collided_with_racket(); // проверка на столкновение с ракеткой
_Bool is_ball_collided_with_boundary(); // проверка со столкновением с боковыми границами

int scoreL = 0;
int scoreR = 0;
int racket_center_R = 12;
int racket_center_L = 12;
int racket_posX_L = 2;
int racket_posX_R = 77;
int posX = 40;
int posY = 12;
int speedX = 0;
int speedY = 0;

enum {
    LEFT_DOWN = 0,
    LEFT_UP,
    RIGHT_DOWN,
    RIGHT_UP
} direction;

int main() {
	Started_Field();
    init_ball();
    char action = 0;
	while ((scoreL < 21)&&(scoreR < 21)) { 
        //scanf(" %c[^\0]", &action);
        action = getch();
        switch (action)
        {
        case 'A':
        case 'a':
            if (racket_center_L != 2)
                racket_center_L = racket_center_L - 1;
            Field();
            break;
        case 'Z':
        case 'z':
            if (racket_center_L != 22)
                racket_center_L = racket_center_L + 1;
            Field();
            break;
        case 'K':
        case 'k':
            if (racket_center_R != 2)
                racket_center_R = racket_center_R - 1;
            Field();
            break;
        case 'M':
        case 'm':
            if (racket_center_R != 22)
                racket_center_R = racket_center_R + 1;
            Field();
            break;
        case ' ':
            Field();
            break;
        default:
            printf("n/a");
            break;
        }
    }
    if (scoreL > scoreR)
        printf("\nCongratulations to the player on the left!\n");
    else
        printf("\nCongratulations to the player on the right!\n");
    return 0;
}

void Started_Field()
{
    racket_center_R = 12;
    racket_center_L = 12;
    racket_posX_L = 2;
    racket_posX_R = 77;
    posX = 40;
    posY = 12;
    speedX = 0;
    speedY = 0;

    for (int j = 0; j < 80; j++)
        printf("=");
    printf("\n");

    for (int i = 1; i < 24; i++) {
        printf("|");
        for (int j = 1; j < 79; j++) {
            if (i == posY && j==posX) {
                    printf("*");
            }
            else
                switch (j) {
                case 2:
                    if (i == racket_center_L - 1)
                        printf("A");
                    else if (i == racket_center_L)
                        printf("N");
                    else if (i == racket_center_L + 1)
                        printf("V");
                    else
                        printf(" ");
                    break;
                case 77:
                    if (i == racket_center_R - 1)
                        printf("A");
                    else if (i == racket_center_R)
                        printf("N");
                    else if (i == racket_center_R + 1)
                        printf("V");
                    else
                        printf(" ");
                    break;
                case 39:
                    printf("]");
                    break;
                case 40:
                    printf("[");
                    break;
                case 29:
                    if (i == 3)
                        printf("%d", scoreL);
                    else
                        printf(" ");
                    break;
                case 49:
                    if (i == 3)
                        printf("%d", scoreR);
                    else
                        printf(" ");
                    break;
                default:
                    printf(" ");
                }
        }
        printf("|\n");
    }

    for (int j = 0; j < 80; j++)
        printf("=");
    printf("\n");
}

void Field() {
    move_ball();
    for (int j = 0; j < 80; j++)
        printf("=");
    printf("\n");

    for (int i = 1; i < 24; i++) {
        printf("|");
        for (int j = 1; j < 79; j++) {
            if (i == posY && j == posX) {
                printf("*");
            }
            else
                switch (j) {
                case 2:
                    if (i == racket_center_L - 1)
                        printf("A");
                    else if (i == racket_center_L)
                        printf("N");
                    else if (i == racket_center_L + 1)
                        printf("V");
                    else
                        printf(" ");
                    break;
                case 77:
                    if (i == racket_center_R - 1)
                        printf("A");
                    else if (i == racket_center_R)
                        printf("N");
                    else if (i == racket_center_R + 1)
                        printf("V");
                    else
                        printf(" ");
                    break;
                case 39:
                    printf("]");
                    break;
                case 40:
                    printf("[");
                    break;
                case 29:
                    if (i == 3)
                        printf("%d", scoreL);
                    else
                        printf(" ");
                    break;
                case 49:
                    if (i == 3)
                        printf("%d", scoreR);
                    else
                        printf(" ");
                    break;
                default:
                    printf(" ");
                }
        }
        printf("|\n");
    }

    for (int j = 0; j < 80; j++)
        printf("=");
    printf("\n");
}

void init_ball() {
    direction = rand() % 4;

    switch (direction) {
    case 0:
        speedX = -1;
        speedY = 1;
        break;
    case 1:
        speedX = -1;
        speedY = -1;
        break;
    case 2:
        speedX = 1;
        speedY = 1;
        break;
    case 3:
        speedX = 1;
        speedY = -1;
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
    change_score();
}

void change_wall_ball_direction() {
    switch (direction) {
    case  LEFT_DOWN:
        speedY = -speedY;
        posX += speedX;
        posY += speedY;
        direction = LEFT_UP;
        break;

    case LEFT_UP:
        speedY = -speedY;
        posX += speedX;
        posY += speedY;
        direction = LEFT_DOWN;
        break;

    case RIGHT_UP:
        speedY = -speedY;
        posX += speedX;
        posY += speedY;
        direction = RIGHT_DOWN;
        break;

    default:
        speedY = -speedY;
        posX += speedX;
        posY += speedY;
        direction = RIGHT_DOWN;
        break;
    }
}

void change_racket_ball_direction() {
    switch (direction) {
    case LEFT_DOWN:

        speedX = -speedX;
        posX += speedX;
        posY += speedY;
        direction = RIGHT_DOWN;
        break;

    case LEFT_UP:
        
        speedX = -speedX;
        posX += speedX;
        posY += speedY;
        direction = RIGHT_UP;
        break;

    case RIGHT_UP:
        speedX = -speedX;
        posX += speedX;
        posY += speedY;
        direction = LEFT_UP;
        break;

    default:
        speedX = -speedX;
        posX += speedX;
        posY += speedY;
        direction = LEFT_DOWN;
        break;
    }
}

void change_score() {
    if (posX - 1 == 0) {
        scoreR = scoreR + 1;
        Started_Field();
        init_ball();
    }
    else
    if (posX + 1 == 79) {
        scoreL = scoreL + 1;
        Started_Field();
        init_ball();
    }
}
                
_Bool is_ball_collided_with_wall() {
    return (posY - 1 == 0 || posY + 1 == 24);
}

_Bool is_ball_collided_with_racket() {
    return ((posX - 1 == 2) && (posY == racket_center_L || posY == racket_center_L + 1 || posY == racket_center_L - 1)) ||
        ((posX + 1 == 77) && (posY == racket_center_R || posY == racket_center_R + 1 || posY == racket_center_R - 1));
}

_Bool is_ball_collided_with_boundary() {
    return (posX - 1 == 0 || posX + 1 == 79);
}