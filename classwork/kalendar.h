#pragma once
#include <vector>
#include <string>
#include <iostream>

void kalendar(int n){
    std::vector <std::string> monts = { "January", "February", 
        "March", "April", "May", "June", "July",
    "August", "September", "October", "November" , "December"};
    
    
    int n_ed = n % 12 ;
    if(n_ed != 0){
    std::cout << monts[n_ed-1];
    }
    if(n_ed == 0){std::cout << monts[11];}
        
}