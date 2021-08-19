#ifndef sandpiles_h
#define sandpiles_h
#include <stdio.h>
void sandpiles_print(int grid[3][3]);
int sandpiles_check(int grid1[3][3]);
void sandpiles_compute(int (*grid1)[3], int grid2[3][3]);
void sandpiles_toppling(int (*grid1)[3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
#endif
