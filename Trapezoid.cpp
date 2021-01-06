#include "Trapezoid.h"

double get_distance(const std::pair<double,double>& one,const std::pair<double,double>& two){
    double x_diff = (two.first - one.first);
    double y_diff = (two.second - one.second);
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

template<class T>
double Trapezoid<T>::get_square() const{
    double less_base = get_distance(edges[1],edges[2]);
    double larger_base = get_distance(edges[0],edges[3]);
    int x1 = edges[0].first;
    int x2 = edges[3].first;
    int y1 = edges[0].second;
    int y2 = edges[3].second;
    int x0 = edges[1].first;
    int y0 = edges[1].second;
    double numerator = fabs((y2 - y1) * x0 - (x2 - x1)*y0 + x2*y1 - y2*x1);
    double denominator = sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
    double height = numerator / denominator;
    return 0.5 * (less_base + larger_base) * height;
}

template<class T>
Trapezoid<T>::Trapezoid(vertex_t& _a,vertex_t& _b,vertex_t& _c,vertex_t& _d) {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
    edges.resize(EDGES_COUNT);

    edges[0].first = static_cast<double>(a.first);
    edges[0].second = static_cast<double>(a.second);

    edges[1].first = static_cast<double>(b.first);
    edges[1].second = static_cast<double>(b.second);

    edges[2].first = static_cast<double>(c.first);
    edges[2].second = static_cast<double>(c.second);

    edges[3].first = static_cast<double>(d.first);
    edges[3].second = static_cast<double>(d.second);
}

template<class T>
Trapezoid<T>::Trapezoid(std::vector<std::pair<T, T>> _vec) {
    a = _vec[0];
    b = _vec[1];
    c = _vec[2];
    d = _vec[3];
    edges.resize(EDGES_COUNT);

    edges[0].first = static_cast<double>(a.first);
    edges[0].second = static_cast<double>(a.second);

    edges[1].first = static_cast<double>(b.first);
    edges[1].second = static_cast<double>(b.second);

    edges[2].first = static_cast<double>(c.first);
    edges[2].second = static_cast<double>(c.second);

    edges[3].first = static_cast<double>(d.first);
    edges[3].second = static_cast<double>(d.second);
}

std::ostream& operator << (std::ostream& out, const std::pair<double,double>& p){
    out << p.first << " " << p.second << std::endl;
    return out;
}

template <class T>
std::ostream &operator<<(std::ostream& out, const Trapezoid<T>& tr) {
    out << "begin of Trapezoid" << std::endl;
    for(size_t i = 0; i < EDGES_COUNT; i++){
        out << tr.edges[i];
    }
    out << "Square is: " << tr.get_square() << std::endl;
    out << "end of Trapezoid" << std::endl;
    return out;
}







