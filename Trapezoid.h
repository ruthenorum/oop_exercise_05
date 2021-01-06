#ifndef OOP5_TRAPEZOID_H
#define OOP5_TRAPEZOID_H

#include <utility>
#include <cmath>
#include <vector>


const int EDGES_COUNT = 4;
template <class T>
class Trapezoid {
public:
    using vertex_t = std::pair<T,T>;
    vertex_t a,b,c,d;
    std::vector<std::pair<double,double>> edges;
    double get_square() const;
    explicit Trapezoid(vertex_t& a,vertex_t& b,vertex_t& c,vertex_t& d);
    explicit Trapezoid(std::vector<std::pair<T,T>> _vec);
};

template <class T>
std::ostream& operator << (std::ostream& out, const Trapezoid<T>& tr);

#include "Trapezoid.cpp"
#endif //OOP5_TRAPEZOID_H
