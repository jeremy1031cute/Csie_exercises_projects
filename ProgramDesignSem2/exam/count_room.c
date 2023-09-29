#include <stdio.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int visited[MAX_ROWS][MAX_COLS]; //record visited floor

int isValidFloorCell(int row, int col, int n, int m, char building[][MAX_COLS]) {
    if (row >= 0 && row < n && col >= 0 && col < m && building[row][col] == '.') {
        return 1;
    }
    return 0;
}

void dfs(int row, int col, int n, int m, char building[][MAX_COLS]) {
    visited[row][col] = 1;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        if (isValidFloorCell(newRow, newCol, n, m, building) && visited[newRow][newCol] != 1) {
            dfs(newRow, newCol, n, m, building);
        }
    }
}

int countRooms(int n, int m, char building[][MAX_COLS]) {
    int roomCount = 0;

    //inalization
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (building[i][j] == '.' && visited[i][j] != 1) {
                roomCount++;
                dfs(i, j, n, m, building); //find the connected floor and sign it
            }
        }
    }

    return roomCount;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char building[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < n; i++) {
        scanf("%s", building[i]);
    }

    int roomCount = countRooms(n, m, building);

    printf("%d", roomCount);

    return 0;
}
