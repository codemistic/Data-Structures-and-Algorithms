//Maze Game
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int l, w;

struct memory
{
    int pr[2], sk[2];
    char dir;
    struct memory *next;
};

struct head
{
    int cnt;
    struct memory *start;
    struct memory *end;
};

typedef struct memory memory;
typedef struct head head;

void record(head *h, int ply[2], int snk[2], char pr_mv)
{
    memory *node = (memory *)malloc(sizeof(memory));
    if (node == NULL)
        return;
    node->pr[0] = ply[0];
    node->pr[1] = ply[1];
    node->sk[0] = snk[0];
    node->sk[1] = snk[1];
    node->dir = pr_mv;
    node->next = NULL;
    h->cnt++;
    if (h->start == NULL)
    {
        h->start = h->end = node;
        return;
    }
    h->end->next = node;
    h->end = node;
}

char undo(head *h, int ply[2], int snk[2])
{
    if (h->start == NULL && h->cnt <= 1)
        return '0';
    char ch = h->end->dir;
    ply[0] = h->end->pr[0];
    ply[1] = h->end->pr[1];
    snk[0] = h->end->sk[0];
    snk[1] = h->end->sk[1];
    memory *temp = h->end;
    memory *node = h->start;
    while (node->next != NULL && node->next->next != NULL)
        node = node->next;
    if (node->next == NULL)
        h->start = h->end = NULL;
    else
    {
        node->next = NULL;
        h->end = node;
    }
    h->cnt--;
    free(temp);
    return ch;
}

void del_memory(head *h)
{
    memory *temp = h->start;
    while (h->start != NULL)
    {
        h->start = h->start->next;
        free(temp);
        temp = h->start;
    }
    if (h->start == NULL)
        h->end == NULL;
}

void print_maze(char maze[l][w])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < w; j++)
            printf("%c", maze[i][j]);
        printf("\n");
    }
}

int check_status(int ply[2], int snk[2])
{
    if (ply[0] == snk[0] && ply[1] == snk[1])
        return 1;
    return 0;
}

void move_snake(int snk[2], int ply[2], char maze[l][w])
{
    int x = snk[0];
    int y = snk[1];

    maze[x][y] = ' ';
    int num = 0;
    int dist = 1e8;

    // If chaser move up
    if (maze[x - 1][y] != 'O' && maze[x - 1][y] != 'X' && x - 1 > 0)
    {
        int diff = abs(ply[0] - (x - 1)) + abs(ply[1] - (y));
        if (diff < dist)
        {
            dist = diff;
            num = 1;
        }
    }

    // If chaser move down
    if (maze[x + 1][y] != 'O' && maze[x + 1][y] != 'X' && x + 1 < l - 1)
    {
        int diff = abs(ply[0] - (x + 1)) + abs(ply[1] - (y));
        if (diff < dist)
        {
            dist = diff;
            num = 2;
        }
    }

    // If chaser move right
    if (maze[x][y + 1] != 'O' && maze[x][y + 1] != 'X' && y + 1 < w - 1)
    {
        int diff = abs(ply[0] - x) + abs(ply[1] - (y + 1));
        if (diff < dist)
        {
            dist = diff;
            num = 3;
        }
    }

    // If chaser move left
    if (maze[x][y - 1] != 'O' && maze[x][y - 1] != 'X' && y - 1 > 0)
    {
        int diff = abs(ply[0] - x) + abs(ply[1] - (y - 1));
        if (diff < dist)
        {
            dist = diff;
            num = 4;
        }
    }

    if (num == 1)
    {
        snk[0]--;
    }
    else if (num == 2)
    {
        snk[0]++;
    }
    else if (num == 3)
    {
        snk[1]++;
    }
    else
    {
        snk[1]--;
    }

    maze[snk[0]][snk[1]] = '~';
}

void play(char maze[l][w], int snk[2], int ply[2], int dst[2])
{
    char ch;
    int win = 0, lose = 0;
    head mem;
    mem.cnt = 0;
    mem.start = mem.end = NULL;
    record(&mem, ply, snk, '^');
    while (!win && !lose)
    {
        system("cls");
        printf("RULES OF GAME\n");
        printf("-------------\n");
        printf("Press \'w\' to move up\n");
        printf("Press \'a\' to move left\n");
        printf("Press \'s\' to move down\n");
        printf("Press \'d\' to move right\n");
        printf("Press \'u\' to undo\n");
        printf("Press \'q\' to quit\n\n");
        print_maze(maze);
        printf("\n");
        fflush(stdin);
        ch = _getch();
        switch (ch)
        {
        case 'w':
        {
            if (maze[ply[0] - 1][ply[1]] == ' ' || maze[ply[0] - 1][ply[1]] == 'X')
            {
                if (maze[ply[0] - 1][ply[1]] == 'X')
                    win = 1;
                maze[ply[0]][ply[1]] = ' ';
                maze[ply[0] - 1][ply[1]] = '^';
                ply[0]--;
                record(&mem, ply, snk, '^');
            }
            break;
        }
        case 'a':
        {
            if (maze[ply[0]][ply[1] - 1] == ' ' || maze[ply[0]][ply[1] - 1] == 'X')
            {
                if (maze[ply[0]][ply[1] - 1] == 'X')
                    win = 1;
                maze[ply[0]][ply[1]] = ' ';
                maze[ply[0]][ply[1] - 1] = '<';
                ply[1]--;
                record(&mem, ply, snk, '<');
            }
            break;
        }
        case 's':
        {
            if (maze[ply[0] + 1][ply[1]] == ' ' || maze[ply[0] + 1][ply[1]] == 'X')
            {
                if (maze[ply[0] + 1][ply[1]] == 'X')
                    win = 1;
                maze[ply[0]][ply[1]] = ' ';
                maze[ply[0] + 1][ply[1]] = 'v';
                ply[0]++;
                record(&mem, ply, snk, 'v');
            }
            break;
        }
        case 'd':
        {
            if (maze[ply[0]][ply[1] + 1] == ' ' || maze[ply[0]][ply[1] + 1] == 'X')
            {
                if (maze[ply[0]][ply[1] + 1] == 'X')
                    win = 1;
                maze[ply[0]][ply[1]] = ' ';
                maze[ply[0]][ply[1] + 1] = '>';
                ply[1]++;
                record(&mem, ply, snk, '>');
            }
            break;
        }
        case 'u':
        {
            int px, py, sx, sy;
            px = ply[0];
            py = ply[1];
            sx = snk[0];
            sy = snk[1];
            char mz_val = undo(&mem, ply, snk);
            if (mz_val != '0')
            {
                maze[px][py] = ' ';
                maze[ply[0]][ply[1]] = mz_val;
                maze[sx][sy] = ' ';
                maze[snk[0]][snk[1]] = '~';
            }
            break;
        }
        case 'q':
        {
            printf("Thank You for Playing...\n");
            del_memory(&mem);
            exit(0);
        }
        default:
        {
            printf("Invalid Choice!!!");
            system("pause");
            break;
        }
        }
        if (ch != 'u')
            move_snake(snk, ply, maze);
        if (check_status(ply, snk))
            lose = 1;
    }
    system("cls");
    print_maze(maze);
    del_memory(&mem);
    if (win)
        printf("\nYou Win... :)\n");
    else
        printf("\nYou Lose... :(\n");
}

void start_game(char *file_name)
{
    //Creating Maze by Reading File
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("%s file not found!!!\n");
        return;
    }
    int snk[2], ply[2], dst[2];
    int x;
    fscanf(fp, "%d %d %d", &x, &l, &w);
    int obs[x - 3][2], n = 0;
    for (int i = 0; i < x; i++)
    {
        int t1, t2, t3;
        fscanf(fp, "%d %d %d", &t1, &t2, &t3);
        if (t3 == 0)
        {
            ply[0] = t1;
            ply[1] = t2;
        }
        else if (t3 == 1)
        {
            snk[0] = t1;
            snk[1] = t2;
        }
        else if (t3 == 2)
        {
            dst[0] = t1;
            dst[1] = t2;
        }
        else
        {
            obs[n][0] = t1;
            obs[n++][1] = t2;
        }
    }
    fclose(fp);

    //Preparing the Maze for the game
    char maze[l][w];
    maze[0][0] = maze[0][w - 1] = maze[l - 1][0] = maze[l - 1][w - 1] = '#';
    for (int i = 1; i < w - 1; i++)
        maze[0][i] = maze[l - 1][i] = '-';
    for (int i = 1; i < l - 1; i++)
        maze[i][0] = maze[i][w - 1] = '|';
    for (int i = 1; i < l - 1; i++)
        for (int j = 1; j < w - 1; j++)
            maze[i][j] = ' ';
    // positioning obstacles
    for (int i = 0; i < n; i++)
        maze[obs[i][0]][obs[i][1]] = 'O';
    maze[dst[0]][dst[1]] = 'X'; //setting final position
    maze[snk[0]][snk[1]] = '~'; //setting sanke position
    maze[ply[0]][ply[1]] = '^'; //setting player position

    play(maze, snk, ply, dst);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid number of Arguments passed!!!\n");
        exit(1);
    }
    start_game(argv[argc - 1]);
    return 0;
}
