#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n;

int main() {
    int ch;
    char g = 'y';
    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;          
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                g = 'n'; // To exit the loop
                break;
            default:
                printf("\nEnter the correct choice.");
        }       
        if (g != 'n') {
            printf("\nDo you want to continue? (y/n): ");
            scanf(" %c", &g); // Note the space before %c
        }
    } while(g == 'y' || g == 'Y');

    return 0;
}

void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("\nNumber of nodes exceeds the maximum limit.");
        n = MAX;
    }
    for(int i = 0; i < n; i++) {
        printf("\nEnter the element for node %d: ", i + 1);
        scanf("%d", &b[i]); 
    }
}

void deletion() {
    int pos;
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);
    if(pos >= n || pos < 0) {
        printf("\nInvalid location.");
    } else {
        for(int i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
        printf("\nThe elements after deletion: ");
        for(int i = 0; i < n; i++) {
            printf("%d ", b[i]);
        }
    }
}

void search() {
    int e, found = 0;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);
    for(int i = 0; i < n; i++) {
        if(b[i] == e) {
            printf("Value is in position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

void insert() {
    int pos, p;
    if (n >= MAX) {
        printf("\nArray is full. Cannot insert new element.");
        return;
    }
    printf("\nEnter the position to insert: ");
    scanf("%d", &pos);
    if(pos > n || pos < 0) {
        printf("\nInvalid location."); 
    } else {
        for(int i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++; 
    }
    printf("\nThe list after insertion: ");
    display(); 
}

void display() {
    printf("\nThe elements of the list are: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
