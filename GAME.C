#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a room
struct Room {
    char name[50];
    char description[200];
    int choices[3]; // Indices of the connected rooms
};

// Function to display room information and choices
void displayRoom(struct Room currentRoom) {
    printf("\nYou are in %s.\n", currentRoom.name);
    printf("%s\n", currentRoom.description);

    printf("\nWhere do you want to go?\n");
    printf("1. %s\n", rooms[currentRoom.choices[0]].name);
    printf("2. %s\n", rooms[currentRoom.choices[1]].name);
    printf("3. %s\n", rooms[currentRoom.choices[2]].name);
}

// Function to play the game
void playGame() {
    int currentRoomIndex = 0; // Start in the first room

    while (1) {
        struct Room currentRoom = rooms[currentRoomIndex];

        // Display the current room and choices
        displayRoom(currentRoom);

        // Get user choice
        int choice;
        printf("\nEnter your choice (1/2/3, or 0 to quit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("\nGoodbye! Thanks for playing.\n");
            break;
        } else if (choice >= 1 && choice <= 3) {
            currentRoomIndex = currentRoom.choices[choice - 1];
        } else {
            printf("\nInvalid choice. Please select 1, 2, 3, or 0 to quit.\n");
        }
    }
}

int main() {
    // Create rooms
    struct Room rooms[3];
    strcpy(rooms[0].name, "Room 1");
    strcpy(rooms[0].description, "This is Room 1. There are three doors: Door A, Door B, and Door C.");
    rooms[0].choices[0] = 1; // Room 1 -> Room 2
    rooms[0].choices[1] = 2; // Room 1 -> Room 3
    rooms[0].choices[2] = 2; // Room 1 -> Room 3

    strcpy(rooms[1].name, "Room 2");
    strcpy(rooms[1].description, "This is Room 2. There's a treasure chest here!");
    rooms[1].choices[0] = 0; // Room 2 -> Room 1
    rooms[1].choices[1] = 0; // Room 2 -> Room 1
    rooms[1].choices[2] = 0; // Room 2 -> Room 1

    strcpy(rooms[2].name, "Room 3");
    strcpy(rooms[2].description, "This is Room 3. There's a monster lurking nearby.");
    rooms[2].choices[0] = 0; // Room 3 -> Room 1
    rooms[2].choices[1] = 2; // Room 3 -> Room 3 (loop back)
    rooms[2].choices[2] = 2; // Room 3 -> Room 3 (loop back)

    // Start the game
    printf("Welcome to the Text-Based Adventure Game!\n");
    playGame();

    return 0;
}
