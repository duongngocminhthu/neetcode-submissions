class MinStack {
public:

    stack<int> st;
    stack<int> min;

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){min.push(val);}
        else{
            if(val < min.top()) min.push(val);
            else{
                int temp = min.top();
                min.push(temp);
            }
        }
        
        st.push(val);        
    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();     
    }
    
    int getMin() {
        return min.top();
    }
};
