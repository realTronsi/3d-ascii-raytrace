#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double x;
	double y;
	double z;
} Point3;

double dist_point3(Point3 point1, Point3 point2); // distance between 2 3d points

Point3* new_point(double x, double y, double z);

int poly_lineseg_collide_3d(
	Point3* vertices, size_t vsize,
	double x1, double y1, double z1, double x2, double y2, double z2, double* ret
);

int lineseg_collide_2d(
	double Ax1, double Ay1,
	double Ax2, double Ay2,
	double Bx1, double By1,
	double Bx2, double By2,
	double* retx, double* rety
);

typedef struct {
	Point3** vertices; // shape vertices
	double shade; // (0 - 1) black - white
	double rcoef; // (0 - 1) none - perfect mirror reflectivitiy 
} Object;

#endif