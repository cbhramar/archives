#include<simplecpp>

long recursiveExp(int n, int k){
//    long r = 1;
    if (k == 0){
        return 1;
    }
    else {
        if (k%2 == 1){
            return n*recursiveExp(n, k-1);
        }
        else
            return recursiveExp(n, k/2)*recursiveExp(n, k/2);
    }
}

main_program{
    int n;
    int k;
    cout << "Enter n, k in that order :" << endl;
    cin >> n >> k;
    cout << "n ^ k is :" << endl;
    cout << recursiveExp(n, k) << endl;
}
