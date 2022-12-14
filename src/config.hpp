#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_
#include "raylib.h"
#include <string>

const int SCREEN_WIDTH {1280}, SCREEN_HEIGHT {720};
const int PADDLE_WIDTH {30}, PADDLE_HEIGHT {200};
const int BALL_SIZE {20};

const int PADDLE_WALL_DIST {100};
const float PADDLE_START_Y {(SCREEN_HEIGHT / 2) - (PADDLE_HEIGHT / 2)};
const float BALL_START_X {(SCREEN_WIDTH / 2) - (BALL_SIZE / 2)}, BALL_START_Y {(SCREEN_HEIGHT / 2) - (BALL_SIZE / 2)};

const float CPU_PADDLE_CENTER_RANGE {40};
const float CPU_PADDLE_REACT_TIME {0.3f};

const int FRAME_TARGET {144};

const float PADDLE_SPEED {500}, BALL_SPEED {300};
const float BALL_VELOCITY_OFFSET {200};
const float BALL_SPEED_INCREASE {10};

const float COUNT_DOWN_TIME {3};

const int SCORE_TEXT_TOP_OFFSET {10}, SCORE_TEXT_BETWEEN_OFFSET {100};
const int SMALL_FONT_SIZE {40}, MEDIUM_FONT_SIZE {60}, LARGE_FONT_SIZE {100};
const int FONT_SHADOW_OFFSET {12};

const char* TITLE_NAME {"Raylib Pong"};
const int TITLE_POS_X {SCREEN_WIDTH / 2 - 290};//MeasureText(TITLE_NAME, LARGE_FONT_SIZE) / 2}; doesn't work?
const int TITLE_POS_Y {100};

const int MENU_BUTTON_SIZE_X {400}, MENU_BUTTON_SIZE_Y {150};
const int MENU_PLAY_POS_X {SCREEN_WIDTH / 2 - MENU_BUTTON_SIZE_X / 2}, MENU_PLAY_POS_Y {SCREEN_HEIGHT / 2 - MENU_BUTTON_SIZE_Y / 2};
const int MENU_BUTTON_SPACE {50};
const int MENU_QUIT_POS_X {MENU_PLAY_POS_X}, MENU_QUIT_POS_Y {MENU_PLAY_POS_Y + MENU_BUTTON_SIZE_Y + MENU_BUTTON_SPACE};

const int SMALL_BUTTON_SIZE_X {120}, SMALL_BUTTON_SIZE_Y {45};
const int SMALL_BUTTON_POS_X {SCREEN_WIDTH / 2 - SMALL_BUTTON_SIZE_X / 2}, SMALL_BUTTON_POS_Y {SCREEN_HEIGHT - SMALL_BUTTON_SIZE_Y - 10};

const Color BALL_COLOR {255,50,50,255};

const std::string SCORE_STRING {"Your score was "};
const int MAX_NAME_CHARS {9};
const float INPUT_BLINK_TIME {0.6f};

#endif