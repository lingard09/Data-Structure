#include <iostream>
#include <string>
using namespace std;
#define SIZE 100
#define EOS '$'

class br_stack{
    int top;
    char s[SIZE];
    public:
        br_stack(){
            top = 0;
        }
        void push(char x){
            s[top] = x;
            top++;
        }
        char pop(){
            top--;
            return(s[top]);
        }
        bool empty(){
            return(top == 0);
        }
        char top_element(){
            return(s[top-1]);
        }
};

int main(){
    string input, output;
    br_stack stack1;
    cout << "Input : ";
    cin >> input;

    input += EOS;
    stack1.push(EOS);

    for(int i = 0; i<input.size(); i++){
        if((input[i] == '(') || (input[i] == '{') || (input[i] == '[')){
            stack1.push(input[i]);
        }
        else if(input[i] == ')' || input[i] == '}' || input[i] == ']'){
            if(stack1.empty() == 1 || stack1.top_element() == '$'){
                output += "Error: An extra parenthesis '";
                output += input[i];
                output += "' is found.";
            }
            else{
                if(stack1.top_element() == '('){
                    if(input[i] == ')'){
                        stack1.pop();
                    }
                    else{
                        output += "Error: mis-matched parenthesis, ')' is expected.";
                        break;
                    }
                }
                else if(stack1.top_element() == '{'){
                    if(input[i] == '}'){
                        stack1.pop();
                    }
                    else{
                        output += "Error: mis-matched parenthesis, '}' is expected.";
                        break;
                    }
                }
                else if(stack1.top_element() == '['){
                    if(input[i] == ']'){
                        stack1.pop();
                    }
                    else{
                        output += "Error: mis-matched parenthesis, ']' is expected.";
                        break;
                    }
                }
            }
        }
    }   

    if(output == ""){
        if(stack1.empty() == 1 || stack1.top_element() == '$'){
            cout << "It’s a normal expression\n";
        }
    }
    else{
        cout << output << endl;
    }
}