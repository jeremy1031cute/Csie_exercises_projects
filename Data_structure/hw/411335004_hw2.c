#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_LINK -1

//printf array
void prin_arr (int *arr, int nums) {
    for (int i = 0; i < nums; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int updateable[100000];
//check whether the path is passable
int is_accessible (int *arr, int start, int nums) {
    memset(updateable, 0, nums*sizeof(int));
    int curr_node_link = arr[start];
    updateable[curr_node_link] = 1;
    //printf("%d ", curr_node_link);
    for (int i = 0; i < nums && curr_node_link != NO_LINK; i++) {
        curr_node_link = arr[curr_node_link];
        updateable[curr_node_link] = 1;
        //printf("%d ", curr_node_link);
        if (curr_node_link == nums - 1) {
            return 1;
        }
    }
    printf("NO ACESS\n");
    return 0;
}

int main() {
    int nums, steps = 5; //first + empty node update + s + new_path + last
    scanf("%d ", &nums);
    int s = 0, d = nums - 1;
    int arr[nums], last_arr[nums], curr_arr[nums], temp_arr[nums];
    int trace[nums];
    memset(trace, 0, nums*sizeof(int));

    //input
    for (int i = 0; i < nums; i++) {
        scanf("%d", &arr[i]);
        curr_arr[i] = arr[i];
        temp_arr[i] = arr[i];
    }
    for (int i = 0; i < nums; i++) {
        scanf("%d", &last_arr[i]);
    }

    //array to trace d from s (exchange node's link and node num)
    for (int i = nums - 1; i >= 0; i--) {
        if (last_arr[i] != NO_LINK)
            trace[last_arr[i]] = i;
    }
    trace[s] = NO_LINK; //s is the final node, its link is -1
    //printf("%d\n", trace[d]);


    //count steps
    for (int i = 0; i < nums; i++) {
        if (temp_arr[i] == NO_LINK && last_arr[i] != NO_LINK) {
            temp_arr[i] = last_arr[i];
        }
    }
    temp_arr[s] = last_arr[s];
    is_accessible(temp_arr, s, nums);
    for (int i = 0; i < nums; i++) {
        if (updateable[i] == 0) {
            temp_arr[i] = last_arr[i];
        }
    }
    for (int i = nums - 1; i >= 0; i--) {
        if (temp_arr[i] != last_arr[i]) {
            if (last_arr[i] != NO_LINK)
                steps++;//already updated empty node
        }
    }
    for (int i = 0; i < nums; i++) {
        if (temp_arr[i] == NO_LINK && temp_arr[i] != NO_LINK) {
            temp_arr[i] = last_arr[i];
        }
    }
    printf("%d\n", steps);

    //output
    prin_arr(arr, nums);
    //empty
    for (int i = 0; i < nums; i++) {
        if (curr_arr[i] == NO_LINK && last_arr[i] != NO_LINK) {
            curr_arr[i] = last_arr[i];
        }
    }
    prin_arr(curr_arr, nums);
    //update s
    curr_arr[s] = last_arr[s];
    prin_arr(curr_arr, nums);
    //sign the curr_node and update others
    is_accessible(curr_arr, s, nums);
    for (int i = 0; i < nums; i++) {
        if (updateable[i] == 0) {
            curr_arr[i] = last_arr[i];
        }
    }
    prin_arr(curr_arr, nums);
    //trace back(start from d, end in s)
    int link = d;
    while (link != NO_LINK) {
        //compare link, update different node
        if (curr_arr[link] != last_arr[link]) {
            curr_arr[link] = last_arr[link];
            prin_arr(curr_arr, nums);
        }
        link = trace[link];
    }
    //delete unuseful node
    prin_arr(last_arr, nums);

    return 0;
}
