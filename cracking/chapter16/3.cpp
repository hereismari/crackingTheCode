#include <stdio.h>
#include<utility>
#include<algorithm>

using namespace std;

struct Point {

    float x, y;
    
    Point(float x=0, float y=0) {
        this->x = x;
        this->y = y;
    }
};


struct Line {

    Point p1, p2;
    float a, b;

    Line(Point p1, Point p2) {
        this->p1 = p1;
        this->p2 = p2;
    
        if(p1.x - p2.x == 0) a = 0;
        else a = (p1.y - p2.y)/(p1.x - p2.x);
   
        b = p1.y - p1.x * a; 
    }

    bool in_line(Point p) {
        float min_x = p1.x < p2.x ? p1.x : p2.x;
        float max_x = p1.x > p2.x ? p1.x : p2.x;
        float min_y = p1.y < p2.y ? p1.y : p2.y;
        float max_y = p1.y > p2.y ? p1.y : p2.y;
        if(p.x < min_x || p.x > max_x) return false;
        if(p.y < min_y || p.y > max_y) return false;
    }

    pair<bool, Point> get_intersection(Line &other_line) {
        if(this->a == other_line.a) {
            return make_pair(false, Point());
        }
        else {
            float x, y;
            x = (this->b - other_line.b) / (other_line.a - this->a);
            y = this->a * x + this->b;

            Point p = Point(x, y);
            bool res = true;
            res &= this->in_line(p);
            res &= other_line.in_line(p);

            return make_pair(res, p);
        }
    }
};

Line get_line() {

    float x1, y1, x2, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    
    Point point1 = Point(x1, y1), point2 = Point(x2, y2);
    return Line(point1, point2);
}

int main() {

    Line line1 = get_line(), line2 = get_line();

   pair<bool, Point> i = line1.get_intersection(line2);
    
    if(i.first) {
        printf("%f %f\n", i.second.x, i.second.y);
    }
    else {
        printf("No intersection\n");
    }
    
    return 0;
}
