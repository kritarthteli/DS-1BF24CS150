#include <stdio.h>
#define MAX 100

int hashTable[MAX];
int m;

void insert(int key) {
    int index, i = 0;
    index = key % m;  
    while (hashTable[(index + i) % m] != -1)
        i++;
    hashTable[(index + i) % m] = key;
}

void display() {
    printf("\nHash Table:\n");
    printf("Address Key\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("%d\t%d\n", i, hashTable[i]);
        else
            printf("%d\t--\n", i);
    }
}

int main() {
    int n, key;

    printf("Enter number of employee records: ");
    scanf("%d", &n);
    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
        hashTable[i] = -1;

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    display();

    return 0;
}
