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
    string input, output, test;
    br_stack stack1;
    cout << "Input : ";
    cin >> input;

    input += EOS; // 인풋 끝에 eos 추가
    stack1.push(EOS);

    for(int i = 0; i<input.size(); i++){
        if((input[i] == '(') || (input[i] == '{') || (input[i] == '[')){
            stack1.push(input[i]); //인풋이 여는 괄호이면 스택에 집어넣기
        }
        else if(input[i] == ')' || input[i] == '}' || input[i] == ']'){
            
            
        }
    }   

    if(stack1.empty() == 1 || stack1.top_element() == '$'){
        cout << "It’s a normal expression";
    }
}