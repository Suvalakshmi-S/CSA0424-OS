#include<stdio.h>
#include<stdlib.h>

// Function to sort the tracks in ascending order
void sortTracks(int tracks[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (tracks[j] > tracks[j+1]) {
                temp = tracks[j];
                tracks[j] = tracks[j+1];
                tracks[j+1] = temp;
            }
        }
    }
}

// Function to calculate the average head movement using SCAN algorithm
float calculateAverageHeadMovement(int tracks[], int n, int head) {
    int i, position, direction, totalHeadMovement = 0;
    
    sortTracks(tracks, n);
    
    // Find the position of the head in the sorted tracks array
    for (i = 0; i < n; i++) {
        if (tracks[i] >= head) {
            position = i;
            break;
        }
    }
    
    // Calculate the head movement when moving towards the right
    direction = 1;
    for (i = position; i < n; i++) {
        totalHeadMovement += abs(head - tracks[i]);
        head = tracks[i];
    }
    
    // Calculate the head movement when moving towards the left
    direction = -1;
    totalHeadMovement += abs(head - tracks[i-1]);
    head = tracks[i-1];
    
    for (i = position-1; i >= 0; i--) {
        totalHeadMovement += abs(head - tracks[i]);
        head = tracks[i];
    }
    
    return (float)totalHeadMovement / n;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int head = 50;
    
    float averageHeadMovement = calculateAverageHeadMovement(tracks, n, head);
    
    printf("Average head movement: %.2f\n", averageHeadMovement);
    
    return 0;
}

