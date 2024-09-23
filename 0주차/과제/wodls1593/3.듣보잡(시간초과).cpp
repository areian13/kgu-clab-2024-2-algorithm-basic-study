#include <iostream>
#include <algorithm>
#include <string>

int main(){

    using namespace std;
    
    int N;
    int M;

    int cnt =0;

    cin >> N >> M;

    string firstName[N];
    string secondName[M];
    //string* sumName;
    int test[500000];
    for(int i =0; i<N; i++){
        cin >> firstName[i];
    }

    sort(firstName, firstName+N);

    for(int i =0; i<M; i++){
        cin >> secondName[i];
    }

    sort(secondName, secondName+M);

    for(int i =0; i<N; i++){
        for(int j =i; j<M; j++){
            if(firstName[i].compare(secondName[j]) == 0){
                test[cnt] = i;
                cnt++;
            }
        }
    }

        
    // sumName = new string[cnt];
    
    // for(int i =0; i< cnt;i++){
    //     sumName[i] = secondName[test[i]];
    // }
    
    cout << cnt << endl;

    //sort(secondName[0], secondName[M]);
    
    for(int i =0; i< cnt; i++){
        cout << firstName[test[i]] << endl;
    }
    return 0;
}