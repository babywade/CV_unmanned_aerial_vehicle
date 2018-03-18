#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int pro3[30], pro4[30];
    for(int i = 0; i < 30; i++) {
        pro3[i] = 0;
        pro4[i] = 0;
    }
    int sum = 0;

    for(int i = 1; i <= 6; i++) {
        sum += i;
        for(int j = 1; j <= 6; j++) {
            sum += j;
            for(int k = 1; k <= 6; k++) {
                sum += k;
                ++pro3[sum];
                sum = i + j;
            }
            sum = i;
        }
        sum = 0;
    }
    for(int i = 1; i <= 6; i++) {
        sum += i;
        for(int j = 1; j <= 6; j++) {
            sum += j;
            for(int k = 1; k <= 6; k++) {
                sum += k;
                for(int m = 1; m <= 6; m++) {
                    sum += m;
                    ++pro4[sum];
                    sum = i + j + k;
                }
                sum = i + j;
            }
            sum = i;
        }
        sum = 0;
    }

    int cnt = 0;
    for(int i = 18; i > 3 ; i--) {
        sum = 0;
        for(int j = i - 1; j > 1; j--) {
            sum += pro4[j];
        }
        cnt += (pro3[i] * sum);
    }
    double all = pow(6.0, 7);
    double result = cnt / all;
    cout << "result: " << result << endl;
    return 0;
}
