//
// Created by Trixi on 12/8/2017.
//

#ifndef PAINT2_CANVAS_H
#define PAINT2_CANVAS_H

#include "stdbool.h"
typedef struct board_struct{
  char** the_board;
  int num_rows;
  int num_cols;
  char blank_space;
}Board;

void display_board(const Board board);
Board create_board(const int num_rows, const int num_cols, const char blank_space);
bool is_board_full(const Board board);
void clean_up(Board* board);

#endif //PAINT2_CANVAS_H
