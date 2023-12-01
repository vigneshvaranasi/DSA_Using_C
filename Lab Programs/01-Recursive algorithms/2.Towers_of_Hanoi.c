#include <stdio.h>
void moveDisk(int n, char source, char destination) {
    printf("Move disk %d from %c to %c\n", n, source, destination);
}

// Function to solve Towers of Hanoi with 'n' disks, using auxiliary peg
void towersOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveDisk(1, source, destination);
        return;
    }

    // Move (n-1) disks from source to auxiliary peg using destination peg
    towersOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination peg
    moveDisk(n, source, destination);

    // Move (n-1) disks from auxiliary to destination peg using source peg
    towersOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Call the Towers of Hanoi function
    towersOfHanoi(numDisks, 'A', 'B', 'C');

    return 0;
}
