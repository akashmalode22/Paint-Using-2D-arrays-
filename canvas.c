//
// Created by Trixi on 12/8/2017.
//

#include "canvas.h"

#include <stdlib.h>
#include <stdio.h>


void display_board(const Board board) {
  //  vertical axis label
  for (int row = 0; row < board.num_rows; ++row) {
    printf("%d ", board.num_rows - 1 - row);
    for (int col = 0; col < board.num_cols; ++col) {
      printf("%c ", board.the_board[row][col]);
    }
    printf("\n");
  }
  printf("  ");
  //  horizontal axis label
  for(int col = 0; col < board.num_cols; ++col){
    printf("%d ", col);
  }
  printf("\n");

}



Board create_board(const int num_rows, const int num_cols, const char blank_space) {
  Board board;
  board.num_rows = num_rows;
  board.num_cols = num_cols;
  board.blank_space = blank_space;
  board.the_board = (char**) malloc(num_rows * sizeof(char*));
  for(int row = 0; row < num_rows; ++row){
    board.the_board[row] = (char*) malloc(num_cols * sizeof(char));
    for (int col = 0; col < num_cols; ++col) {
      board.the_board[row][col] = blank_space;
    }
  }

  return board;
}

bool is_board_full(const Board board) {
  for (int row = 0; row < board.num_rows; ++row) {
    for (int col = 0; col < board.num_cols; ++col) {
      if (board.the_board[row][col] == board.blank_space) {
        return false;
      }
    }
  }
  return true;
}
void clean_up(Board* board) {
  for (int row = 0; row < board->num_rows; ++row) {
    free((board->the_board)[row]);
  }
  free(board->the_board);
  board->the_board = NULL;
}
