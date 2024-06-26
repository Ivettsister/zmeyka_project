#include "control.hpp"

Control::Control(Snake* s) {
    auto v = View::get();
    snake = s;
    auto f = std::bind(&Control::key_pressed, this, std::placeholders::_1);
    v->set_on_key(f);
}

void Control::key_pressed(int code) {
    switch (code) {
        case 'w':
            if (snake->direction != dir::DOWN)
                snake->direction = dir::UP;
            break;
        case 's':
            if (snake->direction != dir::UP)
                snake->direction = dir::DOWN;
            break;
        case 'a':
            if (snake->direction != dir::RIGHT)
                snake->direction = dir::LEFT;
            break;
        case 'd':
            if (snake->direction != dir::LEFT)
                snake->direction = dir::RIGHT;
            break;
    }
}