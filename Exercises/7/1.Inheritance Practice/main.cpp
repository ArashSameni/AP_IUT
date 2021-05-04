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
    hyb_c.name = "😁✌️";
    hyb_c.branch = "😐";
    hyb_c.height = 185;
    hyb_c.weight = 90;
    Hybrid_D hyb_d;
    hyb_d.roll_no = 1;
    hyb_d.name = "😁✌️";
    hyb_d.branch = "😐";
    hyb_d.height = 185;
    hyb_d.weight = 90;
    hyb_d.city = "👀";
    hyb_d.state = "🤪";
    hyb_d.pin = 23;
    hyb_d.game_name = "😐💋";

    Hierarchical_B hie_B;
    hie_B.name = "😫";
    hie_B.roll_no = 2;
    hie_B.rank_med = "😭";
    return 0;
}