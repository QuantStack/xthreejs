#ifndef XTHREE_THREE_TYPES_HPP
#define XTHREE_THREE_TYPES_HPP

#include "xthree.hpp"

#include "xtensor/xarray.hpp"
#include "xtensor/xadapt.hpp"

#include <array>
#include <map>
#include <tuple>
#include <string>
#include <vector>

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

    struct webgldataunion: public xt::xarray<float>
    {
        using base_type = xt::xarray<float>;

        webgldataunion(): base_type(){};
        webgldataunion(base_type& b): base_type(b){};

        template <class D> 
        webgldataunion(const xt::xexpression<D>& b) : base_type(b){};
        template <class D> 
        webgldataunion(xt::xexpression<D>&& b) : base_type(std::move(b)){};
    };

    inline void xwidgets_deserialize(webgldataunion& value, const xeus::xjson& j, const xeus::buffer_sequence& buffers)
    {
        std::size_t index = xw::buffer_index(j.template get<std::string>());
        std::vector<std::size_t> shape = j["shape"];
        const auto& buffer = buffers[index];
        value = xt::adapt(static_cast<const float*>(buffer.data()),
                          buffer.size() / 4, xt::no_ownership(),
                          shape);
    }

    inline void xwidgets_serialize(const webgldataunion& value, xeus::xjson& j, xeus::buffer_sequence& buffers)
    {
        j = {
            {"shape", value.shape()},
            {"dtype", "float32"},
            {"buffer", xw::xbuffer_reference_prefix() + std::to_string(buffers.size())}
        };
        // TODO raw_data -> data upon release 0.16 for xtensor
        buffers.emplace_back(value.data(), 4 * value.size());
    }
}

#endif
