#include <iostream>
using namespace std;

//Multiple Inheritance
class Multiple_A
{
public:
    int a;
};

class Multiple_B
{
public:
    int b;
};

class Multiple_C
{
public:
    int c;
};

class Multiple_D : public Multiple_A, public Multiple_B, public Multiple_C
{
public:
    int d;
};

//Hybrid Inheritance
class Hybrid_A
{
public:
    int roll_no;
    string name;
    string branch;
};

class Hybrid_B
{
public:
    string city;
    string state;
    int pin;
};

class Hybrid_C : public Hybrid_A
{
public:
    int height;
    int weight;
};

class Hybrid_D : public Hybrid_C, public Hybrid_B
{
public:
    string game_name;
};

//Hierarchical Inheritance
class Hierarchical_A
{
public:
    int roll_no;
    string name;
};

class Hierarchical_B : public Hierarchical_A
{
public:
    string rank_med;
};

class Hierarchical_C : public Hierarchical_A
{
public:
    string rank_engg;
};

class Hierarchical_D : public Hierarchical_A
{
public:
    string rank_biotech;
};