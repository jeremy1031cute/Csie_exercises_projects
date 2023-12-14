#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define Obstacle 1

#define debug printf("debug %d\n", __LINE__);

//declartion
int maze_size = 0;
int maze[1000][1000];
int ball_x, ball_y, ball2_x, ball2_y;
int hole_x, hole_y, hole2_x, hole2_y;

//structure which saves x,y
struct coordinates{
    int x;
    int y;
};

//use bfs with queue to explore the maze
struct Queue{
    struct Queue *front;
    struct coordinates *data;
    struct Queue *next;
    struct Queue *rear;
};

//create first queue node
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->next = NULL;
    queue->rear = queue; //not == NULL!!
    return queue;
}

//func for distribute the value to queue's data
struct coordinates *createXY(int x, int y) {
    struct coordinates *ptr = (struct coordinates*)malloc(sizeof(struct coordinates));
    ptr->x = x;
    ptr->y = y;
    //printf("creatXY: x: %d, y: %d\n", x, y);
    return ptr;
}

//check if queue node is empty
int isEmpty(struct Queue* queue) {
    return (queue == NULL);
}

//add a queue node
void enqueue(struct Queue **queue, struct coordinates *item) { //remeber to save coord... in advance
    struct Queue *newNode = (struct Queue*)malloc(sizeof(struct Queue));
    if (newNode == NULL) {
        // make sure allocate memory sucess
        fprintf(stderr, "Failed to allocate memory for newNode\n");
    }
    newNode->data = item;
    newNode->next = NULL;
    newNode->rear = newNode;//be careful

    if (isEmpty((*queue))) {
        (*queue) = newNode;
        if ((*queue) == NULL) {
            fprintf(stderr, "Failed to allocate memory for newNode\n");
        }
        (*queue)->front = NULL;
        //debug
    } else {
        newNode->front = (*queue);
        (*queue)->rear->next = newNode;
    }
    (*queue)->rear = newNode;
}

//delete a queue node but not free the memory->can trace back through the pointer "front"
void dequeue(struct Queue **first) {
    if (isEmpty((*first))) {
        //printf("Queue is empty\n");
    } else {
        if ((*first)->next != NULL) {
            (*first)->next->rear = (*first)->rear;
            (*first) = (*first)->next;
        } else {
            (*first) = NULL;
        }
    }
}

//explore the maze, count steps
void bfs(int start_x, int start_y, int *steps_recorded, int *steps_count, int *isFilled, int *isFilled2) {
    int isVisited[maze_size][maze_size];
    //int isVisited[maze_size][maze_size]={0,0};->can't do this
    memset(isVisited, 0, maze_size*maze_size*sizeof(int));

    struct Queue* first = createQueue();
    first->data = createXY(start_x, start_y);
    struct Queue* got_cha;//record the hole

    while(first != NULL){
        int fx = first->data->x, fy = first->data->y;
        isVisited[fx][fy] = 1;

        if((fx == hole_x && fy == hole_y) && (*isFilled) == 0) {
            (*isFilled) = 1;
            got_cha = first;//maybe the last node isn't the hole
            break;
        }
        if((fx == hole2_x && fy == hole2_y) && (*isFilled2) == 0) {
            (*isFilled2) = 1;
            got_cha = first;
            break;
        }

        //no else if,otherwise they will enqueue only one time instead of four times
        if((maze[fx][fy + 1] != Obstacle) && (isVisited[fx][fy + 1] != 1)) { //up
            enqueue(&first, createXY(fx, fy + 1));
        }
        if((maze[fx + 1][fy] != Obstacle) && (isVisited[fx + 1][fy] != 1)) { //right
            enqueue(&first, createXY(fx + 1, fy));
        }
        if((maze[fx][fy - 1] != Obstacle) && (isVisited[fx][fy - 1] != 1)) { //down
            enqueue(&first, createXY(fx, fy - 1));
        }
        if((maze[fx - 1][fy] != Obstacle) && (isVisited[fx - 1][fy] != 1)) { //left
            enqueue(&first, createXY(fx - 1, fy));
        }
        dequeue(&first);
    }

    //trace back! one node's front have only a node, use linklist Queue to record direction
    struct Queue *steps = NULL;
    struct Queue *trace = got_cha;
    while(trace->data->x != start_x || trace->data->y != start_y){
        if((trace->front->data->y) < (trace->data->y)) {
            //debug
            if(steps == NULL){
                steps = createQueue();
                steps->data = createXY(UP, 0);
            } else {
                enqueue(&steps, createXY(UP, 0));
            }
        }
        if((trace->front->data->x) < (trace->data->x)) {
            //debug
            if(steps == NULL){
                steps = createQueue();
                steps->data = createXY(RIGHT, 0);
            } else {
                enqueue(&steps, createXY(RIGHT, 0));
            }
        }
        if((trace->front->data->y) > (trace->data->y)) {
            //debug
            if(steps == NULL){
                steps = createQueue();
                steps->data = createXY(DOWN, 0);
            } else {
                enqueue(&steps, createXY(DOWN, 0));
            }
        }
        if((trace->front->data->x) > (trace->data->x)) {
            //debug
            if(steps == NULL){
                //debug
                steps = createQueue();
                steps->data = createXY(LEFT, 0);
            } else {
               enqueue(&steps, createXY(LEFT, 0));
            }
        }
        //printf("front: x:%d y:%d\n",trace->front->data->x, trace->front->data->y);
        /*if(steps == NULL)
            printf("NO SUCESS ALLOCATE STEPS\n");*/
        //printf("sx: %d\n", steps->rear->data->x);
        //printf("trace: x:%d y:%d\n", trace->data->x, trace->data->y);
        //printf("\n");
        trace = trace->front;
    }

    //count elements
    int one_time_count = 0;
    struct Queue *ptr = steps;
    while (ptr != NULL) {
        one_time_count++;
        ptr = ptr->next;
    }
    (*steps_count) += one_time_count;
    //printf("count: %d\n", one_time_count);
    for (int i = 1; i <= one_time_count; i++) {
        //debug
        //printf("sx%d: %d\n", i, steps->data->x);
        steps_recorded[(*steps_count) - i] = steps->data->x;
        steps = steps->next;
        //debug
    }
    /*
    for(int i = 0; i < (*steps_count); i++){
        printf("step_record[%d]:%d\n", i, steps_recorded[i]);
    }*/
}

void follow_affter(int *sec_x, int *sec_y, int *steps_recorded, int steps_count) {
    //after bfs, the second ball have to move with first ball
    for (int i = 0; i < steps_count; i++) {
        if (steps_recorded[i] == UP && maze[(*sec_x)][(*sec_y) + 1] != Obstacle)
            (*sec_y)++;
        if (steps_recorded[i] == RIGHT && maze[(*sec_x) + 1][(*sec_y)] != Obstacle)
            (*sec_x)++;
        if (steps_recorded[i] == DOWN && maze[(*sec_x)][(*sec_y) - 1] != Obstacle)
            (*sec_y)--;
        if (steps_recorded[i] == LEFT && maze[(*sec_x) - 1][(*sec_y)] != Obstacle)
            (*sec_x)--;
        //printf("sec_x: %d, sec_y: %d\n", (*sec_x), (*sec_y));
    }
}

int main(){
    //declaration
    int steps_recorded1[100000], steps_count1 = 0;
    int steps_recorded2[100000], steps_count2 = 0;
    int isFilled_one = 0, isFilled_two = 0;

    //input
    scanf("%d", &maze_size);
    for (int j = maze_size - 1; j >= 0; j--) { //start from left
        for (int i = 0; i < maze_size; i++) { //south to north
            scanf("%d", &maze[i][j]);
        }
    }
    /*
    for (int j = maze_size - 1; j >= 0; j--) { //start from left
        for (int i = 0; i < maze_size; i++) { //south to north
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    scanf("%d %d %d %d %d %d %d %d", &ball_x, &ball_y, &ball2_x, &ball2_y, &hole_x, &hole_y, &hole2_x, &hole2_y);

     //backup the value
    int bakeup_x = ball_x, bakeup_y = ball_y;
    int bakeup2_x = ball2_x, bakeup2_y = ball2_y;

    bfs(ball_x, ball_y, steps_recorded1, &steps_count1, &isFilled_one, &isFilled_two);
    follow_affter(&bakeup2_x, &bakeup2_y, steps_recorded1, steps_count1);
    bfs(bakeup2_x, bakeup2_y, steps_recorded1, &steps_count1, &isFilled_one, &isFilled_two);

    //printf("\nROUND2\n");
    //try different way to see if steps more little
    isFilled_one = 0;
    isFilled_two = 0;
    bfs(ball2_x, ball2_y, steps_recorded2, &steps_count2, &isFilled_one, &isFilled_two);
    follow_affter(&bakeup_x, &bakeup_y, steps_recorded2, steps_count2);
    bfs(bakeup_x, bakeup_y, steps_recorded2, &steps_count2, &isFilled_one, &isFilled_two);

    // output the step which smaller
    if (steps_count1 < steps_count2) {
        for (int i = 0 ; i < steps_count1; i++)
            printf("%d", steps_recorded1[i]);
    } else {
        for (int i = 0 ; i < steps_count2; i++)
            printf("%d", steps_recorded2[i]);
    }

    return 0;
}
