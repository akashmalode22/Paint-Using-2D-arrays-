//
// Created by Trixi on 12/6/2017.
//

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "valid_input.h"

void get_dimension(int* num_rows, int* num_cols, int argc, char** argv, int num_args_needed, int num_args_read){
  if (argc == 1){
    *num_rows = 10;
    *num_cols = 10;
  }
  else if (is_input_valid(num_args_needed, num_args_read, argv)){
    *num_rows = atoi(argv[1]);
    *num_cols = atoi(argv[2]);
  }else{
    *num_rows = 10;
    *num_cols = 10;
  }
}

bool is_input_valid(const int num_args_needed, const int num_args_read, char** commandArg){
  int n = 0;
  int intArg1 = sscanf(commandArg[1], "%d", &n);
  int intArg2 = sscanf(commandArg[2], "%d", &n);
  int num_rows = atoi(commandArg[1]);
  int num_cols = atoi(commandArg[2]);

  if (!valid_input(num_args_read, num_args_needed)){
    printf("Wrong number of command line arguements entered.\n");
    return false;
  } else if(intArg1 == 0){
    printf("The number of rows is not an integer.\n");
    return false;
  }else if(intArg2 == 0){
    printf("The number of columns is not an integer.\n");
    return false;
  }else if(not_pos(num_rows)){
    printf("The number of rows is less than 1.\n");
    return false;
  }else if(not_pos(num_cols)){
    printf("The number of columns is less than 1.\n");
    return false;
  }
  return true;

  // printf("Usage: ./paint.out [num_rows num_cols]\n");
  //printf("Unrecognized command. Type h for help.\n");

}


bool valid_input(const int num_args_read, const int num_args_needed) {
  if (num_args_needed == num_args_read){
    return true;
  }
  printf("Wrong number of command line arguements entered.\n");
  return false;
}

bool not_pos(const int val) {
  // if not positive integer equal to or more than 1
  if (val <= 0){
    return true;
  }
  return false;
}
