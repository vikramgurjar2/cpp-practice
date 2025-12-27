#include <iostream>
#include <chrono>
#include <string>
using namespace std;

int main()
{
    using namespace std;
    using namespace std::chrono;

    auto start = high_resolution_clock::now();

    string output;
    output.reserve(800000); // preallocate space

    for (int i = 1; i <= 10000000; ++i)
    {
        output += to_string(i);
        output += '\n';
    }

    // Actually print (optional, comment out if just testing string build)

    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;

    cout << "Execution time: " << duration.count() << " seconds." << endl;

    return 0;
}
