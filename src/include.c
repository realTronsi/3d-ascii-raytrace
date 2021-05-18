#include "include.h"

double dist_point3(Point3 point1, Point3 point2){
	double a = point1.x - point2.x;
	double b = point1.y - point2.y;
	double c = point1.z - point2.z; // height

	double d = sqrt(a * a + b * b); // base
	return sqrt(d * d + c * c);
}

Point3* new_point(double x, double y, double z){
	Point3* point = calloc(1, sizeof(*point));
	point -> x = x;
	point -> y = y;
	point -> z = z;
	return point;
}

int lineseg_collide_2d(
	double Ax1, double Ay1,
	double Ax2, double Ay2,
	double Bx1, double By1,
	double Bx2, double By2,
	double* retx, double* rety
){
	double Am = (Ay2-Ay1)/(Ax2-Ax1);
	double Ab = Ay1 - Am * Ax1;
	double Bm = (By2-By1)/(Bx2-Bx1);
	double Bb = By1 - Bm * Bx1;

	if (Am - Bm == 0)return 0;
	double x = (Bb-Ab)/(Am-Bm);
	double y = x * Am + Ab;
	
	if((x < Ax1 && x < Ax2)
	|| (x > Ax1 && x > Ax2)
	|| (x < Bx1 && x < Bx2)
	|| (x > Bx1 && x > Bx2)
	|| (y < Ay1 && y < Ay2)
	|| (y > Ay1 && y > Ay2)
	|| (y < By1 && y < By2)
	|| (y > By1 && y > By2))return 0;

	*retx = x;
	*rety = y;

	printf("x: %f\ny: %f\n", x, y);

	return 1;
}

int poly_lineseg_collide_2d(
	double* vertices, size_t vsize,
	double x1, double y1, double x2, double y2, double* ret
){
	double* intersections = calloc(1, sizeof(*intersections));
	size_t length = 0; // intersections length

	for(int i = 0; i < vsize; i+=2){
		double retx;
		double rety;
		if(lineseg_collide_2d(x1, y1, x2, y2, vertices[i], vertices[(i+1)%vsize], vertices[(i+2)%vsize], vertices[(i+3)%vsize], &retx, &rety) == 1){
			length += 2;
			intersections = realloc(intersections, length * sizeof(*intersections));
			intersections[length - 2] = retx;
			intersections[length - 1] = rety;
		}
	}

	//printf("intersections: %d xcoord: %f\n", length, intersections[0]);

	if(length == 0) return 0;
	ret = &intersections;

	printf("length: %d\n\n", length);

	return 1;
}

int poly_lineseg_collide_3d(
	Point3* vertices, size_t vsize,
	double x1, double y1, double z1, double x2, double y2, double z2, double* ret
){
	// XY side
	double* xyvertices = calloc(vsize * 2, sizeof(*xyvertices));
	double xyret;
	for(int i=0; i < vsize; i++){
		xyvertices[i * 2] = vertices[i].x;
		xyvertices[i * 2 + 1] = vertices[i].y;
	}

	if(poly_lineseg_collide_2d(xyvertices, vsize, x1, y1, x2, y2, &xyret) == 0)return 0;

	// XZ side
	double* xzvertices = calloc(vsize * 2, sizeof(*xzvertices));
	double xzret;
	for(int i=0; i < vsize; i++){
		xzvertices[i * 2] = vertices[i].x;
		xzvertices[i * 2 + 1] = vertices[i].z;
	}

	if(poly_lineseg_collide_2d(xzvertices, vsize, x1, z1, x2, z2, &xzret) == 0)return 0;

	// YZ side
	double* yzvertices = calloc(vsize * 2, sizeof(*yzvertices));
	double yzret;
	for(int i=0; i < vsize; i++){
		yzvertices[i * 2] = vertices[i].y;
		yzvertices[i * 2 + 1] = vertices[i].z;
	}

	if(poly_lineseg_collide_2d(yzvertices, vsize, y1, z1, y2, z2, &yzret) == 0)return 0;
}




// vvv IGNORE vvv


int point_in_object(Point3* point, Object* object){
	// get point outside of object
	size_t len = sizeof(object -> vertices)/sizeof(object -> vertices[0]);

	double xbound, ybound, zbound; // min bounds for object
	for(int i = 0; i < len; i++){
		Point3* _point = object -> vertices[i];

		if(_point->x < xbound) xbound = _point->x;
		if(_point->y < ybound) xbound = _point->y;
		if(_point->z < zbound) xbound = _point->z;
	}

	Point3* basepoint = new_point(xbound - 1, ybound - 1, zbound - 1);
	
	 // a point outside of the object

	/*
		Connect given point and basepoint and count intersections
	*/
}
