#include <iostream>
using namespace std;

int main() {
    long long n, p = 0, sum = 0, x;
    cin >> n;

    while (n--) {
        cin >> x;
        if (x == -1) {
            if (p > 0) 
                p--;  // A police officer handles the crime
            else 
                sum++; // No police officer available, crime goes unhandled
        } else {
            p += x; // Recruit police officers
        }
    }
    
    cout << sum << endl;
    return 0;
}
