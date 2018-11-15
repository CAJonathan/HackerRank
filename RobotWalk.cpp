#include<iostream>
#include<cmath>

using namespace std;

const int step = 10;

int n;
int m;
int prime;
float rotation;
int count;

struct ROBOTFOOTAGE
{
	double ordinate;	// Tung do
	double abscissa;	// Hoanh do
	float angle;	// Goc hop voi truc hoanh
};
typedef struct ROBOTFOOTAGE foot;

// Khoi tao cac gia tri ban dau
void Initialize(foot *F)
{
	F->abscissa = 0;
	F->ordinate = 0;
	F->angle = 0;
	
	cin >> n >> m >> prime;
	rotation = 2 * M_PI / n;
}

// Di theo chieu kim dong ho
void Clockwise(foot *F)
{
	F->angle += rotation / 2;
	F->ordinate += step * cos(F->angle);
	F->abscissa += step * sin(F->angle);
	F->angle += rotation / 2;
}

// Lui mot buoc sau khi di theo chieu kim dong ho
void CBackward(foot *F)
{
	F->angle -= rotation / 2;
	F->ordinate -= step * cos(F->angle);
	F->abscissa -= step * sin(F->angle);
	F->angle -= rotation / 2;
}

// Di theo chieu nguoc kim dong ho
void Anticlockwise(foot *F)
{
	F->angle -= rotation / 2;
	F->ordinate += step * cos(F->angle);
	F->abscissa += step * sin(F->angle);
	F->angle -= rotation / 2;
}

// Lui mot buoc sau khi di theo chieu nguoc kim dong ho
void ABackward(foot *F)
{
	F->angle += rotation / 2;
	F->ordinate -= step * cos(F->angle);
	F->abscissa -= step * sin(F->angle);
	F->angle += rotation / 2;
}

// Tim duong di cho robot
void findPath(int pos, foot *F)
{
	if(pos == m)
	{
		// Do so thuc dau phay dong khong bieu dien duoc so 0 nen ta chap nhan mot gia tri rat be coi nhu bang 0
		if(fabs(F->abscissa) <= 5e-005 && fabs(F->ordinate) <= 5e-005)
		{
			count = count % prime + 1;
		}
		return;
	}
	Clockwise(F);
	findPath(pos + 1, F);
	CBackward(F);
	Anticlockwise(F);
	findPath(pos + 1, F);
	ABackward(F);
}

int main()
{
	foot F;
	Initialize(&F);
	findPath(0, &F);
	cout << count;
	return 0;
}
