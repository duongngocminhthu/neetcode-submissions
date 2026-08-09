class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        int x = 0 , y = 0;

        for(int i = 0; i < tokens.size(); i++){
            if (tokens[i] != "+" && tokens[i] != "-" &&
                tokens[i] != "*" && tokens[i] != "/"){

                int number = stoi(tokens[i]);
                num.push(number);

            } else {
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();

                if(tokens[i] == "+"){
                    int sum = x + y;
                    num.push(sum);
                }

                if(tokens[i] == "-"){
                    int diff = x - y;
                    num.push(diff);
                }

                if(tokens[i] == "/"){
                    int divide = x / y;
                    num.push(divide);
                }

                if(tokens[i] == "*"){
                    int product = x * y;
                    num.push(product);
                }
            }
        }

        return num.top();
    }
};
