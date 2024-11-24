#include <stdio.h>
#include <string.h>
struct TravelPackage {
    char packageName[100];
    char destination[100];
    int duration;     // in days
    float cost;       // per person
    int seatsAvailable;
};
void displayPackages(const struct TravelPackage packages[], int packageCount);
void bookPackage(struct TravelPackage packages[], int packageCount);

int main() {
    struct TravelPackage packages[5] = {
        {"Beach Bliss", "Maldives", 7, 1500.0, 10},
        {"Mountain Adventure", "Himalayas", 5, 800.0, 15},
        {"City Escape", "New York", 4, 1200.0, 8},
        {"Desert Safari", "Dubai", 6, 1000.0, 12},
        {"Cultural Tour", "Rome", 10, 2000.0, 5}
    };

    int packageCount = 5;
    int choice;

    do {
        printf("\n--- Travel Package Menu ---\n");
        printf("1. Display available packages\n");
        printf("2. Book a travel package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages(packages, packageCount);
                break;
            case 2:
                bookPackage(packages, packageCount);
                break;
            case 3:
                printf("Exiting the program. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
void displayPackages(const struct TravelPackage packages[], int packageCount) {
    printf("\n--- Available Travel Packages ---\n");\
    int i;
    for (i = 0; i < packageCount; i++) {
        printf("\nPackage %d:\n", i + 1);
        printf("Name: %s\n", packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f per person\n", packages[i].cost);
        printf("Seats Available: %d\n", packages[i].seatsAvailable);
    }
}
void bookPackage(struct TravelPackage packages[], int packageCount) {
    int packageNumber, seatsToBook;

    printf("\nEnter the package number to book: ");
    scanf("%d", &packageNumber);

    if (packageNumber < 1 || packageNumber > packageCount) {
        printf("Invalid package number. Please try again.\n");
        return;
    }

    struct TravelPackage *selectedPackage = &packages[packageNumber - 1];

    if (selectedPackage->seatsAvailable == 0) {
        printf("Sorry, no seats are available for this package.\n");
        return;
    }

    printf("Enter the number of seats to book: ");
    scanf("%d", &seatsToBook);

    if (seatsToBook > selectedPackage->seatsAvailable) {
        printf("Sorry, only %d seats are available.\n", selectedPackage->seatsAvailable);
        return;
    }

    selectedPackage->seatsAvailable -= seatsToBook;
    printf("Successfully booked %d seat(s) for the '%s' package.\n", seatsToBook, selectedPackage->packageName);
}


