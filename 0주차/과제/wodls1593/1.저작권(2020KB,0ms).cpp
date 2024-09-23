#include <iostream>

int main(){
    int A;
    int I;
    std::cin >> A;

    std::cin >> I;
    if(1 <= A && A <= 100 && 1 <= I && I <= 100){
        std::cout<< (A * (I-1)) + 1;
    }
    
    return 0;
}