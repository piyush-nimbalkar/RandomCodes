void draw_circle(int x0, int y0, int radius)
{
    int x = 0;
    int y = radius;
    int error = 1 - radius;
    int two_x, two_y;

    while(y >= x) {
        // can memoize these additions, for eg (x0+x), (y0+y)
        // but not sure, coz these are used only twice every time
        putpixel(x0 + x, y0 + y);
        putpixel(x0 + x, y0 - y);
        putpixel(x0 - x, y0 + y);
        putpixel(x0 - x, y0 - y);
        putpixel(x0 + y, y0 + x);
        putpixel(x0 + y, y0 - x);
        putpixel(x0 - y, y0 + x);
        putpixel(x0 - y, y0 - x);
        x++;
        two_x = x << 1;
        if (error < 0)
            // error += 2 * x + 3;
            error += two_x + 3;
        else {
            y--;
            // error += 2 * (x - y) + 5;
            error += two_x - two_y + 5;
        }
    }
}
