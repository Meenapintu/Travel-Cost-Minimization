#ifndef TRAVEL_COST_H
#define TRAVEL_COST_H
#include <iostream>
using namespace std;


struct BNI{  //BOOL AND INT
    int maxf;
    int dest;
};

class Travel_cost
{
    private:
        double *D,*P;
        double *costs;
        double max_run = 100;//km
        int curr_location =0;
        double curr_fuel =1;
        int max_fuel =1;
        double frc = (double)1/100 ;//fuel consumption rate
        int n;
        double tcost=0;

    protected:

    public:
        /** Default constructor */
        Travel_cost(int n);

        /** Default destructor */
        virtual ~Travel_cost();

        /** take input array D[1...n] and P[1...n] */
        void get_DP();

        /** set the value of current fuel and current location ,
        takes the required fuel and finds the next optimal station */
        void reached(int from);

    protected:
        /** return the maximum run distance from a given point(only station points are valid) */
        int get_max_run(int start);

        /** return the index of  minimum costly station */
        BNI get_minimum(int range_start);

        /** return the amount of required fuel from current location (private variable ) to given distance  */
        double Req_fuel(int dest_location);

        /** finally prints the total cost and amount of fuel from each station  */
        void print(double arr[]);

};

#endif // TRAVEL_COST_H
