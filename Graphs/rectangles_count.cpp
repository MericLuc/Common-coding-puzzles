/*!
 * @brief : Write a funciton that takes in a list of Cartesian coordinates
 *          and returns the number of rectangles formed by these coordinates.
 * NB : We only care about horizontal and vertical rectangles (i.e. sides
 *      parellel to x or y axes. )
 */

#include <vector>
#include <unordered_map>
#include <string>

struct Point { 
    int x, y; 
    std::string toStr(void) const { return std::to_string(x) + std::to_string(y); }
};

bool isInUpperRight(const Point& p1, const Point& p2) {
    return p2.x > p1.x && p2.y > p1.y;
}

std::unordered_map<std::string, bool> getCoordsTable( std::vector<Point> coords ) {
    std::unordered_map<std::string, bool> cTable;
    for ( const auto& pt : coords )
        cTable.insert_or_assign(pt.toStr(), true);
    return cTable;
}

int getRectangleCount( const std::vector<Point>&                    coords,
                       const std::unordered_map<std::string, bool>& cTable ) {
    int res{0};
    for ( const auto& p1 : coords )
        for ( const auto& p2 : coords )
            if ( isInUpperRight(p1, p2) ) 
            {
                Point p3{p1.x, p2.y}, p4{p2.x, p1.y};
                auto upStr { p3.toStr() }, rStr{ p4.toStr() };
                if ( cTable.find(upStr) != std::end(cTable) &&
                     cTable.find(rStr ) != std::end(cTable) ) { ++res; }
            }
    return res;
}

// O(n^2) time | O(n) space - n : number of coordinates
int rectangleMania( std::vector<Point> coords ) {
    std::unordered_map< std::string, bool > cTable { getCoordsTable(coords) };
  return getRectangleCount(coords, cTable);
}
