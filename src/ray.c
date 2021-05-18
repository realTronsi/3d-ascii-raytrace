#include "ray.h"

Ray* new_ray(Point3* pos, double vx, double vy, double vz){
	Ray* _ray = calloc(1, sizeof(*_ray));
	_ray -> pos = pos;
	_ray -> vx = vx;
	_ray -> vy = vy;
	_ray -> vz = vz;
	return _ray;
}

int ray_cast(Ray* ray, Object** SCENE){
	
}