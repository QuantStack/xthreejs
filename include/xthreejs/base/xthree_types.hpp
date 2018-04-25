#ifndef XTHREE_THREE_TYPES_HPP
#define XTHREE_THREE_TYPES_HPP

#include "xthree.hpp"

#include <array>
#include <map>
#include <tuple>
#include <string>

namespace xthree
{
    using vector2 = std::array<double, 2>;
    using vector3 = std::array<double, 3>;
    using vector4 = std::array<double, 4>;

    using matrix3 = std::array<double, 9>;
    using matrix4 = std::array<double, 16>;

    using face3 = std::tuple<int, int, int, vector3, std::string, int>;
    using euler = std::tuple<double, double, double, std::string>;

    using dict = std::map<std::string, xw::xholder<xthree_widget>>;
    using dictvec = std::map<std::string, std::vector<xw::xholder<xthree_widget>>>;
}

#endif
