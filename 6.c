// Unions - Memory-Efficient Typed Records and Safe Union Access

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum to identify the data type
typedef enum {
    INT,
    FLOAT,
    STRING
} DataType;

// Union to store different types of data
typedef union {
    int i;
    float f;
    char str[20];
} UnionData;

// Structure to store union and its type
typedef struct {
    UnionData data;
    DataType type;
} TypedRecord;

// Function to display data safely
void display_record(TypedRecord record) {

    switch (record.type) {

        case INT:
            printf("Integer Value: %d\n", record.data.i);
            break;

        case FLOAT:
            printf("Float Value: %.2f\n", record.data.f);
            break;

        case STRING:
            printf("String Value: %s\n", record.data.str);
            break;

        default:
            printf("Invalid Data Type!\n");
    }
}

int main() {

    TypedRecord record;

    // Store integer
    record.data.i = 10;
    record.type = INT;

    printf("--- Integer Record ---\n");
    display_record(record);

    // Store float
    record.data.f = 220.5;
    record.type = FLOAT;

    printf("\n--- Float Record ---\n");
    display_record(record);

    // Store string
    strcpy(record.data.str, "Union Programming");
    record.type = STRING;

    printf("\n--- String Record ---\n");
    display_record(record);

    // Memory information
    printf("\n--- Memory Information ---\n");

    printf("Size of UnionData: %zu bytes\n", sizeof(UnionData));
    printf("Size of TypedRecord: %zu bytes\n", sizeof(TypedRecord));

    printf("\nMemory Addresses:\n");
    printf("Union: %p\n", (void*)&record.data);
    printf("Type: %p\n", (void*)&record.type);

    return 0;
}
