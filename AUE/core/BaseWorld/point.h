//
// Created by halone on 13.07.2023.
//

#ifndef AUE_POINT_H
#define AUE_POINT_H
#include "vector"


typedef long long intl;
namespace aue {
    class Point2D {
    private:
        intl x, y;
    public:
        Point2D();

        Point2D(intl, intl);

        void setX(intl);

        void setY(intl);

        [[nodiscard]] intl getX() const;

        [[nodiscard]] intl getY() const;

        std::vector<intl> getArrPos();

        bool operator==(const Point2D &other) const;

        bool operator>(const Point2D &other) const;

        bool operator<(const Point2D &other) const;

        bool operator<=(const Point2D &other) const;

        bool operator>=(const Point2D &other) const;

        Point2D operator+(const Point2D &other) const;

        [[nodiscard]] long double get_sqr_dist(const Point2D&) const;
    };
}
#endif //AUE_POINT_H
