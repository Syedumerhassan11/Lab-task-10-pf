#include <stdio.h>
#include <string.h>

// Define the structure for employee data
struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

int main() {
    int n;

    // Prompt user for the number of employees
    printf("Enter the number of employees: ");
    scanf_s("%d", &n);

    struct Employee employees[n];
	int i=0;
    for (; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);

        // Input Employee ID
        printf("Employee ID: ");
        scanf_s("%d", &employees[i].id);

        // Clear the input buffer to avoid issues with fgets
        getchar();

        // Input Employee Name
        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        // Remove the trailing newline character
        employees[i].name[strcspn(employees[i].name, "\n")] = 0;

        // Input Employee Department
        printf("Department: ");
        fgets(employees[i].department, sizeof(employees[i].department), stdin);
        // Remove the trailing newline character
        employees[i].department[strcspn(employees[i].department, "\n")] = 0;

        // Input Employee Salary
        printf("Salary: ");
        scanf_s("%f", &employees[i].salary);
    }

    // Display employee details
    printf("\nEmployee Details:\n");
    printf("------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("------------------------------------------------------------\n");
	int i=0;
    for (; i < n; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }

    return 0;
}

