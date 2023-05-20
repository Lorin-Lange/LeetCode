////////////////////////////////////////////////////
//                    LeetCode                    //
//                 155. Min Stack                 //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
public:
    MinStack() { }
    
    void push(int val) {
        my_stack.push(val);
        if(minimum.empty()) {
            minimum.push(val);
        } else {
            minimum.push(min(minimum.top(), val));
        }
    }
    
    void pop() {
        my_stack.pop();
        minimum.pop();
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        return minimum.top();
    }

private:
    stack<int> my_stack;
    stack<int> minimum;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


 int main() {
    MinStack* obj = new MinStack();
    obj->push(4);
    obj->push(4);
    obj->push(5);
    obj->push(42);
    obj->push(-3);
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->push(-3);
    obj->pop();
    
    cout << obj->getMin() << endl;
    return EXIT_SUCCESS;
 }