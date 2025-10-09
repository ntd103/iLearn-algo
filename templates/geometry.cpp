// ========================================
// Geometry Library
// ========================================

#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

// ============ POINT ============
struct Point {
    double x, y;

    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double t) const { return Point(x * t, y * t); }
    Point operator/(double t) const { return Point(x / t, y / t); }

    double dot(const Point &p) const { return x * p.x + y * p.y; }
    double cross(const Point &p) const { return x * p.y - y * p.x; }
    double norm() const { return x * x + y * y; }
    double abs() const { return sqrt(norm()); }

    bool operator<(const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator==(const Point &p) const {
        return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
    }
};

// ============ DISTANCE ============
double distance(const Point &p1, const Point &p2) {
    return (p1 - p2).abs();
}

// ============ CCW (Counter-Clockwise) ============
// Returns: +1 if counter-clockwise, -1 if clockwise, 0 if collinear
int ccw(const Point &a, const Point &b, const Point &c) {
    double area = (b - a).cross(c - a);
    if (area > EPS)
        return 1; // Counter-clockwise
    if (area < -EPS)
        return -1; // Clockwise
    return 0;      // Collinear
}

// ============ LINE SEGMENT INTERSECTION ============
bool segments_intersect(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    int d1 = ccw(p3, p4, p1);
    int d2 = ccw(p3, p4, p2);
    int d3 = ccw(p1, p2, p3);
    int d4 = ccw(p1, p2, p4);

    if (d1 * d2 < 0 && d3 * d4 < 0)
        return true;

    // Check if endpoints lie on the other segment
    if (d1 == 0 && min(p3.x, p4.x) <= p1.x && p1.x <= max(p3.x, p4.x) &&
        min(p3.y, p4.y) <= p1.y && p1.y <= max(p3.y, p4.y))
        return true;
    if (d2 == 0 && min(p3.x, p4.x) <= p2.x && p2.x <= max(p3.x, p4.x) &&
        min(p3.y, p4.y) <= p2.y && p2.y <= max(p3.y, p4.y))
        return true;
    if (d3 == 0 && min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x) &&
        min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y))
        return true;
    if (d4 == 0 && min(p1.x, p2.x) <= p4.x && p4.x <= max(p1.x, p2.x) &&
        min(p1.y, p2.y) <= p4.y && p4.y <= max(p1.y, p2.y))
        return true;

    return false;
}

// ============ CONVEX HULL (ANDREW'S ALGORITHM) ============
// Time: O(n log n)
vector<Point> convex_hull(vector<Point> points) {
    int n = points.size();
    if (n <= 1)
        return points;

    sort(points.begin(), points.end());

    vector<Point> hull;

    // Build lower hull
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // Build upper hull
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lower_size && ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back(); // Remove duplicate point
    return hull;
}

// ============ POLYGON AREA ============
double polygon_area(const vector<Point> &polygon) {
    double area = 0;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        area += polygon[i].cross(polygon[(i + 1) % n]);
    }
    return abs(area) / 2.0;
}

// ============ POINT IN POLYGON ============
// Returns true if point p is inside polygon
bool point_in_polygon(const Point &p, const vector<Point> &polygon) {
    int n = polygon.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % n];

        if (a.y > b.y)
            swap(a, b);

        if (a.y <= p.y && p.y < b.y) {
            if ((b - a).cross(p - a) > EPS) {
                cnt++;
            }
        }
    }

    return cnt % 2 == 1;
}

// ============ CLOSEST PAIR OF POINTS ============
// Time: O(n log n)
double closest_pair_util(vector<Point> &points, int l, int r) {
    if (r - l <= 3) {
        double min_dist = 1e18;
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j < r; j++) {
                min_dist = min(min_dist, distance(points[i], points[j]));
            }
        }
        sort(points.begin() + l, points.begin() + r);
        return min_dist;
    }

    int mid = (l + r) / 2;
    double mid_x = points[mid].x;

    double d = min(closest_pair_util(points, l, mid), closest_pair_util(points, mid, r));

    vector<Point> strip;
    for (int i = l; i < r; i++) {
        if (abs(points[i].x - mid_x) < d) {
            strip.push_back(points[i]);
        }
    }

    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i + 1; j < (int)strip.size() && strip[j].y - strip[i].y < d; j++) {
            d = min(d, distance(strip[i], strip[j]));
        }
    }

    return d;
}

double closest_pair(vector<Point> points) {
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.x < b.x;
    });
    return closest_pair_util(points, 0, points.size());
}
