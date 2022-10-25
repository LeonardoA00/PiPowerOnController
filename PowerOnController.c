#include <pigpio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI_INPUT 0
#define PI_OUTPUT 1

#define PWR_PIN 27

int main(int argc, char* argv[])
{
    if(gpioInitialise() < 0)
    {
        printf("Error initializing gpio\n");
        return -1;
    }

    if (argc != 2) {
        printf("Request a button press time\n");
        return 1;
    }
    float press_time = atof(argv[1]);
    struct timespec * sleep_struct = (struct timespec *)malloc(sizeof(struct timespec));

    if (press_time < 0 || press_time > 15) {
        printf("Bad button press time\n");
        return 1;
    }

    sleep_struct->tv_sec = (int)press_time;
    sleep_struct->tv_nsec = (int)((press_time - sleep_struct->tv_sec) * 1000000000);

    gpioSetMode(PWR_PIN, PI_OUTPUT);

    gpioWrite(PWR_PIN, 1);
    printf("PWR is HIGH\n");
    nanosleep(sleep_struct, sleep_struct);
    gpioWrite(PWR_PIN, 0);
    printf("PWR is LOW\n");

    printf("Succesfully executed PWRON\n");

    free(sleep_struct);
    return 0;
}