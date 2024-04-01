#include <iostream>
#include <string>
using namespace std;
#define SIZE 100
#define EOS '$'

class op_stack{
    int top;
    char s[SIZE];
    public:
        op_stack();
        void push(char x);
        char pop();
        bool empty();
        char top_element();
};

op_stack::op_stack(){
    top = 0;
}

void op_stack::push(char x){
    s[top] = x;
    top++;
}

char op_stack::pop(){
    top--;
    return(s[top]);
}

bool op_stack::empty(){
    return(top == 0);
}

char op_stack::top_element(){
    return(s[top-1]);
}

bool is_operand (char ch){
    if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z'){
        return true;
    }
    else{
        return false;
    }
}

int get_precedence(char op){
    if ((op =='$') || (op == '(')){
        return(0);
    }
    if ((op =='+') || (op == '-')){
        return(1);
    }
    if ((op =='*') || (op == '/' ) || (op == '%')){
        return(2);
    }
    else{
        return(-1);
    }
}

int main(){
    string input, output;
    op_stack stack1;
    cout << "Input an infix expression to convert : ";
    cin >> input;

    input += EOS; // 인풋 끝에 eos 추가
    stack1.push(EOS);

    for(int i = 0; i<input.size(); i++){
        if(is_operand(input[i])){ 
            output += input[i]; //인풋이 문자이면 아웃풋에 집어넣기
        }
        else if(input[i] == '('){
            stack1.push(input[i]); //인풋이 '('이면 스택에 집어넣기
        }
        else if(input[i] == ')'){
            while(stack1.top_element() != '('){
                output += stack1.pop(); //인풋이 ')'이면 '('이 나올 때까지 꺼내서 출력하기
            }
            stack1.pop();
        }
        else{
            while(get_precedence(stack1.top_element()) >= get_precedence(input[i])){
                output += stack1.pop(); //우선순위가 낮아질 때까지 꺼내서 출력하기
            }
            stack1.push(input[i]);
        }
    }

    if(stack1.empty() == false){
        output.erase(output.size()-1, 1);
    }

    cout << output << "\n";
}