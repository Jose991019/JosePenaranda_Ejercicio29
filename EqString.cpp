#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;
const float dx = 0.01;
const float dt = 0.01;
const float c = 1.0/2.0;
const float c1 = dx/dt;
const float ratio = 0.25;

int main(){
    ofstream outfile;
    outfile.open("datos.txt");
    float xi[101][3] = {0};
    for(int i = 0; i < 101; i ++){
        xi[i][0] = sin(M_PI*i/100);
    }
    for(int i = 0; i < 101; i ++){
        outfile<< xi[i][0] <<" ";
    }
    outfile<<endl;
    for(int i = 1; i < 100; i++){
        xi[i][1] = xi[i][0] + 0.5*ratio*(xi[i+1][0]+xi[i-1][0]-2*xi[i][0]);
    }
    for(int i = 0; i < 101; i ++){
        outfile<< xi[i][1] <<" ";
    }
    outfile<<endl;
    for(int i = 0; i < 599; i ++){
        for(int j = 1;j<100;j++){
            xi[j][2] = 2*xi[j][1] - xi[j][0] + ratio*(xi[j+1][1] + xi[j-1][1]-2*xi[j][1]);
        }
        for(int k = 0; k < 101; k ++){
                outfile<< xi[k][2] <<" ";
            }
        outfile<<endl;
        for(int j = 0;j<101;j++){
            xi[j][0]=xi[j][1];
            xi[j][1]=xi[j][2];
        }
    }
    
    outfile.close();
    
    return 0;
}