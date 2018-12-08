//
// Created by Trixi on 12/7/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "commands.h"
#include "write.h"

void get_command(Board board, char* userKey){
  printf("Enter a command: ");
  scanf("%c", userKey);
  printf("user key is %c\n", *userKey);
  if(*userKey == 'h'){
    print_help();
  }else if(*userKey == 'w'){
    Coordinates start;
    Coordinates end;
    get_Coordinates(board, &start, &end);
    write_line(board, start, end);
  }

  return;
}
/*
bool is_valid_command(Commands command, int num_args_read){

  return false;
}
*/
void print_help(){

  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
}

