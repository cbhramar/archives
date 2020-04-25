#include<simplecpp>

/* Program is incomplete.
 * Strategy involves moving lower black cicle about the centre starting from top
 * Imprint the lower circle throughout so that all of right hemisphere is black
 * Now introduce white upper cicle
 * Ta-da !!
 */

main_program
{
    initCanvas("YIN-YANG", 600, 600);
    Circle outer(300, 300, 100);
    Circle upper(300, 250, 50);
    Circle lower(300, 350, 50);
    Circle u_dot(300, 250, 10);
    Circle l_dot(300, 350, 10);
    lower.setFill(true);
    lower.setColor(COLOR("black"));
    l_dot.setFill(true);
    l_dot.setColor(COLOR("white"));
    u_dot.setFill(true);
    u_dot.setColor(COLOR("black"));

    getClick();
}
