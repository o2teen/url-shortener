#include <stdio.h>
#include <string.h>

#define MAX_URLS 100
#define MAX_URL_LENGTH 100

// Array to store original URLs
char urlDatabase[MAX_URLS][MAX_URL_LENGTH];
int urlCount = 0;

// Function to shorten a URL
int shortenURL(const char* originalURL) {
    if (urlCount >= MAX_URLS) {
        printf("Error: URL database is full.\n");
        return -1;
    }

    // Store the original URL in the database
    strncpy(urlDatabase[urlCount], originalURL, MAX_URL_LENGTH - 1);
    urlDatabase[urlCount][MAX_URL_LENGTH - 1] = '\0'; // Ensure null termination

    // Return the short URL ID (index in the database)
    return urlCount++;
}

// Function to retrieve a URL using its short ID
const char* getOriginalURL(int shortID) {
    if (shortID < 0 || shortID >= urlCount) {
        return "Error: Invalid short URL ID.";
    }
    return urlDatabase[shortID];
}

int main() {
    int choice;
    char inputURL[MAX_URL_LENGTH];
    int shortID;

    printf("Simple URL Shortener\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Shorten a URL\n");
        printf("2. Retrieve a URL\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the URL to shorten: ");
                scanf("%s", inputURL);
                shortID = shortenURL(inputURL);
                if (shortID != -1) {
                    printf("Shortened URL ID: %d\n", shortID);
                }
                break;

            case 2:
                printf("Enter the short URL ID: ");
                scanf("%d", &shortID);
                printf("Original URL: %s\n", getOriginalURL(shortID));
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
