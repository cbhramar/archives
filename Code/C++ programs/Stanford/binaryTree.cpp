#include<simplecpp>

void binaryTree(int order, double height, double x, double y, double theta, int & n){
    if (order == 0){
        ++n;
        Text t1(x, y - 15, n);
        t1.imprint();
    }
    if (order > 0){
        double t = PI/3.5 - (5- order)*PI/25;
        Line l0(x, y, x + height*cos(theta - t), y + height*sin(theta - t));
        l0.imprint();
        binaryTree(order - 1, height*0.6, x + height*cos(theta - t), y + height*sin(theta - t), theta, n);
        Line l1(x, y, x + height*cos(theta + t), y + height*sin(theta + t));
        l1.imprint();
        binaryTree(order - 1, height*0.6, x + height*cos(theta + t), y + height*sin(theta + t), theta, n);
        ++n;
        Text t1(x, y, n);
        t1.imprint();
    }
}

main_program{
    initCanvas("Binary Tree", 1360, 700);
    int n = 0;
    binaryTree(5, 200, 680, 700, -PI/2, n);
    getClick();
}
