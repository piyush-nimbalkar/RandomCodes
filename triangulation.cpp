#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

class Point
{
    double x, y;
public:
    Point() { x = y = 0; }
    Point(double _x, double _y);
    friend double dist(const Point &a, const Point &b);
};

Point :: Point(double _x, double _y)
{
    x = _x;
    y = _y;
}

double dist(const Point &a, const Point &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}


double cost(Point points[], int i, int k, int j)
{
    return dist(points[i], points[k]) + dist(points[k], points[j]) + dist(points[i], points[j]);
}

double mtc(Point points[], int i, int j)
{
    if (j < i+2)
        return dist(points[i], points[j]);

    double min_cost = numeric_limits<double>::max();
    for (int k = i+1; k < j; k++)
        min_cost = min(min_cost, mtc(points, i, k) + mtc(points, k, j) + dist(points[i], points[j]));
    return min_cost;
}


double dp_mtc(Point points[], int size)
{
    int i, j, k;
    double min_cost;
    double **cost = new double*[size];

    for (i = 0; i < size; i++)
        cost[i] = new double[size];

    for (i = 1; i < size; i++)
        cost[i-1][i] = dist(points[i-1], points[i]);

    for (int len = 2; len < size; len++) {
        for (i = 0; i < size - len; i++) {
            j = i + len;
            min_cost = numeric_limits<double>::max();
            for (k = i+1; k < j; k++)
                min_cost = min(min_cost, cost[i][k] + cost[k][j] + dist(points[i], points[j]));
            cost[i][j] = min_cost;
        }
    }
    return cost[0][size-1];
}


int main(int argc, char *argv[])
{
    int size = 6;
    Point points[6];
    points[0] = Point(0, 0);
    points[1] = Point(1, 0);
    points[2] = Point(2, 1);
    points[3] = Point(1, 2);
    points[4] = Point(0, 2);
    points[5] = Point(-1, 1);

    cout << "\nMinimum Triangulation Cost: " << mtc(points, 0, size-1) << endl;
    cout << "\nMinimum Triangulation Cost using DP: " << dp_mtc(points, size) << endl << endl;

    return 0;
}
