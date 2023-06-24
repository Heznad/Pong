/*#include <stdio.h>
#include <stdlib.h>

#define bool int

#define BALL_INITIAL_POS_X 12;
#define BALL_INITIAL_LEFT_POS_Y 38;
#define BALL_INITIAL_RIGHT_POS_Y 41;

/*
    TODO:
    1. пофиксить init_ball;
    2. пофиксить начальное расположение шарика (X, Y) - X:25, Y:80
    3. пофиксить проверки на столкновение
*/

/*void init_ball();
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
/*int speedY; // Смещение по Y

enum {
    LEFT_DOWN = 0,
    LEFT_UP,
    RIGHT_DOWN,
    RIGHT_UP
} direction;

int main() {
    init_ball();
    return 0;
}

// Вызывается при запуске программы
void init_ball() {
    direction = rand() % 4;
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
}*/
