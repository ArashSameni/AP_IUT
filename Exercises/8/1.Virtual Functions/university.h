#include <iostream>

class person
{
protected:
    int id;
    int age;
    std::string name;

public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class professor : public person
{
    int publications;
    static int curid;

public:
    professor(std::string _name = "", int _age = 0, int _publications = 0);
    void getdata();
    void putdata();
};

class student : public person
{
    int marks[6];
    static int curid;

public:
    student(std::string _name = "", int _age = 0);
    void getdata();
    void putdata();
};