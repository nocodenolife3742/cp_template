namespace cg {
    struct pt_d {
        double x, y;
        pt_d() : x(0), y(0) {}
        pt_d(double a, double b) : x(a), y(b) {}
    };

    struct pt {
        int x, y;

        pt() : x(0), y(0) {}
        pt(int a, int b) : x(a), y(b) {}

        bool operator<(const pt &b) {
            return tie(x, y) < tie(b.x, b.y);
        }
        bool operator==(const pt &b) {
            return tie(x, y) == tie(b.x, b.y);
        }
        pt operator+(const pt &b) {
            return {x + b.x, y + b.y};
        }
        pt operator-(const pt &b) {
            return {x - b.x, y - b.y};
        }
        int operator*(const pt &b) { // dot 內積
            return x * b.x + y * b.y;
        }
        int operator%(const pt &b) { // cross 外積
            return x * b.y - y * b.x;
        }
        pt operator*(const int &b) {
            return {x * b, y * b};
        }
        pt_d operator/(const double &b) {
            return {x / b, y / b};
        }
        int abs2() {
            return x * x + y * y;
        }
    };

    int sign(int x) {
        if (x > 0)
            return 1;
        if (x < 0)
            return -1;
        return 0;
    }

    bool collinear(pt p1, pt p2, pt p3) { // 三點是否為共線
        return sign((p1 - p3) % (p2 - p3)) == 0;
    }

    bool on_seg(pt start, pt end, pt p) { // p 是否在線段上
        return collinear(start, end, p) && (start - p) * (end - p) <= 0;
    }

    bool intersect(pt a1, pt a2, pt b1, pt b2) { // a, b線段是否相交
        if (a1 == b1 || a1 == b2 || a2 == b1 || a2 == b2)
            return true;
        if (on_seg(a1, a2, b1) || on_seg(a1, a2, b2) || on_seg(b1, b2, a1) || on_seg(b1, b2, a2))
            return true;
        bool c1 = sign((a2 - a1) % (b1 - a1)) * sign((a2 - a1) % (b2 - a1)) < 0;
        bool c2 = sign((b2 - b1) % (a1 - b1)) * sign((b2 - b1) % (a2 - b1)) < 0;
        return c1 && c2;
    }

    pt_d intersect_pt(pt a1, pt a2, pt b1, pt b2) { // a, b線段的交點
        int t1 = ((a2 - a1) % (b1 - a1));
        int t2 = ((a2 - a1) % (b2 - a1));
        return (b2 * t1 - b1 * t2) / (t1 - t2);
    }
}