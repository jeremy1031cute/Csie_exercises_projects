int main() {
    float num[10];

    for (int i = 0; i < 10; i++) {
        scanf("%f", &num[i]);
    }

    float max = num[0], min = num[0];


    for (int i = 0; i < 10; i++) {
        if (max < num[i])
            max = num[i];
        if (min > num[i])
            min = num[i];
    }
    printf("maximum:%.2f\n", max);
    printf("minimum:%.2f\n", min);
}

