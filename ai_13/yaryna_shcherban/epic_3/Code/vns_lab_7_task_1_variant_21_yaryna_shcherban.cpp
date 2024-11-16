#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

#define pi 3.1415
#define angle_triangle_1(a, b, c) acos(-0.5 * (b * b - a * a - c * c) / (a * c)) * (180 / pi)
#define angle_triangle_2(a, b, c) acos(-(c * c - a * a - b * b) / (2.0 * a * b)) * (180 / pi)
#define angle_triangle_3(a, b, c) acos(-(a * a - b * b - c * c) / (2.0 * b * c)) * (180 / pi)

int a, b, c, n;

void angles (int n, ...) {
    if ( n < 3 ) {
        printf("Enter another one number of sides of the polygon! \n");
        return;
    }
    va_list args;
    va_start(args, n);

    int sides[n];
    for (int i = 0; i < n; i++) {
        sides[i] = va_arg(args, double);
    }
    va_end(args);

    int i = 0;
    printf("Angles for %d-gon:\n", n);
    for (int i = 0; i < n; i++) {
        float a = sides[i];
        float b = sides[(i + 1) % n];
        float c = sides[(i + 2) % n];
        printf("Angle %d: %f \n" , i + 1 , angle_triangle_1(a, b, c) );
    }

}


int main() {

    printf("Enter the number of sides of the polygon : ");
    scanf("%d", &n);

    if ( n == 3 ) {

        printf("Input a: ");
        scanf("%d", &a);
        printf("Input b: ");
        scanf("%d", &b);
        printf("Input c: ");
        scanf("%d", &c);

        if ((a+b>c)&&(a+c>b)&&(b+c>a)){

            printf("Angle_1 = %f\n", angle_triangle_1(a, b, c));
            printf("Angle_2 = %f\n", angle_triangle_2(a, b, c));
            printf("Angle_3 = %f\n", angle_triangle_3(a, b, c));

        } else {
            printf("\nInput another size of sides!\n");
        }

    } else if ( n == 9 ) {

        angles(9, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0);

    } else if ( n == 11) {

        angles(11, 3.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0, 20.0, 22.0);
    }

    return 0;
}