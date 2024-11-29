#include "cell.hpp"
std::istream& operator>>(std::istream& in, CellState & cell){
    int tmp ;
    in>> tmp;
    cell=(CellState)tmp;
    return in;
}
std::ostream& operator<<(std::ostream& out, const CellState& cell){
    out << (int) cell;
    return out;
}
