#include <stdio.h>

#define NUM_FRAMES 3
#define NUM_PAGES 12

int main() {
    int frames[NUM_FRAMES] = {0}; // Initialize all frames to 0
    int pages[NUM_PAGES] = {1, 2, 3, 2, 1, 4, 5, 4, 3, 6, 3, 4}; // Page reference string
    int hits = 0, faults = 0;
    for (int i = 0; i < NUM_PAGES; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                hits++;
                break;
            }
        }

        // If the page is not in a frame, find the most recently used frame and replace it
        if (!found) {
            int mru = 0;
            for (int j = 1; j < NUM_FRAMES; j++) {
                if (frames[j] > frames[mru]) {
                    mru = j;
                }
            }
            frames[mru] = page;
            faults++;
        }

        printf("Page %d: ", page);
        for (int j = 0; j < NUM_FRAMES; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Hits: %d\n", hits);
    printf("Faults: %d\n", faults);

    return 0;
}