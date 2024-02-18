
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
    double ratio;
};

int compare(const void* a, const void* b) {
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}

void fractional_knapsack(struct Item items[], int num_items, int capacity) {
    qsort(items, num_items, sizeof(struct Item), compare);

    double total_value = 0.0;
    double total_weight = 0.0;

    for (int i = 0; i < num_items; i++) {
        if (items[i].weight <= capacity) {
            total_value += items[i].value;
            total_weight += items[i].weight;
            capacity -= items[i].weight;
        } else {
            total_value += (double)(items[i].value * capacity) / items[i].weight;
            total_weight += capacity;
            capacity = 0;
        }

        if (capacity == 0)
            break;
    }

    printf("Maximum value: %.2lf\n", total_value);

    printf("item-weight\n");
    for (int i = 0; i < num_items; i++) {
        if (items[i].weight <= capacity) {
            printf("%d-%d\n", i + 1, items[i].weight);
        } else {
            printf("%d-%.1lf\n", i + 1, (double)(items[i].value * capacity) / items[i].weight);
        }

        if (capacity == 0)
            break;
    }
}

int main() {
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    struct Item items[num_items];

    printf("Enter the weights of the items: ");
    for (int i = 0; i < num_items; i++) {
        scanf("%d", &items[i].weight);
    }

    printf("Enter the values of the items: ");
    for (int i = 0; i < num_items; i++) {
        scanf("%d", &items[i].value);
    }

    int capacity;
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < num_items; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    fractional_knapsack(items, num_items, capacity);

    return 0;
}
