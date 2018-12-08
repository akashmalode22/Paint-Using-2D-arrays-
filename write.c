//
// Created by Trixi on 12/8/2017.
//

#include <stdio.h>
#include "write.h"
#include "canvas.h"

void get_Coordinates(Board board, Coordinates* start, Coordinates* end){
  int startRow, endRow;
  scanf("%d %d %d %d", &startRow, &start->col, &endRow, &end->col);
  // scanf("%d %d %d %d", &start->row, , &end->row, &end->col);

  start->row = board.num_rows  - startRow - 1;
  end->row = board.num_rows - endRow - 1;
  //end->col = endCol + 1;

  printf("Start: %d, %d  End: %d, %d\n", start->row, start->col, end->row, end->col);
}
void write_line(Board board, Coordinates start, Coordinates end){
  if(start.row == end.row){
    horizontal(board, start, end);
  }else if (start.col == end.col){
    vertical(board, start, end);
  }else if(is_pos_slope(start, end)){
    left_diag(board, start, end);
  }else if(!is_pos_slope(start, end)){
    right_diag(board, start, end);
  }
}

void horizontal(Board board, Coordinates start, Coordinates end){
  char horizontal_line = '-';
  int i = start.row;
  if(start.col < end.col+1){
    for(int j = start.col; j < end.col + 1; ++j){
      if(board.the_board[i][j] == '|' || board.the_board[i][j] == '/' || board.the_board[i][j] == '\\') {
        board.the_board[i][j] = '+';
      }else{
        board.the_board[i][j] = horizontal_line;
      }
    }
  }else{
    for(int j = end.col; j < start.col + 1; ++j){
      if(board.the_board[i][j] == '|' || board.the_board[i][j] == '/' || board.the_board[i][j] == '\\') {
        board.the_board[i][j] = '+';
      }else{
        board.the_board[i][j] = horizontal_line;
      }
    }
  }
}

void vertical(Board board, Coordinates start, Coordinates end){
  char vertical_line = '|';

  int j = start.col;
  if (start.row < end.row){
    for(int i = start.row; i < end.row + 1; ++i){
      if(board.the_board[i][j] == '-' || board.the_board[i][j] == '/' || board.the_board[i][j] == '\\') {
        board.the_board[i][j] = '+';
      }else{
        board.the_board[i][j] = vertical_line;
      }
    }
  }else{
    for(int i = end.row; i < start.row + 1; ++i){
      if(board.the_board[i][j] == '-' || board.the_board[i][j] == '/' || board.the_board[i][j] == '\\') {
        board.the_board[i][j] = '+';
      }else{
        board.the_board[i][j] = vertical_line;
      }
    }
  }
}

void left_diag(Board board, Coordinates start, Coordinates end){
  printf("LEFT DIAGONAL\n");
  printf("Start: %d, %d  End: %d, %d\n", start.row, board.num_cols - start.col- 1, end.row, board.num_cols -end.col -1);
  if (start.col < end.col){
    int j = end.col;
    for (int i = end.row ; i < start.row + 1; ++i) {
      if(board.the_board[i][j] == '-' || board.the_board[i][j] == '|' || board.the_board[i][j] == '\\') {
        board.the_board[i][j] = '+';
      }else{
        board.the_board[i][j] = '/';
      }
      --j;
    }
  }else{
    int j = start.col;
    for (int i = start.row; i < end.row + 1; ++i){
      if(board.the_board[i][j] == '-' || board.the_board[i][j] == '|' || board.the_board[i][j] == '\\') {
        board.the_board[i][j] = '+';
      }else{
        board.the_board[i][j] = '/';
      }
      --j;
    }
  }
}

void right_diag(Board board, Coordinates start, Coordinates end){
  printf("RIGHT DIAGONAL\n");
  printf("Start: %d, %d  End: %d, %d\n", start.row, board.num_cols - start.col- 1, end.row, board.num_cols -end.col -1);
  int j = end.col;
  for (int i = start.row ; i < end.row + 1; ++i) {
    if(board.the_board[i][j] == '-' || board.the_board[i][j] == '|' || board.the_board[i][j] == '\\') {
      board.the_board[i][j] = '+';
    }else{
      board.the_board[i][j] = '\\';
    }
    ++j;
  }
}
bool is_pos_slope(Coordinates start, Coordinates end) {
  int m = (start.col-end.col)/(start.row-end.row);
  if(m>0){
    return true;
  }
  return false;
}
