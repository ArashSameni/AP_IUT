#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Rational
{
    int a;
    int b;
} Rational;

int bmm(int a, int b)
{
    if (b == 0)
        return a;
    else
        return bmm(b, a % b);
}

void getRational(Rational *i)
{
    int a, b;
    scanf("%d %d", &a, &b);
    i->a = a;
    i->b = b;
}

void print(Rational i)
{
    printf("%d/%d\n", i.a, i.b);
}

void simplify(Rational *i)
{
    int divideBy;
    if (i->a > i->b)
        divideBy = bmm(i->a, i->b);
    else if (i->b > i->a)
        divideBy = bmm(i->b, i->a);
    else
        divideBy = i->a;

    i->a /= divideBy;
    i->b /= divideBy;
}

Rational add(Rational q1, Rational q2)
{
    Rational r;
    if(q1.b != q2.b)
    {
        r.a = (q1.a * q2.b) + (q1.b * q2.a);
        r.b = q1.b * q2.b;
    }else{
        r.a = q1.a + q2.a;
        r.b = q1.b;
    }
    return r;
}

Rational subtract(Rational q1, Rational q2)
{
    q2.a = -q2.a;
    return add(q1, q2);
}

Rational multiply(Rational q1, Rational q2)
{
    Rational r;
    r.a = q1.a * q2.a;
    r.b = q1.b * q2.b;
    return r;
}

void reverse(Rational *i)
{
    int temp = i->a;
    i->a = i->b;
    i->b = temp;
}

Rational divide(Rational q1, Rational q2)
{
    reverse(&q2);
    return multiply(q1, q2);
}

int main()
{
    Rational Q1, Q2, Q3;
    getRational(&Q1);
    getRational(&Q2);


    Q3 = add(Q1, Q2);
    print(Q3);
    simplify(&Q3);
    print(Q3);

    Q3 = subtract(Q1, Q2);
    print(Q3);
    simplify(&Q3);
    print(Q3);

    Q3 = multiply(Q1, Q2);
    print(Q3);
    simplify(&Q3);
    print(Q3);
    
    Q3 = divide(Q1, Q2);
    print(Q3);
    simplify(&Q3);
    print(Q3);
    
    return 0;
}