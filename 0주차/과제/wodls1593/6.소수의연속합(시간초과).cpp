#include <iostream>

int check(int n){
    for(int i =2; i< n; i++){
            if(n%i == 0)
                return 0;
    }
    return n;
}
int main(){

    using namespace std;

    int N;

    cin >> N;

    int arr[N] = {0,};
    int cnt =0;
    for(int j = N; j > 1; j--){
        if(check(j) != 0){
            arr[cnt++] = check(j);
        }

    }

    for (int i = 0; i < cnt; i++)
    {
        cout << arr[i] << endl;
    }
    int check = cnt;
    cnt = 0;
    int sum = 0;
    int sCnt = 0;
    int result = 0;
    while(true){
        
        if(sum > N){
            sum = 0;
            cnt++;
            sCnt = cnt;
        }
        if(sum == N) result++;
        if(sCnt > check) 
        {
            cout << sCnt << endl;
            break;
        }
        sum += arr[sCnt++];

    }

    cout << result << endl;
    return 0;
}