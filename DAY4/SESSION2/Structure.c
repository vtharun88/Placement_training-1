
#include <stdio.h>

struct Address {
    char village[50];
    int pincode;
};

struct Member {
    int id;
    char name[50];
    float share_capital;
    struct Address address;
};

int main() {
    struct Member members[200];
    int n, i;
    float total = 0.0, highestCapital = 0.0;
    printf("Enter the number of members: ");
    scanf("%d", &n);

    if (n <= 0 || n > 200) {
        printf("INVALID COUNT");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter details for member %d:\n", i + 1);
        printf("ID, Name, Share_Capital, Village, Pincode: ");
        scanf("%d %49s %f %49s %d",
              &members[i].id,
              members[i].name,
              &members[i].share_capital,
              members[i].address.village,
              &members[i].address.pincode);

        total += members[i].share_capital;

        if (i == 0 || members[i].share_capital > highestCapital) {
            highestCapital = members[i].share_capital;
        }
    }

    printf("MEMBER LEDGER\n");

    for (i = 0; i < n; i++) {
        printf("%d %s %s %d %.2f\n",
               members[i].id,
               members[i].name,
               members[i].address.village,
               members[i].address.pincode,
               members[i].share_capital);
    }

    printf("Total share capital (Rs): %.2f\n", total);

    printf("Highest holder(s):\n");
    for (i = 0; i < n; i++) {
        if (members[i].share_capital == highestCapital) {
            printf("%d %s %s %d %.2f\n",
                   members[i].id,
                   members[i].name,
                   members[i].address.village,
                   members[i].address.pincode,
                   members[i].share_capital);
        }
    }

    return 0;
}
