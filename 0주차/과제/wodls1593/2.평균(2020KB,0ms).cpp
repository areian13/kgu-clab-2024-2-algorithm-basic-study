#include <iostream>

int main(){

    using namespace std;

    int N;

    cin >> N;

    float num[N];
    int max = 0;
    float sum = 0;

    for(int i=0;i<N;i++){
        cin >> num[i];
        if(max<num[i])
            max = num[i];
    }
    for(int i=0; i<N;i++){

        sum += (num[i]/max)*100;;
    }

    cout << sum/N;
    return 0;
}