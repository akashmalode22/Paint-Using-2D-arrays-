#include <stdio.h>
#include <stdlib.h>
#include "valid_input.h"
#include "canvas.h"
#include "commands.h"

int main(int argc, char* argv[]) {
  // INPUT VALIDATION
  const int num_args_needed = 3;
  int num_rows;
  int num_cols;
  int num_args_read = argc;

  get_dimension(&num_rows, &num_cols, argc, argv, num_args_needed, num_args_read);

  // DISPLAY BOARD
  const char blank_space = '*';
  char userKey;
  //Commands command;
  Board cur_board = create_board(num_rows, num_cols, blank_space);

  while(userKey != 'q') {
    display_board(cur_board);
    get_command(cur_board, &userKey);
  }

  clean_up(&cur_board);


  return 0;
}