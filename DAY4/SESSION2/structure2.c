#include <stdio.h>
#include <stdlib.h>

struct Ticket {
    int ticket_no;
    char vehicle[30];
    float gross;
    float tare;
};

float netWeight(struct Ticket *t) {
    return t->gross - t->tare;
}

void printTicket(struct Ticket *t) {
    printf("%d %s gross %.2f tare %.2f\n",
           t->ticket_no,
           t->vehicle,
           t->gross,
           t->tare);

    printf("net %.2f\n", netWeight(t));
}

int main() {
    int n, i, heaviest = 0;
    float total = 0.0;
    printf("Enter the number of tickets: ");
    scanf("%d", &n);

    printf("Enter ticket data in this format: ticket_no vehicle gross tare\n");

    if (n <= 0 || n > 100000) {
        printf("INVALID COUNT\n");
        return 0;
    }

    struct Ticket *tickets =
        malloc(n * sizeof(struct Ticket));

    if (tickets == NULL) {
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d %29s %f %f",
              &tickets[i].ticket_no,
              tickets[i].vehicle,
              &tickets[i].gross,
              &tickets[i].tare);

        total += netWeight(&tickets[i]);

        if (netWeight(&tickets[i]) >
            netWeight(&tickets[heaviest])) {
            heaviest = i;
        }
    }

    printf("WEIGHBRIDGE DAY BOOK\n");

    for (i = 0; i < n; i++) {
        printTicket(&tickets[i]);
    }

    printf("Tickets: %d\n", n);
    printf("Total net weight (kg): %.2f\n", total);

    printf("Heaviest net load: ticket %d %s\n",
           tickets[heaviest].ticket_no,
           tickets[heaviest].vehicle);

    printf("%.2f\n", netWeight(&tickets[heaviest]));

    free(tickets);

    return 0;
}
