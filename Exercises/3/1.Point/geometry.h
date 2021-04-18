class point
{
    int x, y;

public:
    point(int type = 0);
    point(int _x, int _y);
    int getX();
    int getY();
    void setX(int _x);
    void setY(int _y);
    void set(int _x, int _y);
    float length();
    void print();
};