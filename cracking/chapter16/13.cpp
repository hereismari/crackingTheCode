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

    const bool operator <(const Point &other_point) {
        if(x < other_point.x) return true;
        else if(y <= other_point.y) return true;
        else return false;
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

float get_mean(float x, float y) {
    // x < y
    return x + (y-x)/2.0;
}

struct Square {

    Point p1, p2, medium_p;
    Square(Point p1, Point p2) {
        this->p1 = p1 < p2 ? p1: p2;
        this->p2 = p1 < p2 ? p2: p1;
        this->medium_p = Point(get_mean(p1.x, p2.x), get_mean(p1.y, p2.y));
    }

    Line bisect_squares(const Square &other_sqr) {

        printf("(%f, %f), (%f, %f)\n", medium_p.x, medium_p.y, other_sqr.medium_p.x, other_sqr.medium_p.y);

        // if they are parallel in x
        if(medium_p.y == other_sqr.medium_p.y) {
            return Line(Point(p1.x, medium_p.y), Point(other_sqr.p2.x, other_sqr.medium_p.y)); 
        }
        // if they are prallel in y
        else if(medium_p.x == other_sqr.medium_p.x) {
            return Line(Point(medium_p.x, p1.y), Point(other_sqr.medium_p.x, p2.y));
        }
        else {
            
            float slope = (medium_p.y - other_sqr.medium_p.y)/(medium_p.x - other_sqr.medium_p.x);
            float b = medium_p.y - slope * medium_p.x;

            printf("%f %f\n", slope, b);
            Point left = Point(p1.x, slope * p1.x + b);        
            Point right = Point(other_sqr.p2.x, slope * other_sqr.p2.x + b);
            return Line(left, right);        
        }
    }
};

Square get_square() {

    float x1, y1, x2, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    
    Point point1 = Point(x1, y1), point2 = Point(x2, y2);
    return Square(point1, point2);
}

int main() {

   Square sqr1 = get_square(), sqr2 = get_square();

   // sqr1.x < sqr2, if equal then sqr1.y < sqr2.y
   Line l = sqr1.bisect_squares(sqr2);
   
   printf("y = %fx + %f\n", l.a, l.b);
   printf("(%f, %f) (%f, %f)\n", l.p1.x, l.p1.y, l.p2.x, l.p2.y); 

    return 0;
}
