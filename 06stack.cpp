#include<iostream>
#include<stack>
using namespace std;


bool checkRedundant(string *str) {
    stack<char> st;
    for (int i = 0; i < str->length(); i++) {
        char ch = (*str)[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '/') {
            st.push(ch);
        } else if (ch == ')') {
            int operatorCount = 0;
            while (!st.empty() && st.top() != '(') {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                    operatorCount++;
                }
                st.pop();
            }
            st.pop();
            if (operatorCount == 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string str = "((a+b)*(c+d))";
    // string str ="{(28*2)[2(2*1)]}";
    bool ans = checkRedundant(&str);
    if (ans == true) {
        cout << "Redundant Bracket Present" << endl;
    } else {
        cout << "Redundant Bracket Not Present" << endl;
    }
    return 0;
}

























































// #include<iostream>
// #include<stack>
// using namespace std;
// void checkRedundant(string * str){
//     stack<char> st;
//     for (int i=0;i<str->length();i++){
//         char ch = str [i];
//     if(ch=='(' ||ch=='+' ||ch=='-'||ch=='/'){
//         st.push(ch);
//     }
//     else if (ch==')'){
//         int operatorCount=0;
//         while(!st.empty() && st.top()!='('){
//             chat temp= st.top();
//             if(temp=='+'||temp=='-'||temp=='*'||temp=='/'){
//                     operatorCount++;

//             }
//             st.pop();

//         }
//                     st.pop();
//             if(operatorCount==0){
//                 return true ;


//             }

//     }

//     }
//     return false;
// }

// int main(){

// string str= "((a+b)*(a+d))";
//   bool ans == checkRedundant(str);
//   if(ans==true){
//     cout<<"Redundant Bracket Present "<<endl;
//   }
//     else{
//         cout<<"Redundant Bracket Not Present "<<endl;
//     }
// }