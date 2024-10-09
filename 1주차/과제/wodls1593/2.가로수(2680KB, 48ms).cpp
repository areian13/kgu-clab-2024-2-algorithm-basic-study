#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_n 100000

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a%b);
}

int main(){
    int N;
    int tree[MAX_n];
    int treeDistance[MAX_n];
    int gcd=0, cnt=0;
    cin >> N;

    for (int i=0; i< N; i++){
        cin >> tree[i];
    }
    
    sort(tree, tree + N);

    for(int i=0; i<N-1;i++){
        treeDistance[i] = tree[i+1] - tree[i];
    }

    gcd = treeDistance[0];
    for(int i=1; i < N-1;i++){
        gcd = GCD(gcd, treeDistance[i]);
    }

    for(int i =0; i<N-1; i++){
        cnt += treeDistance[i];
    }
    cnt = cnt/gcd - (N-1);
    cout << cnt;

}