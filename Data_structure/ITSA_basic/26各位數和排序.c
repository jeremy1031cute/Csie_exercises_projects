#include <stdio.h>

struct number {
    int sum;
    int num_10;
};

int cmpfunc (const void * a, const void * b) {
    const struct number *elem1 = a;
    const struct number *elem2 = b;

    if (elem1->sum < elem2->sum)
        return -1;
    else if (elem1->sum > elem2->sum)
        return 1;
    else
        return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    struct number nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i].num_10);
        int compute = nums[i].num_10;
        nums[i].sum = 0;
        while (compute != 0) { // notice!
            nums[i].sum += (compute % 10);
            compute /= 10;
        }
    }

    qsort(nums, n, sizeof(struct number), cmpfunc);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i].sum == nums[j].sum) {
                if (nums[i].num_10 > nums[j].num_10) {
                    int temp = nums[i].num_10;
                    nums[i].num_10 = nums[j].num_10;
                    nums[j].num_10 = temp;
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        if (i != n-1)
            printf("%d ", nums[i].num_10);
        else
            printf("%d\n", nums[i].num_10);
    }

}
