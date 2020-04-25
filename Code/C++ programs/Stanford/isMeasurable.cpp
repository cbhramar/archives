#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

bool isMeasurable(int target, vector<int> & weights);

int main(){
    vector<int> weights = {1, 2, 4, 8};
    while (true){
        cout << "How much do you want to measure? " << endl;
        int target;
        cin >> target;
        if (target == -1) break;
        if (isMeasurable(target, weights)) cout << "This weight is indeed measurable" << endl;
        else cout << "This is not measurable, sorry :(" << endl;
    }

    return 0;
}

bool isMeasurable(int target, vector<int> & weights){
    if (weights.size() == 1) {
        return target == weights[0];
    }
    else {
        vector<int> restweights(weights.size() - 1);
        int singleElement = weights[0];
        for (int i = 1; i < weights.size(); i++){
            restweights[i - 1] = weights[i];
        }
        return isMeasurable(target, restweights) || isMeasurable(target + singleElement, restweights) || isMeasurable(target - singleElement, restweights) || target == singleElement;
    }
}
