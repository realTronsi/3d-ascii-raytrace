#ifndef RAY_H
#define RAY_H

#include "include.h"
#include "camera.h"

typedef struct {
	Point3* pos;
	double acc; // update speed
	double vx, vy, vz; // xyz velocities
} Ray;

#endif