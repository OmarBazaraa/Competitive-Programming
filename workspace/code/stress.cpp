#include <bits/stdc++.h>

using namespace std;

// Generates random sample test case to a text file.
void generateRandomCase() {
    ofstream fout("test_case.txt");

    const int N = 1e9;
    const int L = 1e4;

    int a = rand() % N + L;
    int b = rand() % N + L;

    fout << a << ' ' << b << endl;

    fout.close();
}

int main() {
    // Compile both programs: the correct and the wrong ones.
    system("g++ -O2 -std=c++14 acc.cpp -o ac.exe");
    system("g++ -O2 -std=c++14 src.cpp -o wa.exe");

    // Set random seed
    srand(time(0));

    // Local variables
    int testCase = 0;
    string wa, ac;

    while (wa == ac) {
        // Print test case number
        cout << "Test Case #" << ++testCase << endl;

        // Generate random test case
        generateRandomCase();

        // Run the AC program to read from "test_case.txt" and output to "ac.txt"
        system("ac.exe < test_case.txt > ac.txt");
        ifstream acf("ac.txt");
        getline(acf, ac, char(EOF));
        acf.close();

        // Run the WA program to read from "test_case.txt" and output to "wa.txt"
        system("wa.exe < test_case.txt > wa.txt");
        ifstream waf("wa.txt");
        getline(waf, wa, char(EOF));
        waf.close();
    }

    return 0;
}