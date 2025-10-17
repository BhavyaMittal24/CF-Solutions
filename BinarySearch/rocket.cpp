#include <iostream>
#include <vector>

int ask(long long y) {
    int resp;
    std::cout << y << std::endl;
    std::cin >> resp;
    if (resp == -2) exit(0); // Add an exit condition for unexpected errors
    return resp;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n;
    std::cin >> m >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        // This part of the logic may be incorrect depending on the problem
        int verdict = ask(1);
        if (verdict == 0) return 0;
        if (verdict == 1) p[i] = 1;
        else p[i] = 0;
    }

    long long low = 1;
    long long high = m;
    int i = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        int verdict = ask(mid);

        // Check for correct answer
        if (verdict == 0) {
            break;
        }

        // Determine the correction factor from the p array
        int correct = (p[i % n] == 0) ? -1 : 1;

        // Apply the correction factor to the verdict
        verdict = verdict * correct;

        // Update binary search bounds
        if (verdict == 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }

        i++;
    }

    return 0;
}