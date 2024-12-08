#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bus information
struct Bus{
    int busNumber;
    char source[50];
    char destination[50];
    int totalSeats;
    int availableSeats;
    float fare;
    int seatno[50];
};

// Define a structure to store user login information
struct User{
    char username[50];
    char password[50];
};

struct adminuser{
    char adminuser[50];
    char adminpass[50];
};

// Function to display the main menu
void displayMainMenu(){
    printf("\n=== Main Menu ===\n");
    printf("1. Login\n");
    printf("2. Admin login\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// Function to display the user menu
void displayUserMenu(){
    printf("\n=== User Menu ===\n");
    printf("1. Book a Ticket\n");
    printf("2. Cancel a Ticket\n");
    printf("3. Check Bus Status\n");
    printf("4. Logout\n");
    printf("Enter your choice: ");
}

// Function to perform user login
int loginUser(struct User users[], int numUsers, char username[], char password[]){
    for (int i = 0; i < numUsers; i++){
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0){
            return i; // Return the index of the logged-in user
        }
    }
    return -1; // Return -1 if login fails
}

// Admin login
int adminlogin(struct adminuser admins[], int numadmins, char adminuser[], char adminpass[]){
    for(int i=0 ; i < numadmins ; i++){
        if (strcmp(admins[i].adminuser, adminuser) == 0 && strcmp(admins[i].adminpass, adminpass) == 0){
            return i; // Return index of logged in admin
        }
    }
    return -1; // Return -1 if login fails
}

// Function to book tickets
void bookTicket(struct Bus buses[], int numBuses){
    printf("\nEnter Bus Number: ");
    int busNumber;
    scanf("%d", &busNumber);

    // Find the bus with the given busNumber
    int busIndex = -1;
    for (int i = 0; i < numBuses; i++){
        if (buses[i].busNumber == busNumber){
            busIndex = i;
            break;
        }
    }

    if (busIndex == -1){
        printf("Bus with Bus Number %d not found.\n", busNumber);
    }
    else{
        printf("Enter Number of Seats: ");
        int seatsToBook;
        scanf("%d", &seatsToBook);
        if (buses[busIndex].availableSeats < seatsToBook){
            printf("Sorry, only %d seats are available.\n", buses[busIndex].availableSeats);
        }
        else{
            buses[busIndex].availableSeats -= seatsToBook;
            printf("Your Booked Seats Are ");
            for (int g=0; g<seatsToBook; g++)
            {
                printf("%d ", buses[busIndex].seatno[g]);
            }
            int size=sizeof(buses[busIndex].seatno)/sizeof(buses[busIndex].seatno[0]);
            //printf("size  %d", size);
            int seatstoBook=seatsToBook;
            while(seatstoBook--)
            {
                for (int g=1; g<size; g++)
            {
                buses[busIndex].seatno[g-1]=buses[busIndex].seatno[g];
            }
            size--;
            }


            printf("Booking successful! %d seats booked on Bus Number %d.\n", seatsToBook, busNumber);
        }
    }
}

// Function to cancel tickets
void cancelTicket(struct Bus buses[], int numBuses){
    printf("\nEnter Bus Number: ");
    int busNumber;
    scanf("%d", &busNumber);

    // Find the bus with the given busNumber
    int busIndex = -1;
    for (int i = 0; i < numBuses; i++){
        if (buses[i].busNumber == busNumber){
            busIndex = i;
            break;
        }
    }

    if (busIndex == -1){
        printf("Bus with Bus Number %d not found.\n", busNumber);
    }
    else{
        printf("Enter Number of Seats to Cancel: ");
        int seatsToCancel;
        scanf("%d", &seatsToCancel);

        if (seatsToCancel > (buses[busIndex].totalSeats - buses[busIndex].availableSeats)){
            printf("Error: You can't cancel more seats than were booked.\n");
        }
        else{

            printf("Cancellation successful! %d seats canceled on Bus Number %d.\n", seatsToCancel,
                   busNumber);
            for(int a=seatsToCancel; a>0; a--)
            {
                buses[busIndex].seatno[buses[busIndex].availableSeats]=(buses[busIndex].totalSeats-buses[busIndex].availableSeats);
                buses[busIndex].availableSeats++;
            }
            //buses[busIndex].availableSeats += seatsToCancel;
        }
    }
}

// Function to check bus status
void checkBusStatus(struct Bus buses[], int numBuses){
    printf("\nEnter Bus Number: ");
    int busNumber;
    scanf("%d", &busNumber);

    // Find the bus with the given busNumber
    int busIndex = -1;
    for (int i = 0; i < numBuses; i++){
        if (buses[i].busNumber == busNumber){
            busIndex = i;
            break;
        }
    }

    if (busIndex != -1){
        printf("\nBus Number: %d\n", buses[busIndex].busNumber);
        printf("Source: %s\n", buses[busIndex].source);
        printf("Destination: %s\n", buses[busIndex].destination);
        printf("Total Seats: %d\n", buses[busIndex].totalSeats);
        printf("Available Seats: %d\n", buses[busIndex].availableSeats);
        printf("Fare: %.2f\n", buses[busIndex].fare);
    }
    else{
        printf("Bus with Bus Number %d not found.\n", busNumber);
    }
}

int main(){
    // Initialize user data
    struct User users[6] = {
        {"user1", "pass1"}, {"user2", "pass2"}, {"user3", "pass3"}, {"user4", "pass4"}, {"Admin-Nex", "1234"}, {"gopi", "cars"}
    };
    struct adminuser admins[2] = {
        {"nex","1234"}, {"2.0","1234"}
    };
    int numUsers = 6;
    int numadmins = 2;

    int flag=0;

    // Initialize bus data
    struct Bus buses[3] = {
        {101, "City A", "City B", 50, 50, 500.0, {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}},
        {102, "City C", "City D", 50, 50, 400.0, {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}},
        {103, "City E", "City F", 50, 50, 300.0, {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}}
    };
    int numBuses = 3;

    int loggedInUserId = -1; // Index of the logged-in user
    int loggedInAdminId = -1; // "       "

    while (1){
        if (loggedInUserId == -1 && loggedInAdminId)
        {
            displayMainMenu();
            int choice;
            scanf("%d", &choice);

            if (choice == 1)
            {
                char username[50];
                char password[50];

                printf("Enter Username: ");
                scanf("%s", username);
                printf("Enter Password: ");
                scanf("%s", password);

                loggedInUserId = loginUser(users, numUsers, username, password);
                if (loggedInUserId == -1){
                    printf("Login failed. Please check your username and password.\n");
                }
                else{
                    printf("Login successful. Welcome, %s!\n", username);
                }
            }

            else if (choice == 2)
            {
                char adminuser[50];
                char adminpass[50];

                printf("Enter Username: ");
                scanf("%s", adminuser);
                printf("Enter Password: ");
                scanf("%s", adminpass);

                loggedInAdminId = adminlogin(admins, numadmins, adminuser, adminpass);
                if (loggedInAdminId == -1){
                    printf("Login failed. Please check your Username and Password. \n");
                }
                else{
                    printf("Login successful. Welcome, %s!\n", adminuser);
                    flag=1;
                }
            }
            else if (choice == 3)
            {
                printf("Exiting the program.\n");
                break;
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
            }
        }

        else if (flag == 1)
        {

        }
        else{
            displayUserMenu();
            int userChoice;
            scanf("%d", &userChoice);

            switch (userChoice){
            case 1:
                bookTicket(buses, numBuses);
                break;
            case 2:
                cancelTicket(buses, numBuses);
                break;
            case 3:
                checkBusStatus(buses, numBuses);
                break;
            case 4:
                printf("Logging out.\n");
                loggedInUserId = -1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}
