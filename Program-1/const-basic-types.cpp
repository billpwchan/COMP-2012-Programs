#include <iostream>     /* File: const-basic-types.cpp */
#include <cstdlib>      // Need the constant RAND_MAX
using namespace std;

int main()  // To generate 5 random integers between 0 and 100
{
    const int N = 5;         // Number of integers to generate
    const int MAX_NUM = 100; // Max integer

    // Seed the random number generator by current time
    srand(time(0));

    for (int j = 0; j < N; ++j)
    {
        int random_num = 0.5
            + static_cast<double>(rand())/RAND_MAX*MAX_NUM;
        cout << random_num << endl;
    }

    return 0;
}
