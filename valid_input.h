//
// Created by Trixi on 12/6/2017.
//

#ifndef PAINT_VALID_INPUT_H
#define PAINT_VALID_INPUT_H
#include <stdbool.h>

void get_dimension(int* num_rows, int* num_cols, int argc, char** argv, int num_args_needed, int num_args_read);
bool is_input_valid(const int num_args_needed, const int num_args_read, char** commandArg);
bool valid_input(const int num_args_read, const int num_args_needed);
bool not_pos(const int val);

#endif //PAINT_VALID_INPUT_H
