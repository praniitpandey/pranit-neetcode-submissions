class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string> st;
        string current;
        for (int i = 0; i < tokens.size(); i++) {
            current = tokens[i];

            if (current == "+") {
                int operand_2 = stoi(st.top());
                st.pop(); //taking out the first operand 
                int operand_1 = stoi(st.top());
                st.pop(); //taking out the second operand

                st.push(to_string(operand_1 + operand_2));
            }
            else if (current == "-") {
                int operand_2 = stoi(st.top());
                st.pop(); //taking out the first operand 
                int operand_1 = stoi(st.top());
                st.pop(); //taking out the second operand

                st.push(to_string(operand_1 - operand_2));
            }
            else if (current == "*") {
                int operand_2 = stoi(st.top());
                st.pop(); //taking out the first operand 
                int operand_1 = stoi(st.top());
                st.pop(); //taking out the second operand

                st.push(to_string(operand_1 * operand_2));
            }
            else if (current == "/") {
                int operand_2 = stoi(st.top());
                st.pop(); //taking out the first operand 
                int operand_1 = stoi(st.top());
                st.pop(); //taking out the second operand

                st.push(to_string(operand_1 / operand_2));
            }
            else {
                st.push(current);
            }
        }
        
        return stoi(st.top());
    }
};
