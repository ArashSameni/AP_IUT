#include <iostream>
#include "inherit.h"
using namespace std;

int main()
{
    Multiple_D mul_d;
    mul_d.a = 1;
    mul_d.b = 2;
    mul_d.c = 3;
    mul_d.d = 4;

    Hybrid_C hyb_c;
    hyb_c.roll_no = 1;
    hyb_c.name = "ðâïļ";
    hyb_c.branch = "ð";
    hyb_c.height = 185;
    hyb_c.weight = 90;
    Hybrid_D hyb_d;
    hyb_d.roll_no = 1;
    hyb_d.name = "ðâïļ";
    hyb_d.branch = "ð";
    hyb_d.height = 185;
    hyb_d.weight = 90;
    hyb_d.city = "ð";
    hyb_d.state = "ðĪŠ";
    hyb_d.pin = 23;
    hyb_d.game_name = "ðð";

    Hierarchical_B hie_B;
    hie_B.name = "ðŦ";
    hie_B.roll_no = 2;
    hie_B.rank_med = "ð­";
    return 0;
}