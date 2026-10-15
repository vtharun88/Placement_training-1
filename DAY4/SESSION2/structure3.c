#include <stdio.h>

union Value {
    float temperature;
    char door_state;
    long pulses;
};

struct Reading {
    int sensor_id;
    char kind;
    union Value value;
};

struct ReadingAllFields {
    int sensor_id;
    char kind;
    float temperature;
    char door_state;
    long pulses;
};

int main() {
    struct Reading readings[1000];
    int n, i;

    printf("Enter the number of sensor readings: ");
    scanf("%d", &n);

    printf("Enter data in this format: sensor_id kind value\n");
    printf("kind: T for temperature, D for door, P for pulses\n");

    if (n <= 0 || n > 1000) {
        printf("INVALID COUNT\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        scanf("%d %c", &readings[i].sensor_id,
              &readings[i].kind);

        switch (readings[i].kind) {
            case 'T':
                scanf("%f", &readings[i].value.temperature);
                break;

            case 'D':
                scanf(" %c", &readings[i].value.door_state);
                break;

            case 'P':
                scanf("%ld", &readings[i].value.pulses);
                break;

            default:
                printf("INVALID KIND\n");
                return 0;
        }
    }

    printf("SENSOR REPORT\n");

    for (i = 0; i < n; i++) {
        printf("Sensor %d ",
               readings[i].sensor_id);

        switch (readings[i].kind) {
            case 'T':
                printf("temperature %.2f C\n",
                       readings[i].value.temperature);
                break;

            case 'D':
                if (readings[i].value.door_state == 'O') {
                    printf("door OPEN\n");
                } else {
                    printf("door CLOSED\n");
                }
                break;

            case 'P':
                printf("pulses %ld\n",
                       readings[i].value.pulses);
                break;
        }
    }

    printf("sizeof(union Value): %zu\n",
           sizeof(union Value));

    printf("sizeof(Reading) with union: %zu\n",
           sizeof(struct Reading));

    printf("sizeof(Reading) with all fields: %zu\n",
           sizeof(struct ReadingAllFields));

    printf("Bytes saved per record: %zu\n",
           sizeof(struct ReadingAllFields) -
           sizeof(struct Reading));

    return 0;
}