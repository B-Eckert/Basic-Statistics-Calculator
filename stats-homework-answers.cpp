// stats-homework-answers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <stack>
#include <cmath>;
using namespace std;

int main()
{
    cout << "How to use this program:\nThis program is made to coincide with simple data calculations such as the mean, median, variance and standard deviation of a set of numbers." <<
        " In order to use this program, you may type either single numbers, or NxM to repeat N M times. You may type in -1 to end the procedure." << endl;
    stack<double> numbers;
    while (1) {
        string x;
        double y;
        int repeats = 1;
        getline(cin, x);
        int pos;
        if ((pos = x.find('x')) != string::npos) {
            y = stod(x.substr(0, pos));
            repeats = stoi(x.substr(pos+1));

        }
        else {
            y = stod(x);
        }
        if (y == -1)
            break;
        cout << "Adding " << y << " this many times: " << repeats << endl;
        while (repeats != 0) {
            numbers.push(y);
            repeats--;
        }
    }
    double size = numbers.size();
    double median = numbers.size() * 0.5;
    bool isMidValue = true;
    if ((median - floor(median)) != 0.0) {
        isMidValue = false;
    }
    median = ceil(median);
    double medianValue = -1;
    double mean = 0;
    double variance = 0;
    double varianceL = 0;
    double varianceR = 0;
    double std_dev = 0;
    int counter = size;
    double previous = -1.0;
    while (!numbers.empty()) {
        counter--;
        double n = numbers.top();
        if (counter == median) {
            if (isMidValue)
                previous = n;
            else {
                medianValue = n;
            }
        }
        else if (isMidValue && previous != -1.0 && medianValue == -1.0) {
            medianValue = (previous + n) / 2.0;
        }
        varianceL += pow(n, 2.0);
        mean += n;
        numbers.pop();
    }
    varianceR = pow(mean, 2.0) / size;
    variance = (varianceL - varianceR) / (size - 1.0);
    std_dev = sqrt(variance);
    mean /= size;

    cout << "Mean: " << mean << endl;
    cout << "Median: " << medianValue << endl;
    cout << "Variance: " << variance << endl;
    cout << "Standard Dev: " << std_dev << endl;
    cout << "Sample Size: " << size << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
