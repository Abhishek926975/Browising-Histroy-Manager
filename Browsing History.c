#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* current = NULL;

// Function to create a new node
Node* createNode(char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Visit a new website
void visitWebsite(char* url) {
    Node* newNode = createNode(url);
    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    printf("Visited: %s\n", url);
}

// Display all history
void displayHistory() {
    if (head == NULL) {
        printf("History is empty.\n");
        return;
    }
    Node* temp = head;
    printf("\n--- Browser History ---\n");
    while (temp != NULL) {
        printf("%s\n", temp->url);
        temp = temp->next;
    }
    printf("-----------------------\n");
}

// Navigate backward
void back() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous website.\n");
        return;
    }
    current = current->prev;
    printf("Moved back to: %s\n", current->url);
}

// Navigate forward
void forward() {
    if (current == NULL || current->next == NULL) {
        printf("No forward website.\n");
        return;
    }
    current = current->next;
    printf("Moved forward to: %s\n", current->url);
}

// Delete a specific website from history
void deleteWebsite(char* url) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->url, url) == 0) {
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            if (temp == head) head = temp->next;
            if (temp == current) current = temp->prev ? temp->prev : temp->next;
            free(temp);
            printf("Deleted: %s\n", url);
            return;
        }
        temp = temp->next;
    }
    printf("Website not found in history.\n");
}

// Clear history
void clearHistory() {
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    head = current = NULL;
    printf("History cleared.\n");
}

// --- Sorting (Bubble Sort on Linked List) ---
void sortHistory() {
    if (head == NULL) return;
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (strcmp(ptr1->url, ptr1->next->url) > 0) {
                char temp[100];
                strcpy(temp, ptr1->url);
                strcpy(ptr1->url, ptr1->next->url);
                strcpy(ptr1->next->url, temp);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("History sorted alphabetically.\n");
}

// --- Searching (Linear Search) ---
void searchWebsite(char* url) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (strcmp(temp->url, url) == 0) {
            printf("Website found at position %d: %s\n", pos, temp->url);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("Website not found in history.\n");
}

// Menu
void menu() {
    printf("\n===== Browser History Manager =====\n");
    printf("1. Visit Website\n");
    printf("2. Back\n");
    printf("3. Forward\n");
    printf("4. Display History\n");
    printf("5. Delete Website\n");
    printf("6. Clear History\n");
    printf("7. Search Website\n");
    printf("8. Sort History Alphabetically\n");
    printf("9. Exit\n");
    printf("==================================\n");
}

int main() {
    int choice;
    char url[100];

    while (1) {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter website URL: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0; // remove newline
                visitWebsite(url);
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                displayHistory();
                break;
            case 5:
                printf("Enter website URL to delete: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0;
                deleteWebsite(url);
                break;
            case 6:
                clearHistory();
                break;
            case 7:
                printf("Enter website URL to search: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0;
                searchWebsite(url);
                break;
            case 8:
                sortHistory();
                break;
            case 9:
                clearHistory();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
