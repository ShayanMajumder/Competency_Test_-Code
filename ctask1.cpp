#include<iostream>
#include<cmath>
double Radius1(double x, double y);
double Theta(double x, double y);
double Radius2(double x, double y, double z);
double Theta2(double x, double y, double z);
double Alpha(double x, double y, double z);



class affine_matrix
{
	public:
	double matrix[3][3];
	void read_matrix()
	{
		std::cout << "enter the affine matrix 3X3 order\n";
		for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			{std::cin>>matrix[i][j];
			}
	}

};


 
int main()
{
	std::cout <<"hello world \n";
	affine_matrix c;
	c.read_matrix();
	double cord[3];
	double r, theta, z,phi;
	double new_coordinates[3];
	
	std::cout << "press 1 for cartisian 2 for cylindrical and 3 for spherical\n";
	int a;
	std::cin >> a;
	switch (a) 
	{
	case 1:
		std::cout << "Enter the coordinates in x,y and z \n";
		std::cin >> cord[0] >> cord[1] >> cord[2];
		for (int i = 0; i < 3; i++)
		{
			new_coordinates[i] = c.matrix[i][0] * cord[0] + c.matrix[i][1] * cord[1] + c.matrix[i][2] * cord[2];

		}
		
		std::cout << "NEW coordinates are in cartisian form are\n" << new_coordinates[0] << '\n' << new_coordinates[1] << '\n' << new_coordinates[2];
		break;
	case 2:
		std::cout << "Enter the coordinates in r,theta(in radians) and z  \n";
		std::cin >> r >> theta >> z;
    
		for (int o = 0; o < 3; o++)
		{
			new_coordinates[o] = c.matrix[o][0] * (r * cos(theta)) + c.matrix[o][1] * (r * sin(theta)) + c.matrix[o][2] * z;

		}
		std::cout << "NEW coordinates are in cylindrical form are\n" << Radius1(new_coordinates[0], new_coordinates[1]) << '\n' << Theta(new_coordinates[0], new_coordinates[1]) << '\n' << new_coordinates[2];
    break;
	case 3:
		std::cout << "Enter the coordinates in r,theta(in radians) and phi(in radians)  \n";
		std::cin >> r >> theta >> phi;
		for (int g = 0; g < 3; g++)
		{
			new_coordinates[g] = c.matrix[g][0] * (r * sin(phi) * cos(theta)) + c.matrix[g][1] * (r * sin(phi) * sin(theta)) + c.matrix[g][2] * (r * cos(phi));

		}
		std::cout << "NEW coordinates in spherical form are\n" << Radius2(new_coordinates[0], new_coordinates[1],new_coordinates[2]) << '\n' << Theta2(new_coordinates[0], new_coordinates[1], new_coordinates[2]) << '\n' << Alpha(new_coordinates[0], new_coordinates[1], new_coordinates[2]);
		break;
	default:
		std::cout << "wrong input";

	}

	return 0;

}
double Radius2(double x, double y,double z)
{
	double rads;
	rads = sqrt(x*x+y*y+z*z);
	return rads;
}

double Radius1(double x, double y)
{
	double rad;
	rad = sqrt((pow(x, 2)) + (pow(y, 2)));
	return rad;
}
double Theta(double x, double y)
{
	double Thta;
	Thta = atan(y / x);
	return Thta;
}
double Theta2(double x, double y,double z)
{
	double mno;
	mno = atan(y/x);
	return mno;
}
double Alpha(double x, double y, double z)
{
	double alpa;
	alpa = atan((sqrt(x*x +y*y) )/ z);
	return alpa;
}
