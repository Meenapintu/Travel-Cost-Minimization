#include "Travel_cost.h"

Travel_cost::Travel_cost(int n)
{
    this->D = (double*)calloc(n,sizeof(double));
    this->P =  (double*)calloc(n,sizeof(double));
    this->costs =  (double*)calloc(n,sizeof(double));
    this->n = n;

}

Travel_cost::~Travel_cost()
{
    //dtor
}

void Travel_cost::get_DP(){
    double p,d;
    for(int i=1;i<this->n;i++){
        cin>>d>>p;
        this->D[i] =d;
        this->P[i] =p;
    }
    //print(this->D);
    //this->print(this->P);
}
int Travel_cost::get_max_run(int start)
{
    double temp=0;
    for(int i=start+1;i<n;i++)
    {
            temp+=this->D[i]-this->D[i-1];
            if(temp == max_run)return i;
            else if(temp >max_run)return i-1;
    }
    return n-1;
}
BNI Travel_cost::get_minimum(int range_start)
{

    int t = get_max_run(range_start);
    BNI temp;
    temp.maxf = 0;
    temp.dest=t;
    double min = this->P[range_start];
    for(int i=range_start+1;i<=t;i++){
        if(min >= this->P[i])
        {
           // cout<<this->P[i]<<"  ";
            min=this->P[i];
            temp.dest =i;
            temp.maxf=-1;
            break;
        }
    }
    if(temp.maxf != -1){
           min =1111111;
            temp.maxf= t;
        for(int i=range_start+1;i<=t;i++){
                //cout<<this->P[i]<<"  ";
        if(min >= this->P[i])
        {
            min=this->P[i];
            temp.dest =i;
        }
    }
    }
    return temp;
}
void Travel_cost::reached(int from)
{


    BNI nstep = this->get_minimum(from);
    if(nstep.maxf != -1)
    {    //cout<<nstep.maxf<< "+++++++++" <<endl;
         if(nstep.maxf < n-1)
         {
             this->costs[from] = 1- this->curr_fuel;
             this->curr_fuel = 1 -(this->D[nstep.dest]-this->D[this->curr_location])*this->frc;
             this->tcost +=this->costs[from]*this->P[from];

         }
         else
        {
            this->costs[from] = this->Req_fuel(nstep.maxf);
            this->tcost +=this->costs[from]*this->P[from];
        }
        this->curr_location=nstep.dest;
    }
    else
    {
    //cout<<nstep.maxf<< "++++______" <<endl;
    this->costs[from] = this->Req_fuel(nstep.dest);
    this->tcost +=this->costs[from]*this->P[from];
    this->curr_location=nstep.dest;
    }
    if(nstep.dest != n-1 && nstep.maxf !=n-1)
    {
       // cout<<"REACHED TO ONE MILE STONE "<<this->curr_location<<" WITH Fuiel "<<this->curr_fuel <<"  "<<this->D[this->curr_location]<<endl;
       this->reached(this->curr_location);

    }
    else{
       // cout<<"REACHED TO ONE MILE STONE "<<this->curr_location<<" WITH Fuiel "<<this->curr_fuel <<"  "<<this->D[this->curr_location]<<endl;
        this->print(this->costs);
    }
}

double Travel_cost::Req_fuel(int dest)
{
    double temp;
    temp = this->curr_fuel -(this->D[dest]-this->D[this->curr_location])*this->frc;
    if(temp>0)
    {
        this->curr_fuel = temp;
        return 0;
    }
    else {
        this->curr_fuel=0;
        return 0-temp;
    }
}


void Travel_cost::print(double arr[])
{
    //cout<<"Printing out the total cost and quantity from every station\n";
    cout<<this->tcost<<"   ";
    for(int i=0;i<this->n;i++)
        cout<<arr[i]<<"   ";
    cout<<'\n';
}
