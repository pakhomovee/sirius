#include <iostream>
#include <vector>
/*
Shows difference between emplace_back (construct in-place from args)
and push_back (push an existing object or temporary). Prefer emplace_back
for non-trivial types to avoid an extra move/copy.
*/
using namespace std;

struct Point {
  int x;
  int y;
  explicit Point(int x_, int y_) : x(x_), y(y_) {}
};

int main() {
  vector<Point> pts;

  // Constructs in-place (no temporary)
  pts.emplace_back(1, 2);

  Point p(3, 4);
  // Pushes an existing object
  pts.push_back(p);

  // Pushes a temporary (may move/construct)
  pts.push_back(Point(5, 6));

  cout << pts.size() << '\n';
  return 0;
}


