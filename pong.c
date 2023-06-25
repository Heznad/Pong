#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void show_field(); // прорисовка пол€ с изменени€ми
void make_action(char action); // в зависимости от введенной команды
// (AZ/KM/space) происходит какое-то действие
void init_ball(); // начальна€ траектори€ движени€ м€чика
void move_ball(); // изменение координаты м€чика
void process_wall_collision();   // удар об стены
void process_racket_collision(); // удар об ракетку
void process_boundary_collision(); // достижение боковых границ
void change_wall_ball_direction(); // изменение направлени€ от удара об стены
void change_racket_ball_direction(); // изменение направлени€ от удара об
// ракетку
void change_score(); // изменение счЄт и прорисовка пол€ в начальное положение
_Bool is_ball_collided_with_wall(); // проверка на столкновение со стенами
_Bool is_ball_collided_with_racket(); // проверка на столкновение с ракеткой
_Bool is_ball_collided_with_boundary(); // проверка со столкновением с боковыми
// границами
void switch_from_show_field(int i, int j, int ls1, int ls2, int rs1,
    int rs2); // прорисовка ракеток, счЄта и сетки
void case_4_left_racket(int i); //
void case_4_right_racket(int i);
void case_4_left_score_1st_digit(
    int i, int ls1); // функци€ условий дл€ печати первого символа счЄта слева
void case_4_left_score_2nd_digit(
    int i, int ls2); // функци€ условий дл€ печати второго символа счЄта слева
void case_4_right_score_1st_digit(
    int i, int rs1,
    int rs2); // функци€ условий дл€ печати первого символа счЄта справа
void case_4_right_score_2nd_digit(
    int i, int rs1,
    int rs2); // функци€ условий дл€ печати второго символа счЄта справа
void init_base_values(); // функци€ подстановки начальных значений

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
    RIGHT_UP,
} direction;

int main() {
    show_field();
    init_ball();
    while ((scoreL < 21) && (scoreR < 21)) {
        char action = getchar();
        make_action(action);
    }
    if (scoreL > scoreR)
        printf("Congratulations to the player on the left!\n");
    else
        printf("Congratulations to the player on the right!\n");
    return 0;
}

void make_action(char action) {
    switch (action) {
    case 'A':
    case 'a':
        if (racket_center_L != 2)
            racket_center_L = racket_center_L - 1;
        show_field();
        break;
    case 'Z':
    case 'z':
        if (racket_center_L != 22)
            racket_center_L = racket_center_L + 1;
        show_field();
        break;
    case 'K':
    case 'k':
        if (racket_center_R != 2)
            racket_center_R = racket_center_R - 1;
        show_field();
        break;
    case 'M':
    case 'm':
        if (racket_center_R != 22)
            racket_center_R = racket_center_R + 1;
        show_field();
        break;
    case ' ':
        show_field();
        break;
    }
}

void show_field() {
    move_ball();
    int left_score_1st_digit = scoreL / 10, left_score_2nd_digit = scoreL % 10,
        right_score_1st_digit = scoreR / 10, right_score_2nd_digit = scoreR % 10;
    for (int j = 0; j < 80; j++)
        printf("=");
    printf("\n");

    for (int i = 1; i < 24; i++) {
        printf("|");
        for (int j = 1; j < 79; j++) {
            if (i == posY && j == posX) {
                printf("o");
            }
            else
                switch_from_show_field(i, j, left_score_1st_digit, left_score_2nd_digit,
                    right_score_1st_digit, right_score_2nd_digit);
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

void process_wall_collision() { change_wall_ball_direction(); }

void process_racket_collision() { change_racket_ball_direction(); }

void process_boundary_collision() { change_score(); }

void change_wall_ball_direction() {
    switch (direction) {
    case LEFT_DOWN:
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
        init_base_values();
        init_ball();
    }
    else if (posX + 1 == 79) {
        scoreL = scoreL + 1;
        init_base_values();
        init_ball();
    }
}

_Bool is_ball_collided_with_wall() { return (posY - 1 == 0 || posY + 1 == 24); }

_Bool is_ball_collided_with_racket() {
    return ((posX - 1 == 2) &&
        (posY == racket_center_L || posY == racket_center_L + 1 ||
            posY == racket_center_L - 1)) ||
        ((posX + 1 == 77) &&
            (posY == racket_center_R || posY == racket_center_R + 1 ||
                posY == racket_center_R - 1));
}

_Bool is_ball_collided_with_boundary() {
    return (posX - 1 == 0 || posX + 1 == 79);
}

void switch_from_show_field(int i, int j, int left_score_1st_digit,
    int left_score_2nd_digit, int right_score_1st_digit,
    int right_score_2nd_digit) {
    switch (j) {
    case 2:
        case_4_left_racket(i);
        break;
    case 77:
        case_4_right_racket(i);
        break;
    case 39:
        printf("]");
        break;
    case 40:
        printf("[");
        break;
    case 29:
        case_4_left_score_1st_digit(i, left_score_1st_digit);
        break;
    case 30:
        case_4_left_score_2nd_digit(i, left_score_2nd_digit);
        break;
    case 49:
        case_4_right_score_1st_digit(i, right_score_1st_digit,
            right_score_2nd_digit);
        break;
    case 50:
        case_4_right_score_2nd_digit(i, right_score_1st_digit,
            right_score_2nd_digit);
        break;
    default:
        printf(" ");
    }
}

void case_4_left_racket(int i) {
    if (i == racket_center_L - 1)
        printf("|");
    else if (i == racket_center_L)
        printf("|");
    else if (i == racket_center_L + 1)
        printf("|");
    else
        printf(" ");
}

void case_4_right_racket(int i) {
    if (i == racket_center_R - 1)
        printf("|");
    else if (i == racket_center_R)
        printf("|");
    else if (i == racket_center_R + 1)
        printf("|");
    else
        printf(" ");
}

void case_4_left_score_1st_digit(int i, int left_score_1st_digit) {
    if (i == 3) {
        if (left_score_1st_digit != 0)
            printf("%d", left_score_1st_digit);
        else
            printf(" ");
    }
    else
        printf(" ");
}

void case_4_left_score_2nd_digit(int i, int left_score_2nd_digit) {
    if (i == 3)
        printf("%d", left_score_2nd_digit);
    else
        printf(" ");
}

void case_4_right_score_1st_digit(int i, int right_score_1st_digit,
    int right_score_2nd_digit) {
    if (i == 3) {
        if (right_score_1st_digit == 0)
            printf("%d", right_score_2nd_digit);
        else
            printf("%d", right_score_1st_digit);
    }
    else
        printf(" ");
}

void case_4_right_score_2nd_digit(int i, int right_score_1st_digit,
    int right_score_2nd_digit) {
    if (i == 3) {
        if (right_score_1st_digit == 0)
            printf(" ");
        else
            printf("%d", right_score_2nd_digit);
    }
    else
        printf(" ");
}

void init_base_values() {
    racket_center_R = 12;
    racket_center_L = 12;
    racket_posX_L = 2;
    racket_posX_R = 77;
    posX = 40;
    posY = 12;
    speedX = 0;
    speedY = 0;
}
