#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

bool canCrossInSeconds(long long N, long long K, vector<long long> &seconds)
{
    sort(seconds.begin(), seconds.end());
    long long minSeconds{seconds[0]};
    long long totalSeconds{};
    if (N > 2)
    {
        totalSeconds = (minSeconds * (((N - 2) * 2) + 1));
    }
    if (N <= 2)
    {
        totalSeconds = minSeconds;
    }
    if (totalSeconds <= K)
    {
        return true;
    }
    return false;
}

int main()
{
    long long T;
    cin >> T; // Total TestCases

    for (long long testCase{1}; testCase <= T; testCase += 1)
    {
        long long N, K;
        cin >> N; // Total Persons
        cin >> K; // Total Seconds
        vector<long long> seconds(N);
        for (long long i{}; i < N; i += 1)
        {
            cin >> seconds[i];
        }
        ofstream output("output.txt", ios::app);
        if (canCrossInSeconds(N, K, seconds))
        {
            // cout << "Case #" << testCase << ": YES\n";
            output << "Case #" << testCase << ": YES\n";
        }
        else
        {
            // cout << "Case #" << testCase << ": NO\n";
            output << "Case #" << testCase << ": NO\n";
        }
    }

    return 0;
}