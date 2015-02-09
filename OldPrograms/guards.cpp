#include <iostream>
#include <queue>

using namespace std;

const int MAX = 10;

class Room
{
    int x, y;
    int distance, visit;

public:
    Room() { visit = distance = 0; }
    Room(int i, int j) { x = i; y = j; visit = distance = 0; }
    void set_distance(int dist) { distance = dist; }
    int get_distance() { return distance; }
    int is_guard() { return !distance; }
    int get_x() { return x; }
    int get_y() { return y; }
    int visited() { return visit; }
    void mark_visited(int value) { visit = value; }
};

class Building
{
    int length, width;
    Room rooms[MAX][MAX];

public:
    Building() { }
    Building(int, int);
    void set_guard(int, int);
    int closest_guard();
    void minimize_distance(int, int);
    void display();
};

Building :: Building(int l, int w)
{
    length = l;
    width = w;
    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++) {
            rooms[i][j] = Room(i, j);
            rooms[i][j].set_distance(99);
        }
}

void Building :: display()
{
    cout << endl;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            cout.width(3);
            cout << rooms[i][j].get_distance();
        }
        cout << endl;
    }
    cout << endl;
}

void Building :: set_guard(int i, int j)
{
    rooms[i][j].set_distance(0);
}

int Building :: closest_guard()
{
    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++)
            if (rooms[i][j].is_guard())
                minimize_distance(i, j);
}


void Building :: minimize_distance(int x, int y)
{
    int current_x, current_y;
    Room current;
    Room guard = rooms[x][y];
    Room delimiter = Room(9999, 9999);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (rooms[i][j].is_guard())
                continue;

            int desired_x = i,  desired_y = j;
            int min_dist = 0;

            queue<Room> q;
            q.push(guard);
            q.push(delimiter);

            while(!q.empty()) {
                current = q.front();
                q.pop();

                if (current.get_x() == delimiter.get_x()) {
                    min_dist++;
                    q.push(delimiter);
                    continue;
                }

                current_x = current.get_x();
                current_y = current.get_y();
                rooms[current_x][current_y].mark_visited(1);

                if (current_x == desired_x && current_y == desired_y) {
                    if (rooms[current_x][current_y].get_distance() > min_dist)
                        rooms[current_x][current_y].set_distance(min_dist);
                    break;
                }

                if (current_x + 1 < length && !rooms[current_x + 1][current_y].visited())
                    q.push(rooms[current_x + 1][current_y]);
                if (current_x - 1 >= 0 && !rooms[current_x - 1][current_y].visited())
                    q.push(rooms[current_x - 1][current_y]);
                if (current_y + 1 < width && !rooms[current_x][current_y + 1].visited())
                    q.push(rooms[current_x][current_y + 1]);
                if (current_y - 1 >= 0 && !rooms[current_x][current_y - 1].visited())
                    q.push(rooms[current_x][current_y - 1]);
            }

            for (int p = 0; p < length; p++)
                for (int q = 0; q < width; q++)
                    rooms[p][q].mark_visited(0);
        }
    }
}


int main(int argc, char *argv[])
{
    Building taj(10, 10);
    taj.set_guard(0, 0);
    taj.set_guard(0, 1);
    taj.set_guard(1, 2);
    taj.set_guard(3, 3);
    taj.closest_guard();
    taj.display();
    return 0;
}
