#ifndef GLOBAL_Map
#define GLOBAL_Map
#include "../models/random.h"

class Map
{
public:
    int level = 0;
    int a[10][10];
    void init(int level);
    bool move(int name);
    int *move_array;
    bool *move_array_true;
    int move_point = 0;

    bool isBot = false;
    int m = 0;
    int n = 0;
    void botting();
    void move_reverse(int name);
    bool isWin();

private:
};
void Map::init(int level)
{
    this->level = level;
    this->move_point = this->level * NUMBER;
    this->move_array = new int[this->level * NUMBER];
    this->move_array_true = new bool[this->level * NUMBER];

    Random *random = new Random();
    int arr[this->level * this->level];
    for (int i = 0; i < this->level * NUMBER; i++)
    {
        move_array[i] = i % 4 + 1;
    }
    random->generate(move_array, this->level * NUMBER);

    for (int i = 0; i < this->level * this->level; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < this->level; i++)
    {
        for (int j = 0; j < this->level; j++)
        {
            a[i][j] = arr[i * level + j];
        }
    }

    a[this->level - 1][this->level - 1] = 1000;
    this->m = this->level - 1;
    this->n = this->level - 1;

    for (int i = 0; i < this->level * NUMBER; i++)
    {
        move_array_true[i] = this->move(this->move_array[i]);
    }
}
bool Map::move(int name)
{
    bool moved = false;
    if (this->m != 0 && name == MOVE_DOWN)
    {
        int temp = this->a[this->m - 1][this->n];
        this->a[this->m - 1][this->n] = this->a[this->m][this->n];
        this->a[this->m][this->n] = temp;
        this->m = this->m - 1;
        moved = true;
    }

    if (this->m != this->level - 1 && name == MOVE_UP)
    {
        int temp = this->a[this->m + 1][this->n];
        this->a[this->m + 1][this->n] = this->a[this->m][this->n];
        this->a[this->m][this->n] = temp;
        this->m = this->m + 1;
        moved = true;
    }

    if (this->n != this->level - 1 && name == MOVE_LEFT)
    {
        int temp = this->a[this->m][this->n + 1];
        this->a[this->m][this->n + 1] = this->a[this->m][this->n];
        this->a[this->m][this->n] = temp;
        this->n = this->n + 1;
        moved = true;
    }
    if (this->n != 0 && name == MOVE_RIGHT)
    {
        int temp = this->a[this->m][this->n - 1];
        this->a[this->m][this->n - 1] = this->a[this->m][this->n];
        this->a[this->m][this->n] = temp;
        this->n = this->n - 1;
        moved = true;
    }
    return moved;
}
void Map::botting()
{
    if (this->move_point >= 0 && this->isBot == true)
    {
        this->move_point--;
        if (this->move_array_true[this->move_point])
            this->move_reverse(this->move_array[this->move_point]);
    }
}
void Map::move_reverse(int name)
{
    if (this->m != this->level - 1 && name == MOVE_DOWN)
    {
        this->move(MOVE_UP);
    }
    if (this->m != 0 && name == MOVE_UP)
    {
        this->move(MOVE_DOWN);
    }
    if (this->n != 0 && name == MOVE_LEFT)
    {
        this->move(MOVE_RIGHT);
    }
    if (this->n != this->level - 1 && name == MOVE_RIGHT)
    {
        this->move(MOVE_LEFT);
    }
}
bool Map::isWin()
{
    int z = 0;
    for (int i = 0; i < this->level; i++)
    {
        for (int j = 0; j < this->level; j++)
        {
            if (i < this->level - 1 || j < this->level - 1)
            {

                if (this->a[i][j] != z)
                    return false;
                z++;
            }
        }
    }
    return true;
}
#endif
