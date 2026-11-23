#include <stdio.h>

// Define the structure for a student
struct Student {
    int rollNo;
    char name[50];
    int marks[3]; // Array to store marks for 3 subjects
    int total;
    float percentage;
};

int main() {
    int n, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Declare an array of structures dynamically based on user input
    struct Student s[n];

    // Accept student details
    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);
        while ((getchar()) != '\n');

        printf("Name: ");
        // Using fgets to safely read names with spaces
        fgets(s[i].name, sizeof(s[i].name), stdin);

        // Remove trailing newline character added by fgets
        for (int k = 0; s[i].name[k] != '\0'; k++) {
            if (s[i].name[k] == '\n') {
                s[i].name[k] = '\0';
                break;
            }
        }

        s[i].total = 0;
        printf("Enter marks for 3 subjects (out of 100):\n");
        for (j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        // Calculate percentage (3 subjects * 100 = 300 max marks)
        s[i].percentage = (float)s[i].total / 3;
    }

    // Display the results
    printf("\n================================ STUDENT RESULTS ================================\n");
    printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s\n", "Roll No", "Name", "Sub 1", "Sub 2", "Sub 3", "Total", "Percentage");
    printf("---------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-10d %-10d %-10d %-10d %-10.2f%%\n",
               s[i].rollNo,
               s[i].name,
               s[i].marks[0],
               s[i].marks[1],
               s[i].marks[2],
               s[i].total,
               s[i].percentage);
    }
    printf("=================================================================================\n");

    return 0;
}
