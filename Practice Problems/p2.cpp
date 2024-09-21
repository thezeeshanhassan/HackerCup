#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

double calculateIncreaseProbablity(int N, int P)
{
    double pointProbablity = P / 100.0;
    double initialSuccessProbablityForOneLess = pow(pointProbablity, N - 1);
    double newProbablity = pow(initialSuccessProbablityForOneLess, 1.0 / N);
    newProbablity *= 100;
    return newProbablity - P;
}

int main()
{
    int T;
    cin >> T; // Number of test cases

    for (int testCase{1}; testCase <= T; testCase += 1)
    {
        int N;
        double P;
        cin >> N >> P;

        double increase = calculateIncreaseProbablity(N, P);

        // cout << fixed << setprecision(15);
        // cout << "Case #" << testCase << ": " << increase << endl;
        ofstream output("output.txt", ios::app);
        output << fixed << setprecision(15);
        output << "Case #" << testCase << ": " << increase << endl;
    }

    return 0;
}