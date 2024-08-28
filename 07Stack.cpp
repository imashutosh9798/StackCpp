#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int target) {
    // base case
    if (s.empty()) {
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    // recursive call
    solve(s, target);

    // backtrack
    s.push(topElement);
}

void insertAtBottom(stack<int> &s) {
    if (s.empty()) {
        cout << "stack is empty" << endl;
        return;
    }
    int target = s.top();
    s.pop();
    solve(s, target);
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    insertAtBottom(s);
    cout <<"Printing the element "<<endl;
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
