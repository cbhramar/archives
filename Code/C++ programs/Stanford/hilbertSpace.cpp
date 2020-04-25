#include <simplecpp>

void hilbert(double x, double y, double xi, double xj, double yi, double yj, int n){
    if (n == 0) {
        Circle c0(x + (xi + yi)/2, y + (xj + yj)/2, 3);
        c0.imprint();
        Line l0(x, y, x + (xi + yi)/2, y + (xj + yj)/2);
        l0.imprint();
    }
    else {
        hilbert(x,           y,           yi/2, yj/2,  xi/2,  xj/2, n-1);
        hilbert(x+xi/2,      y+xj/2 ,     xi/2, xj/2,  yi/2,  yj/2, n-1);
        hilbert(x+xi/2+yi/2, y+xj/2+yj/2, xi/2, xj/2,  yi/2,  yj/2, n-1);
        hilbert(x+xi/2+yi,   y+xj/2+yj,  -yi/2,-yj/2, -xi/2, -xj/2, n-1);
    }
}

main_program{
    initCanvas("The Hilbert Curve", 600, 600);
    // Turtle t;
    int order;
    cout << "What order would you prefer?" << endl;
    cin >> order;
    hilbert(100, 100, 400, 0, 0, 400, order);

    getClick();
}
