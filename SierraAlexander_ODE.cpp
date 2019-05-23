#include <iostream>
#include <fstream>
#include <math.h>


int main()
{
    
int nt = 10;
float dt = 0.1;
float m = 7294.29;
float q = 2;
float t = 0.0;

float x[nt];float y[nt];
x[0] = 1.0;y[0] = 0.0;// Position

float Sx[nt];float Sy[nt];
Sx[0] = 0.0;Sy[0] = 1.0;// Speed
float Bx = 0.0;float By = 0.0;
for ( int i = 0; i < nt; ++i)    
{
        
        // Magnetic Field 2D
        if(3<t<7)
        {
        float Bx = 0.0;float By = 3.0;
        }

    
    
        //Hallo los k1 del Runge_Kutta para las posiciones y para las velocidades 
        double k1x = Sx[i];
        double k1y = Sy[i];
        double k1Sx = -q/m*(Sy[i]*By) ;    //Producto cruz: de v y B, lo mismo para todo lo demas 
        double k1Sy = q/m*(Sx[i]*Bx);

        //Hallo los k2 del Runge_Kutta para las posiciones y para las velocidades, lo mismo para K3, y K4 solo que la formula cambia 
        double k2x = k1x + (0.5*dt*k1Sx);   
        double k2y = k1y + (0.5*dt*k1Sy);
        double k2Sx = q/m*( -  (0.5*dt)*By); //Otra vez hallo el producto cruz pero este cambia 
        double k2Sy = -q/m*(-  (0.5*dt)*Bx);

        double k3x = k1x + (0.5*dt*k2Sx);  //Hallo k3 de posiciones y  velocidades 
        double k3y = k1y + (0.5*dt*k2Sy);
        double k3Sx = q/m*(Sy[i]+0.5*dt*k2Sy);
        double k3Sy = -q/m*(Sx[i]+0.5*dt*k2Sx);

        double k4x = k1x + k3Sx*dt; //Hallo k4 de posiciones y  velocidades 
        double k4y = k1y + k3Sy*dt;
        double k4Sx = q/m* (Sy[i]+dt*k3Sy);
        double k4Sy = -q/m* (Sx[i]+dt*k3Sx);

        //Aplicar la formula general de Runge_Kuta 4orden Para las posiciones y para las velocidades 
        y[i+1] = y[i] + (1.0/6.0)*dt*(k1y + 2*k2y +2*k3y + k4y);        
        x[i+1] = x[i] + (1.0/6.0)*dt*(k1x + 2*k2x +2*k3x + k4x);

        Sx[i+1] = Sx[i] + (1.0/6.0)*dt*(k1Sx + 2*k2Sx +2*k3Sx + k4Sx);
        Sy[i+1] = Sy[i] + (1.0/6.0)*dt*(k1Sy + 2*k2Sy +2*k3Sy + k4Sy);

        std::cout<< t <<" "<< x[i] << " " << y[i] << " " <<std::endl;
        t +=dt;

    }

    return 0; 



    










}





