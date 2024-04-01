#include <iostream>
#include <string>
using namespace std;

string reverse(string str){
    char a;
    a=str[str.length()-1];
    if(str.length() <= 1){
        return str;
    }
    str.erase(str.length()-1, 1);
    return a+reverse(str);
    a--;

}
 
int main(){
    string  input, r_input;
    cout << "Input a string : ";
    cin >> input; 
    r_input = reverse(input); 
    cout << r_input << endl;
    return 0;
}

