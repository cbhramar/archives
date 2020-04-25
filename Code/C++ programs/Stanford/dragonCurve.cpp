#include<simplecpp>
#include<iostream>

using namespace std;

void dragon(int n, Turtle & t);
void nograd(int n, Turtle & t);

int main(){
    initCanvas("The Dragon Curve", 1360, 700);
    Turtle t;
    t.right(180);
/*    t.forward(70);
    t.left(180);*/
    dragon(12, t);
    Turtle t2;
 /*   t2.forward(70);
    t2.left(180);*/
    dragon(12, t2);
    getClick();

    return 0;
}

void dragon(int n, Turtle & t){
    if (n == 0){
        t.forward(4);
    }
    else{
        dragon(n - 1, t);
        t.left(90);
        nograd(n - 1, t);
    }
}

void nograd(int n, Turtle & t){
    if (n == 0){
        t.forward(4);
    }
    else{
        dragon(n - 1, t);
        t.right(90);
        nograd(n - 1, t);
    }
}
