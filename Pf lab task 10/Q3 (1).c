#include <stdio.h>
#include <string.h>

struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    int mileage;
};
void addCar(struct Car cars[], int *carCount);
void displayCars(const struct Car cars[], int carCount);
void searchCar(const struct Car cars[], int carCount);

int main() {
    struct Car cars[100]; 
    int carCount = 0;     
	    int choice;
	do {
        printf("\n--- Car Dealership Menu ---\n");
        printf("1. Add a new car\n");
        printf("2. Display all cars\n");
        printf("3. Search for a car by make or model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &carCount);
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCar(cars, carCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
void addCar(struct Car cars[], int *carCount) {
    printf("\nEnter details of the new car:\n");
    printf("Make: ");
    scanf("%s", cars[*carCount].make);
    printf("Model: ");
    scanf("%s", cars[*carCount].model);
    printf("Year: ");
    scanf("%d", &cars[*carCount].year);
    printf("Price: ");
    scanf("%f", &cars[*carCount].price);
    printf("Mileage: ");
    scanf("%d", &cars[*carCount].mileage);

    (*carCount)++;
    printf("Car added successfully!\n");
}
void displayCars(const struct Car cars[], int carCount) {
    if (carCount == 0) {
        printf("\nNo cars available in the dealership.\n");
        return;
    }

    printf("\nList of available cars:\n");
    int i;
    for (i = 0; i < carCount; i++) {
        printf("\nCar %d:\n", i + 1);
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: $%.2f\n", cars[i].price);
        printf("Mileage: %d miles\n", cars[i].mileage);
    }
}
void searchCar(const struct Car cars[], int carCount) {
    if (carCount == 0) {
        printf("\nNo cars available to search.\n");
        return;
    }

    char query[50];
    printf("\nEnter the make or model to search for: ");
    scanf("%s", query);

    printf("\nSearch results:\n");
    int found = 0;
    int i=0;
    for (; i < carCount; i++) {
        if (strcasecmp(cars[i].make, query) == 0 || strcasecmp(cars[i].model, query) == 0) {
            printf("\nCar %d:\n", i + 1);
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: $%.2f\n", cars[i].price);
            printf("Mileage: %d miles\n", cars[i].mileage);
            found = 1;
        }
    }
	 if (!found) {
        printf("No cars found matching the query.\n");
    }
}

