#include "camera.h"

Camera* new_camera(double x, double y, double z, double alpha, double beta, double length){
	Camera* camera = calloc(1, sizeof(*camera));
	camera -> pos = new_point(x, y, z);
	camera -> alpha = alpha;
	camera -> beta = beta;
	camera -> length = length;
	return camera;
}

int** camera_cast(
	Camera camera, 
	int** buffer, // output buffer
	int sw, // screen width
	int sh, // screen height
	double fov
){
	for(int c = 0; c < sw; c++){
		for(int r = 0; r < sh; r++){
			double z = r/sh * fov - fov / 2; // unweighted z
			//double z_diff = z - camera.pos.z;
			double theta = atan(z/camera.length); // angle to pixel relative to origin
			z = 1 / (tan(theta + camera.beta) * camera.length);

			double y = c/sh * fov * 2 - fov; // unweighted y
			theta = atan(y/camera.length) + camera.alpha;

			double x = cos(theta) * camera.length;
			y = sin(theta) * camera.length;

			double sum = x + y + z;
			Ray* _ray = new_ray(*camera.pos, x/sum, y/sum, z/sum);
			int pixel = ray_cast(_ray);
			buffer[c][r] = pixel;
		}
	}
}