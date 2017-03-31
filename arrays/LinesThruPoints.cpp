#include "Arrays.h"

struct Point {
    int x, y;
    Point(int x_, int y_) : x(x_), y(y_) {}
};

struct Line {
    #define TOLERANCE 0.0001
    double slope;     // DBL_MAX if vertical
    double intercept; // x-coord if vertical
    Line(double slope_, double intercept_) :
        slope(slope_), intercept(intercept_) {}
    bool operator==(const Line& rhs) const {
        if (slope == DBL_MAX) {
            return this->intercept == rhs.intercept;
        } else {
            return abs(this->slope - rhs.slope) < TOLERANCE
                && abs(this->intercept - rhs.intercept) < TOLERANCE;
        }
    }
};

namespace std {
    template<> struct hash<Line> {
        size_t operator()(const Line& line) const {
            size_t h1 = hash<double>()(line.slope);
            size_t h2 = hash<double>()(line.intercept);
            return h1 ^ (h2 << 1);
        }
    };
}

/**
 * Given a list of 2D points, find the number of lines
 * that can be drawn through at least three points.
 */
class LinesThruPoints {
private:
    vector<Point> points_;
    vector<Line> linesThruPairs_;
    unordered_map<Line, int> lineTally_;
    int count_;

public:
    LinesThruPoints(const vector<Point>& points) :
        points_(points),
        count_(0)
    {}

    int solve() {
        findLinesThruPairs();
        tallyLinesThruPairs();
        countRepeatedLinesThruPairs();
        return count_;
    }

private:
    void findLinesThruPairs() {
        for (size_t i = 0; i < points_.size(); ++i) {
            for (size_t j = i + 1; j < points_.size(); ++j) {
                int x1 = points_[i].x;
                int y1 = points_[i].y;
                int x2 = points_[j].x;
                int y2 = points_[j].y;
                double slope, intercept;
                if (x1 == x2) {
                    slope = DBL_MAX;
                    intercept = x1;
                } else {
                    slope = double(y2 - y1) / double(x2 - x1);
                    intercept = y1 - (slope * x1);
                }
                linesThruPairs_.push_back(Line(slope, intercept));
            }
        }
    }

    void tallyLinesThruPairs() {
        for (auto& line : linesThruPairs_) {
            ++lineTally_[line];
        }
    }

    void countRepeatedLinesThruPairs() {
        for (auto& entry : lineTally_) {
            if (entry.second > 1) {
                ++count_;
            }
        }
    }
};

void testLinesThruPoints() {
    cout << endl;
    cout << "Test linesThruPoints():" << endl;
    cout << "=======================" << endl;

    vector<Point> points;

    points.push_back(Point(-1, -1));
    points.push_back(Point( 0, -1));
    points.push_back(Point( 1, -1));

    points.push_back(Point(-1,  0));
    points.push_back(Point( 0,  0));
    points.push_back(Point( 1,  0));

    points.push_back(Point(-1,  1));
    points.push_back(Point( 0,  1));
    points.push_back(Point( 1,  1));

    cout << "             y                 " << endl;
    cout << "             |                 " << endl;
    cout << "             |                 " << endl;
    cout << "             |                 " << endl;
    cout << "             |                 " << endl;
    cout << " (-1, 1) *---*---* (1, 1)      " << endl;
    cout << "         | \\ | / |            " << endl;
    cout << "---------*---*---*--------- x  " << endl;
    cout << "         | / | \\ |            " << endl;
    cout << "(-1, -1) *---*---* (1, -1)     " << endl;
    cout << "             |                 " << endl;
    cout << "             |                 " << endl;
    cout << "             |                 " << endl;
    cout << "             |                 " << endl;
    cout << endl;

    cout << "Points = " << endl;
    for (auto& point : points) {
        cout << "\t(" << point.x << ", " << point.y << ")" << endl;
    }
    cout << endl;

    LinesThruPoints linesThruPoints(points);
    int numLines = linesThruPoints.solve();

    cout << "Number of lines = " << numLines << endl;
}
