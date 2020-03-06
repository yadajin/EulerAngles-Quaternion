#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define RAD 57.29577951f
void QuaternionToEulerAngles(double qx, double qy, double qz, double qw)
{
	double Φ, θ, Ψ;//俯仰角pitch,滚动角roll,航向角yaw
	Φ = atan2f(2.f*(qw*qx + qy * qz), 1 - 2 * (qx*qx + qy * qy));
	θ = asinf(2.f*(qw*qy - qz*qx));
	Ψ = atan2f(2.f*(qw*qz + qx * qy), 1 - 2 * (qy*qy + qz * qz));
	printf("Ψ=%lf deg\nθ=%lf deg\nΦ=%lf deg\n\n", Ψ*RAD, θ*RAD, Φ*RAD);
}
void EulerAnglesToQuaternion(  float Ψ ,float θ,float Φ)
{
	float x, y, z, w;
	w = cosf(Φ*0.5f)*cosf(θ*0.5f)*cosf(Ψ*0.5f) + sinf(Φ*0.5f)*sinf(θ*0.5f)*sinf(Ψ*0.5f);
	x = sinf(Φ*0.5f)*cosf(θ*0.5f)*cosf(Ψ*0.5f) - cosf(Φ*0.5f)*sinf(θ*0.5f)*sinf(Ψ*0.5f);
	y = cosf(Φ*0.5f)*sinf(θ*0.5f)*cosf(Ψ*0.5f) + sinf(Φ*0.5f)*cosf(θ*0.5f)*sinf(Ψ*0.5f);
	z = cosf(Φ*0.5f)*cosf(θ*0.5f)*sinf(Ψ*0.5f) - sinf(Φ*0.5f)*sinf(θ*0.5f)*cosf(Ψ*0.5f);
	printf("%f,%f,%f,%f\n\n", x, y, z, w);
}
int main()
{
	double x, y, z, w;
	double Φ, θ, Ψ;
	int a;
	while (1)
	{
		printf("【1:四元素->欧拉角，2:欧拉角->四元素】->>>");
		scanf("%d",&a);
		switch (a)
		{
		case 1:
			scanf("%lf,%lf,%lf,%lf",&x,&y,&z,&w);
			QuaternionToEulerAngles(x,y,z,w);
			break;
		case 2:
			scanf("%lf %lf %lf", &Ψ, &θ, &Φ);
			EulerAnglesToQuaternion(Ψ / RAD, θ / RAD, Φ / RAD);
			break;
		default:
			break;
		}
	}
	return 0;
}
