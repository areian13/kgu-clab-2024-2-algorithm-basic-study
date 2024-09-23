#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){
    int N;
    std::cin >> N;

    vector<double> scores(N);
    for(int i=0; i<N; i++){
        std::cin >> scores[i];
    }

    double M = *std::max_element(scores.begin(), scores.end()); 

    double sum = 0; 
    for(int i = 0; i<N; i++){
        sum += (scores[i]/M)*100;
    }
    
    cout << sum/N << endl;
    return 0;
}