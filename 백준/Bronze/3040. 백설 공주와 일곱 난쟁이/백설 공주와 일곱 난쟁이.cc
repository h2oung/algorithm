#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> dwarfs(9);  
    for (int i = 0; i < 9; ++i) {
        cin >> dwarfs[i];
    }

    for (int a = 0; a < 9; ++a) {
        for (int b = a + 1; b < 9; ++b) {
            for (int c = b + 1; c < 9; ++c) {
                for (int d = c + 1; d < 9; ++d) {
                    for (int e = d + 1; e < 9; ++e) {
                        for (int f = e + 1; f < 9; ++f) {
                            for (int g = f + 1; g < 9; ++g) {
                                int sum = dwarfs[a] + dwarfs[b] + dwarfs[c] +
                                          dwarfs[d] + dwarfs[e] + dwarfs[f] + dwarfs[g];
                                if (sum == 100) {
                                    cout << dwarfs[a] << "\n" << dwarfs[b] << "\n" << dwarfs[c] << "\n"
                                         << dwarfs[d] << "\n" << dwarfs[e] << "\n" << dwarfs[f] << "\n" << dwarfs[g] << "\n";
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}