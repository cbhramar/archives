#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

bool isSubsetSum(vector<int> & vec, int target);
int countSubsetSumWays(vector<int> & vec, int target);

int main() {
    while (true) {
        int veclength;
        cout << "Enter the length of your vector :" << endl;
        cin >> veclength;
        if (veclength == 0) break;
        cout << "Enter your numbers : " << endl;
        vector<int> vec;
        for (int i = 0; i < veclength; i++) {
            int n;
            cin >> n;
            vec.push_back(n);
        }
        int target;
        cout << "Enter your target : " << endl;
        cin >> target;
        if (isSubsetSum(vec, target)) cout << "It is possible, and there are " << countSubsetSumWays(vec, target) << " ways to do so" << endl;
        else cout << "It isn't possible" << endl;
    }
    return 0;
}

bool isSubsetSum(vector<int> & vec, int target) {
    if (vec.size() == 0) {
        return target == 0;
    }
    else{
        int element = vec[0];
        vector<int> rest (vec.size() - 1);
        for (int i = 1; i < vec.size(); i++) {
            rest[i - 1] = vec[i];
        }
        return (isSubsetSum(rest, target) || isSubsetSum(rest, target - element));
    }
}

int countSubsetSumWays(vector<int> & vec, int target) {
    int way = 0;
    if (vec.size() == 0) {
        if (target == 0) {
            way = 1;
        }
        else way = 0;
    }
    else{
        int element = vec[0];
        vector<int> rest (vec.size() - 1);
        for (int i = 1; i < vec.size(); i++) {
            rest[i - 1] = vec[i];
        }
        way = countSubsetSumWays(rest, target) + countSubsetSumWays(rest, target - element);
    }
    return way;
}
