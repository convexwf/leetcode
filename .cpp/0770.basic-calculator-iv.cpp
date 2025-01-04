/*
 * @lc app=leetcode id=770 lang=cpp
 *
 * [770] Basic Calculator IV
 */

// @lc code=start
// 1. 逆波兰表达式+栈+哈希表
// 2024-12-31 submission
// 158/158 cases passed
// Runtime: 12 ms, faster than 27.47% of cpp online submissions.
// Memory Usage: 23.9 MB, less than 30.77% of cpp online submissions.
class Term {
public:
    int coefficient;
    vector<string> variables;

    Term(const string &token) {
        if (isdigit(token[0]) || token[0] == '-') {
            coefficient = stoi(token);
        }
        else {
            coefficient = 1;
            variables.push_back(token);
        }
    }

    Term(int coefficient, const vector<string> &variables) {
        this->coefficient = coefficient;
        this->variables = variables;
        sort(this->variables.begin(), this->variables.end());
    }

    Term operator*(const Term &rhs) const {
        int newCoefficient = coefficient * rhs.coefficient;
        vector<string> newVariables = variables;
        for (const string &variable : rhs.variables) {
            newVariables.push_back(variable);
        }
        return Term(newCoefficient, newVariables);
    }

    string toString() const {
        string result = to_string(coefficient);
        for (const string &variable : variables) {
            result += "*" + variable;
        }
        return result;
    }
};

class Expression {
private:
    vector<Term> terms;

public:
    Expression(const vector<Term> &_terms) {
        terms = _terms;

        // sort terms
        sort(terms.begin(), terms.end(), [](const Term &lhs, const Term &rhs) {
            if (lhs.variables.size() != rhs.variables.size()) {
                return lhs.variables.size() > rhs.variables.size();
            }
            for (int i = 0; i < lhs.variables.size(); i++) {
                if (lhs.variables[i] != rhs.variables[i]) {
                    return lhs.variables[i] < rhs.variables[i];
                }
            }
            return false;
        });

        // combine terms
        vector<Term> combinedTerms;
        for (int i = 0; i < terms.size(); i++) {
            if (i > 0 && terms[i].variables == terms[i - 1].variables) {
                combinedTerms.back().coefficient += terms[i].coefficient;
            }
            else {
                combinedTerms.push_back(terms[i]);
            }
        }

        // remove zero coefficient terms
        vector<Term> newTerms;
        for (const Term &term : combinedTerms) {
            if (term.coefficient != 0) {
                newTerms.push_back(term);
            }
        }

        terms = move(newTerms);
    }

    Expression operator+(const Expression &rhs) {
        vector<Term> newTerms = terms;
        for (const Term &term : rhs.terms) {
            newTerms.push_back(term);
        }
        return Expression(newTerms);
    }

    Expression operator-(const Expression &rhs) {
        vector<Term> newTerms = terms;
        for (const Term &term : rhs.terms) {
            newTerms.push_back(Term(-term.coefficient, term.variables));
        }
        return Expression(newTerms);
    }

    Expression operator*(const Expression &rhs) {
        vector<Term> newTerms;
        for (const Term &lhsTerm : terms) {
            for (const Term &rhsTerm : rhs.terms) {
                newTerms.push_back(lhsTerm * rhsTerm);
            }
        }
        return Expression(newTerms);
    }

    vector<string> toList() {
        vector<string> result;
        for (const Term &term : terms) {
            result.push_back(term.toString());
        }
        return result;
    }

    string toString() {
        string result;
        for (int i = 0; i < terms.size(); i++) {
            if (i > 0 && terms[i].coefficient > 0) {
                result += "+";
            }
            result += terms[i].toString();
        }
        return result;
    }
};

class Solution {
private:
    int priority(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    vector<string> infixToRPN(const string &s) {
        stack<char> ops;
        vector<string> output;
        string num;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i]) || isalpha(s[i])) {
                num += s[i];
            }
            else {
                if (!num.empty()) {
                    output.push_back(num);
                    num.clear();
                }
            }
            if (s[i] == '(') {
                ops.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    output.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.pop();
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                while (!ops.empty() && priority(ops.top()) >= priority(s[i])) {
                    output.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.push(s[i]);
            }
        }
        if (!num.empty()) output.push_back(num);
        while (!ops.empty()) {
            output.push_back(string(1, ops.top()));
            ops.pop();
        }
        return output;
    }

    Expression evalRPN(const vector<string> &rpn, unordered_map<string, string> &eval) {
        stack<Expression> stk;
        for (const string &token : rpn) {
            if (isdigit(token[0])) {
                stk.push(Expression({Term(token)}));
            }
            else if (isalpha(token[0])) {
                if (eval.count(token)) {
                    stk.push(Expression({Term(eval[token])}));
                }
                else {
                    stk.push(Expression({Term(token)}));
                }
            }
            else {
                Expression b = stk.top();
                stk.pop();
                Expression a = stk.top();
                stk.pop();
                if (token[0] == '+') {
                    stk.push(a + b);
                }
                if (token[0] == '-') {
                    stk.push(a - b);
                }
                if (token[0] == '*') {
                    stk.push(a * b);
                }
            }
        }
        return stk.top();
    }

public:
    vector<string> basicCalculatorIV(string expression, vector<string> &evalvars,
                                     vector<int> &evalints) {
        unordered_map<string, string> eval;
        for (int i = 0; i < evalvars.size(); i++) {
            eval[evalvars[i]] = to_string(evalints[i]);
        }
        vector<string> rpn = infixToRPN(expression);
        Expression result = evalRPN(rpn, eval);
        return result.toList();
    }
};
// @lc code=end
