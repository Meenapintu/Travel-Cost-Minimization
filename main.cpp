#include <iostream>
#include "Travel_cost.h"
using namespace std;
/** MAIN FILE */
int main()
{
    int n;
    cin>>n;
    Travel_cost tc =  Travel_cost(n+1);
    tc.get_DP();
    tc.reached(0);
    return 0;
}
