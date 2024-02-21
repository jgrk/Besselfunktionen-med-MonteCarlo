

#include <iostream>
#include <vector>


#include <complex>
#include <random>

#define _USE_MATH_DEFINES

#include <math.h>






//Motsvarar integranden som definiers i Bessel-funktionen

std::complex<double> integr_func(int n, double theta, double r, double pi)
{
    
    std::complex<double> a( cos( n * theta ), -sin( n * theta ) );
    std::complex<double> b( cos( r * sin(theta) ), sin( r * sin(theta) ) );

    return (1 / (2 * pi)) * a * b; 

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
    

    std::complex<double> val;

    std::cout << "Approximative Evaluation of the BesselJ-function using the Monte Carlo integration method" << std::endl;
    std::cout << "r = "; 
    std::cin >> r;
    std::cout << "n = ";
    std::cin >> n; 
    std::cout << "Running " << n_sims << " simulations.." << std::endl;

    
    for (int i = 0; i < n_sims; i++)
    {

      
        double rand_num = dis(gen);

        val = integr_func(n, rand_num, r, M_PI);

        h += real(val);
        im_h += imag(val);

    }

    h = h * (2.0*M_PI ) / (n_sims);
    im_h = im_h * (2.0 * M_PI) / (n_sims);

    std::cout << std::endl << "Real part of J" << n << "( " << r << " ) = " << h << std::endl;
    std::cout << std::endl << "Imaginary part of J" << n << "( " << r << " ) = " << im_h << std::endl;


    return 0;
}
