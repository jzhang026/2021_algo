// https://leetcode-cn.com/problems/min-stack/
//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) —— 将元素 x 推入栈中。
//pop()—— 删除栈顶的元素。
//top()— 获取栈顶元素。
//getMin() —— 检索栈中的最小元素。
#include <utility>;
#include <stack>;
class MinStack {

private:
    std::stack<std::pair<int, int>> st;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        }
        else {
            st.push({ val, min(val, st.top().second)});
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }

    }

    int top() {
        if (st.empty()){
            return 0;
        }
        return st.top().first;
    }

    int getMin() {
        if (st.empty()) {
            return 0;
        }
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */