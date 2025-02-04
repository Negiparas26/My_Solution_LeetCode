
//     using two pointer

#include <iostream>
#include <algorithm>
using namespace std;

void reverseString(string &s) {
    int j = s.length() - 1;  // Start j from last index
    for (int i = 0; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

int getLength(char* arr) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    string s;
    getline(cin, s);  // Read input with spaces
    
    reverseString(s);  // Call corrected function
    cout << "Reversed string: " << s << endl;
    
    // Corrected loop to print characters
    for (int i = 0; i < s.length(); i++) {
        cout << s[i] << " : ";
    }

    return 0;
}




// using reverse inbuilt func

#include <iostream>
#include <algorithm>  // for reverse()
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str); // Read input with spaces
    reverse(str.begin(), str.end()); // In-built function
    cout << "Reversed string: " << str << endl;
    return 0;
}


//using recursion 



#include <iostream>
using namespace std;

void reverseRecursive(string &str, int left, int right) {
    if (left >= right) return;  // Base case
    swap(str[left], str[right]); // Swap first and last
    reverseRecursive(str, left + 1, right - 1); // Recursive call
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    reverseRecursive(str, 0, str.length() - 1);
    cout << "Reversed string: " << str << endl;
    return 0;
}
