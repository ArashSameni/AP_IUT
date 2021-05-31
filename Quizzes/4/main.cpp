#include "Store.h"

int main()
{
    Store s;
    Food *f = new Food(4000, 25);
    Dress *d1 = new Dress(5000);
    Dress *d2 = new Dress(4000);
    s.addProduct(f);
    s.addProduct(d1);
    s.addProduct(d2);

    std::cout << s.sell("dress") << std::endl
              << s.sell("food", 20) << std::endl
              << s.sell("dress") << std::endl
              << s.sell("furniture") << std::endl;
}