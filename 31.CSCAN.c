#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100
int i,j;
int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

void cscan(int tracks[], int num_tracks, int start_track) {
    int total_head_movement = 0;
    int current_track = start_track;

    // Sort the tracks in ascending order
    for ( i = 0; i < num_tracks - 1; i++) {
        for (j = 0; j < num_tracks - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    // Find the position of the start track
    int start_index = 0;
    for (i = 0; i < num_tracks; i++) {
        if (tracks[i] >= start_track) {
            start_index = i;
            break;
        }
    }

    // Head movement from start track to the end
    for (i = start_index; i < num_tracks; i++) {
        printf("Move from %d to %d\n", current_track, tracks[i]);
        total_head_movement += abs_diff(current_track, tracks[i]);
        current_track = tracks[i];
    }

    // Head movement from the beginning to the start track
    printf("Move from %d to %d\n", current_track, tracks[0]);
    total_head_movement += abs_diff(current_track, tracks[0]);
    current_track = tracks[0];

    // Head movement from the start track to the end of the disk
    for (i = 1; i < start_index; i++) {
        printf("Move from %d to %d\n", current_track, tracks[i]);
        total_head_movement += abs_diff(current_track, tracks[i]);
        current_track = tracks[i];
    }

    printf("Total head movement: %d\n", total_head_movement);
    float average_head_movement = (float) total_head_movement / num_tracks;
    printf("Average head movement: %.2f\n", average_head_movement);
}

int main() {
    int tracks[MAX_TRACKS] = {55, 58, 60, 70, 18};
    int num_tracks = 5;
    int start_track = 55;

    printf("C-SCAN Disk Scheduling Algorithm:\n");
    cscan(tracks, num_tracks, start_track);

    return 0;
}

