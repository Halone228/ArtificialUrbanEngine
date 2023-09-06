//
// Created by halone on 13.07.2023.
//

#include "point.h"
#include "boost/container_hash/hash.hpp"
using namespace aue;
Point2D::Point2D() : x(0), y(0) {}
Point2D::Point2D(intl _x, intl _y) : x(_x), y(_y) {}
void Point2D::setY(const intl _y) {
    this->y = _y;
}

const intl Point2D::getX() const {
    return x;
}

const intl Point2D::getY() const {
    return y;
}

std::vector<intl> Point2D::getArrPos() const{
    return {x,y};
}
bool Point2D::operator==(const Point2D &other) const {
    return (this->getX() == other.getX()) && (this->getY() == other.getY());
}
bool Point2D::operator>(const Point2D &other) const {
    return (this->getX() > other.getX()) || (!(this->operator==(other)) && this->getY() > other.getY());
}
bool Point2D::operator<(const Point2D &other) const {
    return !(this->operator==(other)) && !this->operator>(other);
}
bool Point2D::operator<=(const Point2D &other) const {
    return this->operator==(other) || this->operator<(other);
}
bool Point2D::operator>=(const Point2D &other) const {
    return this->operator==(other) || this->operator>(other);
}

long double Point2D::get_sqr_dist(const aue::Point2D& other) const {
    intl x_ = this->getX() - other.getX();
    intl y_ = this->getY() - other.getY();
    return x_*x_ + y_*y_;
}

Point2D Point2D::operator+(const Point2D &other) const {
    return {this->getX()+other.getX(), this->getY()+other.getY()};
}

size_t Point2D::hash() const {
    size_t seed1(0);
    boost::hash_combine(seed1, x);
    boost::hash_combine(seed1, y);
    return seed1;
}
