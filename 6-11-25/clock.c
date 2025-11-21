#include <stdio.h>

int main() {
    int hour, minute;
    float hour_angle, minute_angle, angle;

    printf("Enter hour (1-12): ");
    scanf("%d", &hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &minute);

    hour_angle = (hour * 30) + (minute * 0.5);
    minute_angle = minute * 6;

    angle = hour_angle - minute_angle;

    if (angle < 0)
        angle = -angle;

    if (angle > 180)
        angle = 360 - angle;

    printf("Angle between clock hands = %.2f degrees", angle);

    return 0;
}
