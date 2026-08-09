class MinStack {
public:
    stack<int> num;
    stack<int> min;

    MinStack() {
        
    }
    
    void push(int val) {
        if(min.empty() || val <= min.top()){
            min.push(val);
        }

        num.push(val);
    }
    
    void pop() {
        if(num.top() == min.top()){
            min.pop();
        }

        num.pop();
    }
    
    int top() {
        return num.top();
    }
    
    int getMin() {
        return min.top();
    }
};
