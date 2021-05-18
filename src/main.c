#include "include.h"

// Keep 2:1
int SCREEN_WIDTH = 60;
int SCREEN_HEIGHT = 30;

double fov = 30; // equ camera height

#define buff[SCREEN_WIDTH][SCREEN_HEIGHT];
char shades[] = " .:-=+*#%@";

Object** SCENE;

int main(int argc, char** argv){
	Point3* vertices = calloc(3, sizeof(*vertices));
	double ret;
	vertices[0] = *new_point(1, 1, 0);
	vertices[1] = *new_point(3, 3, 1);
	vertices[2] = *new_point(2, 2, 2);
	poly_lineseg_collide_3d(vertices, 3, 0, 0, 0, 10, 10, 10, &ret);
	double foo;
	double bar;
	int baz = lineseg_collide_2d(1, 0, 2, 2, 0, 0, 10, 10, &foo, &bar);
	printf("%d", baz);
	return 0;
}