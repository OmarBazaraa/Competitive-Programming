#include <bits/stdc++.h>

using namespace std;

// Generates random sample test case to a text file.
void generateRandomCase() {
    ofstream fout("input.txt");

    int n = 1 + rand() % 50;
    int k = 1 + rand() % n;
    fout << n << ' ' << k << endl;

    fout.close();
}

int main() {
    // Compile both programs: the correct and the wrong ones.
    system("g++ -O2 -std=c++14 AC.cpp -o ac.exe");
    system("g++ -O2 -std=c++14 WA.cpp -o wa.exe");

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

        // Run the WA program to read from "input.txt" and output to "wa.txt"
        system("wa < input.txt > wa.txt");
        ifstream waf("wa.txt");
        getline(waf, wa, char(EOF));
        waf.close();

        // Run the AC program to read from "input.txt" and output to "ac.txt"
        system("ac < input.txt > ac.txt");
        ifstream acf("ac.txt");
        getline(acf, ac, char(EOF));
        acf.close();
    }

    return 0;
}