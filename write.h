//
// Created by Trixi on 12/8/2017.
//

#ifndef PAINT_WRITE_H
#define PAINT_WRITE_H

#include "canvas.h"
typedef struct Coordinates_struct {
  int row;
  int col;
}Coordinates;

void get_Coordinates(Board board, Coordinates* start, Coordinates* end);
void write_line(Board board, Coordinates start, Coordinates end);
void horizontal(Board board, Coordinates start, Coordinates end);
void vertical(Board board, Coordinates start, Coordinates end);
void left_diag(Board board, Coordinates start, Coordinates end);
void right_diag(Board board, Coordinates start, Coordinates end);
bool is_pos_slope(Coordinates start, Coordinates end);


#endif //PAINT_WRITE_H
