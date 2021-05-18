I'm torturing myself by (attempting to) creating a 3d engine with ascii with no outside help at all, so all of the current (and ugly + unoptimized) code comes directly from my brain. I'm planning to cast `SCREEN_WIDTH` (in pixels) by `SCREEN_HEIGHT` # of rays from the camera origin and have them bounce around until fully absorbed, from which the final brightness of the ray and shade of the final surface is added and set as the pixel of the corresponding ray.

The camera object will be responsible for casting these rays:

![camera](https://storage.googleapis.com/replit/images/1618859256176_915dc1f72354eb952d85bed796adcb28.png)

```c
typedef struct {
	Point3* pos;
	double alpha; // z-axis rotation in degrees
	double beta; // xy-axis rotation in degrees
} Camera;
```

The `alpha` and `beta` members correspond to axis rotations

![alpha](https://storage.googleapis.com/replit/images/1618859312802_235073622fa87e423d71278065d46265.png)
![beta](https://storage.googleapis.com/replit/images/1618859312734_20da8d165cf87553bab9aaaadfcd87fc.png)

---

The problem is converting the alpha and beta angles into x, y, and z velocities for each ray. I've thought of a few approaches but I can't seem to put them into code.

## 1) Find the coordinates of the pixel on the camera

![Screen Shot 2021-04-19 at 3.10.52 PM](https://storage.googleapis.com/replit/images/1618859466800_1818ff65fc3828e6e4558c012762b278.png)

Say we had a 4x4 console, that would mean the camera shooting out 16 rays, each corresponding to one pixel. The origin point is where the camera is. 

If we take the top left pixel, the ray the camera shoots must start from the origin point and pass through the pixel. If we can deduce the coordinates of the pixel, we can formulate the velocities for the ray.

Since I don't have rotation on both x and y axises on the same time, rather the rotation is on whichever axis is relative to the current z axis rotation, we can find the z coordinate first.

```c
double z = pixel_row/SCREEN_HEIGHT * fov - fov / 2; // unweighted z
double z_diff = z - camera.pos.z;
double theta = arctan(z_diff/camera.length); // angle to pixel relative to origin
z = 1 / (tan(theta + camera.beta) * camera.length); // add theta to beta for actual pixel degree
```

This should give us the z coordinate of a selected pixel given the row.