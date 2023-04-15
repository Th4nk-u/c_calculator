#include <iostream>
#include <string>

using namespace std;

class Calculator {
public:
    Calculator(const string& input) : input_(input), pos_(0) {}

    // Evaluate the arithmetic expression and return the result.
    double evaluate() {
        // Parse the expression starting at the top level (expression).
        double result = parse_expression();

        // Check that we have consumed the entire input string.
        if (pos_ < input_.size()) {
            throw runtime_error("Invalid expression");
        }

        return result;
    }

private:
    // Parse an expression, which can be a sum or difference of terms.
    double parse_expression() {
        // Parse the first term.
        double left = parse_term();

        // Repeat while there are more terms to add or subtract.
        while (pos_ < input_.size() && (input_[pos_] == '+' || input_[pos_] == '-')) {
            // Get the operator.
            char op = input_[pos_];
            pos_++;

            // Parse the next term.
            double right = parse_term();

            // Apply the operator to the current result.
            if (op == '+') {
                left += right;
            }
            else {
                left -= right;
            }
        }

        // Return the final result.
        return left;
    }

    // Parse a term, which can be a product or quotient of factors.
    double parse_term() {
        // Parse the first factor.
        double left = parse_factor();

        // Repeat while there are more factors to multiply or divide.
        while (pos_ < input_.size() && (input_[pos_] == '*' || input_[pos_] == '/')) {
            // Get the operator.
            char op = input_[pos_];
            pos_++;

            // Parse the next factor.
            double right = parse_factor();

            // Apply the operator to the current result.
            if (op == '*') {
                left *= right;
            }
            else {
                left /= right;
            }
        }

        // Return the final result.
        return left;
    }

    // Parse a factor, which can be a number or a sub-expression in parentheses.
    double parse_factor() {
        if (pos_ < input_.size() && input_[pos_] == '(') {
            // If the factor starts with an opening parenthesis, parse the sub-expression inside the parentheses.
            pos_++;
            double result = parse_expression();
            if (pos_ >= input_.size() || input_[pos_] != ')') {
                throw runtime_error("Mismatched parentheses");
            }
            pos_++;

            // Return the result of the sub-expression.
            return result;
        }
        else {
            // Otherwise, the factor is a number, so parse it.
            return parse_number();
        }
    }

    // Parse a floating-point number.
    double parse_number() {
        // Find the start of the number.
        size_t start = pos_;
        while (pos_ < input_.size() && isdigit(input_[pos_])) {
            pos_++;
        }

        // If there is a decimal point, parse the fractional part.
        if (pos_ < input_.size() && input_[pos_] == '.') {
            pos_++;
            while (pos_ < input_.size() && isdigit(input_[pos_])) {
                pos_++;
            }
        }

        // Extract the number as a substring and convert it to a double.
        return stod(input_.substr(start, pos_ - start));
    }

    string input_;
    size_t pos_;
};

int main() {
    string input;
    cout << "Enter an arithmetic expression: ";
    getline(cin, input);

    Calculator calc(input);
    try {
        double result = calc.evaluate();
        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
