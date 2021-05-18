#ifndef CAMERA_H
#define CAMERA_H

#include "include.h"
#include "ray.h"

typedef struct {
	Point3* pos;
	double alpha; // z-axis rotation
	double beta; // xy-axis rotation
	double length;
} Camera;

Camera* new_camera(double x, double y, double z, double alpha, double beta, double length);

#endif