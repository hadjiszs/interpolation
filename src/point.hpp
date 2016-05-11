#ifndef _POINT_
#define _POINT_

#include <array>
#include <cstdlib> // for std::size_t
#include <initializer_list>
#include <iostream>
#include <ostream>

template<uint8_t N,
         typename Corps>
class Point;

//
// Surcharge d'operateurs
//

template<uint8_t N,
         typename Corps>
bool operator==(const Point<N, Corps> &, const Point<N, Corps> &);

template<uint8_t N,
         typename Corps>
bool operator!=(const Point<N, Corps> &, const Point<N, Corps> &);

template<uint8_t N,
         typename Corps>
Point<N, Corps> operator-(const Point<N, Corps> &, const Point<N, Corps> &);

template<uint8_t N,
         typename Corps>
std::ostream& operator<<(std::ostream &, const Point<N, Corps> &);

//
// Template class Point
//

template<uint8_t N,
         typename Corps>
class Point {
public:
    using PointNC = Point<N, Corps>;

private:
    std::array<Corps, N> _data;
    double _value;

public:
    Point();
    Point(std::initializer_list<Corps> l);

    void   set_value(double);
    double get_value() const;

    Corps&         operator[](std::size_t);
    PointNC&       operator-=(const PointNC &);

    friend bool           operator== <>(const PointNC &, const PointNC &);
    friend bool           operator!= <>(const PointNC &, const PointNC &);
    friend PointNC        operator-  <>(const PointNC &, const PointNC &);
    friend std::ostream & operator<< <>(std::ostream &, const PointNC & p);
};

//
// Template implementation
//

#include "point.tcc"

#endif