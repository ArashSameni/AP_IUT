class point
{
    int x, y;

public:
    point(int type = 0);
    point(int _x, int _y);
    int getX() const;
    int getY() const;
    void setX(int _x);
    void setY(int _y);
    void set(int _x, int _y);
    float length() const;
    void print() const;
};

class pointArray
{
    point *arr;
    int size;
    void resize(int _size);

public:
    pointArray();
    pointArray(const point *_arr, int _size);
    void pushBack(const point &p);
    void insert(const int pos, const point &p);
    void remove(const int pos);
    const int getSize() const;
    void clear();
    point *get(const int pos);
    ~pointArray();
};