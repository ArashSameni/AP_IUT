template <typename T>
class Vector
{
    T *_arr;
    int _count;

public:
    Vector();
    Vector(int count);
    Vector(const T* arr, int count);
    Vector(const Vector& obj);
    void push_back(const T data);
    void push_front(const T data);
    void insert(int index, const T data);
    T pop();
    T remove(int index);
    int search(T data);
    int size();
    void swap(int index1, int index2);
    void reverse();
    void sort();
    void print();
};