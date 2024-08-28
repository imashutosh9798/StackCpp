#include<iostream>
using namespace std;
class Stack {
    int* arr;
    int size ;
    int top;

    Stack(int size){
        arr =new int [size];
        this ->size=size;
        this ->top=-1;


    }

    void push(int data){
        top++;
        arr[top]=data;
    }
}
int main(){
   
    

}