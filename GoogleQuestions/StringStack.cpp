#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>

int opResult(int first, int second, std::string op) {
    if (op == "add") return first + second;
    if (op == "sub") return first - second;
    if (op == "mul") return first * second;
    if (op == "div") return first / second;
    if (op == "pow") return static_cast<int>(pow(first, second));
    return 0;
}

std::string evaluate(const std::string& s) {
    std::stack<std::string> st;
    std::string token;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(' || s[i] == ',' || s[i] == ')') {
            if (!token.empty()) {
                st.push(token);
                token.clear();
            }
            if (s[i] == ')') {
                int second = std::stoi(st.top()); st.pop(); // Operand 2
                st.pop(); // Pop ','
                int first = std::stoi(st.top()); st.pop(); // Operand 1
                st.pop(); // Pop '('
                std::string op = st.top(); st.pop(); // Operator

                int result = opResult(first, second, op);
                st.push(std::to_string(result));
            } else {
                st.push(std::string(1, s[i]));
            }
        } else {
            token += s[i];
        }
    }

    if (!token.empty()) {
        st.push(token);
    }

    return st.top();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::cin >> s;
    std::cout << evaluate(s) << std::endl;
    return 0;
}