#include <iostream>
using namespace std;

class Quad
{
protected:
    float sides[4];

public:
    Quad(float x, float y, float z, float v)
    {
        sides[0] = x;
        sides[1] = y;
        sides[2] = z;
        sides[3] = v;
    }
    virtual float getArea() = 0;
};

class Rectangle : public Quad
{
    float area;

public:
    Rectangle(float x, float y, float z, float v) : Quad(x, y, z, v) {}
    float getArea() { return sides[0] * sides[1]; }
    float getArea(Rectangle &other)
    {
        return other.getArea();
    }
};

int main()
{
    Rectangle rectangle(4.5f, 3.2f, 4.5f, 3.2f);

    cout << "Rectangle Area: " << rectangle.getArea() << endl;
    cout << "Area from top-level function: " << rectangle.getArea(rectangle) << endl;

    return 0;
}