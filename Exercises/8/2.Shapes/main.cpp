#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iomanip>
////////////////////////////////////////////////////
class point
{
    float x;
    float y;

public:
    point(float _x = 0, float _y = 0);

    float X() const { return x; }
    float Y() const { return y; }
    void setX(float _x) { x = _x; }
    void setY(float _y) { y = _y; }

    static float getDistance(const point &p1, const point &p2);

    friend std::istream &operator>>(std::istream &in, point &obj);
};

class shape
{
protected:
    int n;
    std::vector<point> vertices;
    std::vector<float> sidesLength;
    std::string color;

public:
    virtual float getPerimeter() const;
    virtual float getArea() const;

    virtual void getin();
    virtual void print();
    virtual ~shape() = 0;
};

class nshape : public shape
{
protected:
    std::vector<float> diametersLength;

public:
    virtual void getin();
    virtual void print();
    virtual ~nshape() = 0;
};

class triangle : public shape
{
public:
    triangle() { n = 3; }
};

class rectangle : public nshape
{
public:
    rectangle() { n = 4; }
};

class square : public rectangle
{
};

class diamond : public nshape
{
public:
    diamond() { n = 4; }
};

class hexagon : public nshape
{
public:
    hexagon() { n = 6; }
};

class octagon : public nshape
{
public:
    octagon() { n = 8; }
};
////////////////////////////////////////

//point class
point::point(float _x, float _y)
{
    x = _x;
    y = _y;
}

float point::getDistance(const point &p1, const point &p2)
{
    float dx = p1.X() - p2.X();
    float dy = p1.Y() - p2.Y();
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

std::istream &operator>>(std::istream &in, point &obj)
{
    std::string temp;
    in >> temp;

    int colonPos = temp.find(":");
    obj.x = std::stof(temp.substr(0, colonPos));
    obj.y = std::stof(temp.substr(colonPos + 1));

    return in;
}

//shape class

float shape::getPerimeter() const
{
    return std::accumulate(sidesLength.begin(), sidesLength.end(), 0.0);
}

float shape::getArea() const
{
    float sum = vertices[n - 1].X() * vertices[0].Y();
    for (int i = 0; i < n - 1; i++)
        sum += (vertices[i].X() * vertices[i + 1].Y()) - (vertices[i].Y() * vertices[i + 1].X());
    sum -= vertices[n - 1].Y() * vertices[0].X();
    if(sum < 0)
        sum *= -1;
    return sum / 2.0;
}

void shape::getin()
{
    //GREEN : 0:0 2:0 1:4
    std::string temp;
    std::cin >> color;
    std::cin >> temp; // gets a colon

    point vertex;
    for (int i = 0; i < n; i++)
    {
        std::cin >> vertex;
        vertices.push_back(vertex);
        if (i != 0)
        {
            float dis = point::getDistance(vertices[i], vertices[i - 1]);
            sidesLength.push_back(dis);

            if (i == n - 1)
            {
                dis = point::getDistance(vertices[i], vertices[0]);
                sidesLength.push_back(dis);
            }
        }
    }
}

void shape::print()
{
    std::cout << color << " : "
              << getPerimeter() << " "
              << getArea() << std::endl;
}

shape::~shape() {}

//nshape

void nshape::getin()
{
    this->shape::getin();
    for (int i = 0; i < n - 2; i++) //set diameters length
    {
        for (int j = i + 2; j < n; j++)
        {
            if (i != 0 || j != n - 1)
                diametersLength.push_back(point::getDistance(vertices[i], vertices[j]));
        }
    }
    std::sort(diametersLength.rbegin(), diametersLength.rend());
}

void nshape::print()
{
    std::cout << color << " : "
              << getPerimeter() << " "
              << getArea() << " ";

    for (auto i = diametersLength.begin(); i != diametersLength.end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;
}
nshape::~nshape() {}

int main()
{
    std::cout << std::fixed << std::setprecision(2);
    int n, tmp;
    std::cin >> n;
    std::vector<int> shape_num;
    for (int i = 0; i < n; i++)
    {
        std::cin >> tmp;
        shape_num.push_back(tmp);
    }

    shape *sptr = nullptr;
    for (int i = 0; i < n; i++)
    {
        if (shape_num[i] == 1)
            sptr = new triangle;
        if (shape_num[i] == 2)
            sptr = new rectangle;
        else if (shape_num[i] == 3)
            sptr = new diamond;
        else if (shape_num[i] == 4)
            sptr = new square;
        else if (shape_num[i] == 5)
            sptr = new hexagon;
        else if (shape_num[i] == 6)
            sptr = new octagon;

        sptr->getin();
        sptr->print();
        delete sptr;
    }

    return 0;
}