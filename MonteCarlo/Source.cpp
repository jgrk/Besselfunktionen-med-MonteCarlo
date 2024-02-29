

#include <iostream>
#include <vector>

#include <random>

#define _USE_MATH_DEFINES

#include <math.h>






//Motsvarar integranden som definiers i Bessel-funktionen

inline double integr_func(int &n, double &theta, double &r)
{
    
    double re = cos(n * theta) * cos(r * sin(theta)) + sin(n * theta) * sin(r * sin(theta));

    return re; 

}


int main() {

    //antal simuleringar
    const long int n_sims = pow(10, 7);
    
    //RNG-generator

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-M_PI, M_PI);

    
    //radie r - polära koordinater

    
    double r;

    int n;

    //integral summor
    double h = 0.0;
    double im_h = 0.0;
    

    double val;

    std::cout << "Approximative Evaluation of the BesselJ-function using the Monte Carlo integration method" << std::endl;
    std::cout << "r = "; 
    std::cin >> r;
    std::cout << "n = ";
    std::cin >> n; 
    std::cout << "Running " << n_sims << " simulations.." << std::endl;

   
    
    for (int i = 0; i < n_sims; i++)
    {

      
        double rand_num = dis(gen);
     
        val = integr_func(n, rand_num, r);

        h += val;

    }

    h = h  / (n_sims);


    std::cout << std::endl << "Real part of J" << n << "( " << r << " ) = " << h << std::endl;

    return 0;
}
