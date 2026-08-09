class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                int a = num.top();
                num.pop();

                int b = num.top();
                num.pop();

                int sum = a + b;

                num.push(sum);
            }

            else if(tokens[i] == "-"){
                int a = num.top();
                num.pop();

                int b = num.top();
                num.pop();

                int diff = b - a;

                num.push(diff);
            }

            else if(tokens[i] == "*"){
                int a = num.top();
                num.pop();

                int b = num.top();
                num.pop();

                int product = a * b;

                num.push(product);
            }

            else if(tokens[i] == "/"){
                int a = num.top();
                num.pop();

                int b = num.top();
                num.pop();

                int quotient = b / a;

                num.push(quotient);
            }

            else num.push(stoi(tokens[i]));
        }

        return num.top();
    }
};
