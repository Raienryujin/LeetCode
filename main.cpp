#include <iostream>
#include <string>

int main() 
{   
    std::string cars[5] = {"Audi","Bentley","Chevrolet","Datsun","Aston Martin"};
    for(int i = 0; i < sizeof(cars)/sizeof(cars[0]); i++)
    {
        std::cout << cars[i] << std::endl;
    }
} 