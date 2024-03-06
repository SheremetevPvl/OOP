#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
    return 0;
}