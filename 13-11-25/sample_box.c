#include <stdio.h>

int main() {
    int boxes[] = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    int n = 9;
    int sum = 0;
    int i, j;

    while (1) {
        int found = 0; 

        for (i = 0; i < n; i++) {
            int count = 1;
            for (j = i + 1; j < n; j++) {
                if (boxes[j] == boxes[i])
                    count++;
                else
                    break;
            }
            if (count > 1) {
                sum += count * count;
                found = 1;

                for (int k = j; k < n; k++) {
                    boxes[k - count] = boxes[k];
                }
                n -= count; 
                break; 
            }
        }

        if (!found)
            break;
    }

    printf("Total points: %d", sum);
    return 0;
}
