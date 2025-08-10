#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    ifstream expected("output.txt");

    if (!input.is_open() || !expected.is_open()) {
        cerr << "Failed to open input or output file.\n";
        return 1;
    }

    int T;
    input >> T;

    for (int t = 0; t < T; ++t) {
        long long A, B;
        input >> A >> B;

        ofstream temp_input("temp_input.txt");
        temp_input << A << ' ' << B << '\n';
        temp_input.close();

        int exit_code = system("./solution < temp_input.txt > user_output.txt");
        if (exit_code != 0) {
            cerr << "Execution failed for testcase " << t + 1 << '\n';
            return 1;
        }

        ifstream user_output("user_output.txt");
        long long user_ans, expected_ans;

        if (!(user_output >> user_ans)) {
            cerr << "Failed to read user output for testcase " << t + 1 << '\n';
            return 1;
        }

        if (!(expected >> expected_ans)) {
            cerr << "Failed to read expected output for testcase " << t + 1 << '\n';
            return 1;
        }

        if (user_ans != expected_ans) {
            cout << "Testcase " << t + 1 << " FAILED\n";
            cout << "A = " << A << ", B = " << B << '\n';
            cout << "Expected: " << expected_ans << ", Got: " << user_ans << '\n';
            return 1;
        }
    }

    cout << "All testcases PASSED\n";
    return 0;
}
