// Structures - 2
#include <stdio.h>
#include <stdlib.h>
// Rectangle Inventory and Geometry Analysis
typedef struct {
    float width;
    float height;
    float area;
    float perimeter;
} Rectangle;

// Calculate area and perimeter
void calculate_geometry(Rectangle *r) {
    r->area = r->width * r->height;
    r->perimeter = 2 * (r->width + r->height);
}

// Dynamically allocate rectangle array
Rectangle* create_rectangle_array(int size) {
    Rectangle *rectangles = (Rectangle*) malloc(size * sizeof(Rectangle));

    if (rectangles == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    return rectangles;
}

// Add rectangle details
void add_rectangle(Rectangle *rectangles, int index, float width, float height) {
    rectangles[index].width = width;
    rectangles[index].height = height;

    calculate_geometry(&rectangles[index]);
}

// Display rectangle records
void display_rectangles(Rectangle *rectangles, int size) {
    printf("\n--- Rectangle Inventory ---\n");

    for (int i = 0; i < size; i++) {
        printf("Rectangle %d:\n", i + 1);
        printf("Width = %.2f\n", rectangles[i].width);
        printf("Height = %.2f\n", rectangles[i].height);
        printf("Area = %.2f\n", rectangles[i].area);
        printf("Perimeter = %.2f\n\n", rectangles[i].perimeter);
    }
}

// Calculate total area
void calculate_total_area(Rectangle *rectangles, int size) {
    float total = 0;

    for (int i = 0; i < size; i++) {
        total += rectangles[i].area;
    }

    printf("Total Area = %.2f\n", total);
}

// Find rectangle with largest area
void find_largest_rectangle(Rectangle *rectangles, int size) {
    int largest = 0;

    for (int i = 1; i < size; i++) {
        if (rectangles[i].area > rectangles[largest].area) {
            largest = i;
        }
    }

    printf("\n--- Largest Rectangle ---\n");
    printf("Rectangle Number: %d\n", largest + 1);
    printf("Area = %.2f\n", rectangles[largest].area);
    printf("Perimeter = %.2f\n", rectangles[largest].perimeter);
}

// Free allocated memory
void free_rectangle_array(Rectangle *rectangles) {
    free(rectangles);
}

int main() {
    int number_of_rectangles = 2;

    Rectangle *rectangles = create_rectangle_array(number_of_rectangles);

    add_rectangle(rectangles, 0, 5.0, 4.0);
    add_rectangle(rectangles, 1, 6.5, 3.5);

    display_rectangles(rectangles, number_of_rectangles);

    calculate_total_area(rectangles, number_of_rectangles);

    find_largest_rectangle(rectangles, number_of_rectangles);

    free_rectangle_array(rectangles);

    return 0;
}
