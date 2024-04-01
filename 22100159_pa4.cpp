#include <iostream>
#include <string>
using namespace std;
#define YES 1
#define NO 0

bool check(string s, int n1, int n2){
    if(n1 >= n2){
        return true;
    }
    if(s[n1] != s[n2]){
        return false;
    }
    else{
        return check(s, n1+1, n2-1);
    }
}

int main(){
    string input;
    int len;

    cout << "Input a string : ";
    cin >> input;
    len = input.size();

    if(check(input, 0, len-1) == YES){
        cout << "Yes, it is a palindrome.\n";
    }
    else{
        cout << "No, it is not a palindrome.\n";
    }

    return 0;

}

