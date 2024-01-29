#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 10

typedef struct {
    char name[50];
    int seatNumber;
} Passenger;

Passenger bus[MAX_SEATS];

int validateLogin(char username[], char password[]) {

    if (strcmp(username, "Admin") == 0 && strcmp(password, "Password") == 0) {
        return 1; // Valid credentials
    } else {
        return 0; // Invalid credentials
    }
}

void displayMenu() {
    printf("\n1. Book a ticket\n\n");
    printf("2. Cancel a booking\n\n");
    printf("3. Display bookings\n\n");
    printf("4. Exit\n\n");
}

void bookTicket() {
    int seat;
    printf("Enter seat number (1-%d): ", MAX_SEATS);
    scanf("%d", &seat);
 if (seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (bus[seat - 1].seatNumber == 0) {
        printf("Enter passenger name: ");
        scanf("%s", bus[seat - 1].name);
        bus[seat - 1].seatNumber = seat;
        printf("\nTicket booked successfully!\n");
    } else {
        printf("Seat already booked.\n");
    }
}

void cancelBooking() {
    int seat;
    printf("Enter seat number to cancel booking: ");
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (bus[seat - 1].seatNumber == seat) {
        bus[seat - 1].seatNumber = 0;
        printf("Booking cancelled successfully!\n");
    } else {
        printf("No booking found for this seat.\n");
    }
}

void displayBookings() {
    printf("\nSeat\tPassenger Name\n");
    for (int i = 0; i < MAX_SEATS; ++i) {
        if (bus[i].seatNumber != 0) {
            printf("\n%d\t%s\n", bus[i].seatNumber, bus[i].name);
        }
    }
}

int main() {

    char username[20];
    char password[20];
    printf("\t\t\t************\n\n");
    printf("\t\t\t\t\tBUS TICKET BOOKING\n\n");
    printf("\t\t\t************\n\n\n");
    printf("Enter username: ");
    scanf("%s" ,username);

    printf("\nEnter password: ");
    scanf("%s", password);
    printf("\n");
     printf("-------------------------------------------------------------------\n");

    // Validate login
    if (validateLogin(username, password)) {
        printf("\nLogin successful. Welcome, %s!\n\n", username);

        int choice;

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                cancelBooking();
                break;
            case 3:
                displayBookings();
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    } else {
        printf("\nInvalid credential. Please try again.\n");
    }



    return 0;
}
