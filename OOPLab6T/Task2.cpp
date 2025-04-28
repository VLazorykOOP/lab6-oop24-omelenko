#include <iostream>
#include <cmath>
using namespace std;

class Shape 
{
public:
    virtual double surfaceArea() const = 0;
    virtual ~Shape() {}
};

class Parallelepiped : public Shape 
{
private:
    double a, b, c;
public:
    Parallelepiped(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}
    double surfaceArea() const override 
{
        return 2 * (a * b + b * c + a * c);
    }
};

class Sphere : public Shape 
{
private:
    double r;
    const double PI = 3.14159265359;
public:
    Sphere(double r_) : r(r_) {}
    double surfaceArea() const override 
{
        return 4 * PI * r * r; 
    }
};

class Tetrahedron : public Shape 
{
private:
    double a;
    const double PI = 3.14159265359;
public:
    Tetrahedron(double a_) : a(a_) {}
    double surfaceArea() const override 
{
        return a * a * pow(PI, 3);
    }
};

int task2() 
{
    Parallelepiped parallelepiped(2, 3, 4);
    Sphere sphere(5);
    Tetrahedron tetrahedron(3);

    cout << "Parallelepiped surface area: " << parallelepiped.surfaceArea() << endl;
    cout << "Sphere surface area: " << sphere.surfaceArea() << endl;
    cout << "Tetrahedron surface area: " << tetrahedron.surfaceArea() << endl;

    return 0;
}