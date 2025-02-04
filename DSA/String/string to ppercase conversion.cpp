#include <iostream>
using namespace std;

void toUppercase(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') { // Check if it's a lowercase letter
            s[i] = s[i] - 32; // Convert to uppercase manually
        }
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s); // Read input including spaces

    toUppercase(s); // Call function to convert to uppercase

    cout << "Uppercase: " << s << endl;
    return 0;
}
