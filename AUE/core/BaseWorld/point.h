//
// Created by halone on 13.07.2023.
//

#ifndef AUE_POINT_H
#define AUE_POINT_H
#include "vector"


using intl = long double;
namespace aue {
    class Point2D {
    private:
        intl x, y;
    public:
        Point2D();

        Point2D(intl, intl);

        void setX(const intl _x){
            this->x = _x;
        };

        void setY(const intl);

        [[nodiscard]] const intl getX() const;

        [[nodiscard]] const intl getY() const;

        std::vector<intl> getArrPos() const;

        bool operator==(const Point2D &other) const;

        bool operator>(const Point2D &other) const;

        bool operator<(const Point2D &other) const;

        bool operator<=(const Point2D &other) const;

        bool operator>=(const Point2D &other) const;

        Point2D operator+(const Point2D &other) const;

        [[nodiscard]] size_t hash() const;

        [[nodiscard]] long double get_sqr_dist(const Point2D& other) const;
    };
}
#endif //AUE_POINT_H
