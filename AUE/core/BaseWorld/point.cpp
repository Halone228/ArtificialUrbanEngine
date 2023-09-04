//
// Created by halone on 13.07.2023.
//

#include "point.h"
using namespace aue;
Point2D::Point2D() : x(0), y(0) {}
Point2D::Point2D(intl _x, intl _y) : x(_x), y(_y) {}
void Point2D::setX(intl _x) {
    x = _x;
}
void Point2D::setY(intl _y) {
    y = _y;
}

intl Point2D::getX() const {
    return x;
}

intl Point2D::getY() const {
    return y;
}

std::vector<intl> Point2D::getArrPos() {
    return {x,y};
}
bool Point2D::operator==(const Point2D &other) const {
    return this->getX() == other.getX() && this->getY() == other.getY();
}
bool Point2D::operator>(const Point2D &other) const {
    return !(this->operator==(other)) && (this->getX() > other.getX() || this->getY() > other.getY());
}
bool Point2D::operator<(const Point2D &other) const {
    return !this->operator>(other);
}
bool Point2D::operator<=(const Point2D &other) const {
    return this->operator==(other) || this->operator<(other);
}
bool Point2D::operator>=(const Point2D &other) const {
    return this->operator==(other) || this->operator>(other);
}

long double Point2D::get_sqr_dist(const aue::Point2D &other) const {
    long double x = this->getX() - other.getX();
    long double y = this->getY() - other.getY();
    return x*x + y*y;
}

Point2D Point2D::operator+(const Point2D &other) const {
    return {this->getX()+other.getX(), this->getY()+other.getY()};
}
