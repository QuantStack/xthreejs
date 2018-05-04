#ifndef XTHREE_SPLINE_CURVE_HPP
#define XTHREE_SPLINE_CURVE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"

namespace xthree
{
    //
    // spline_curve declaration
    //

    template<class D>
    class xspline_curve : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xspline_curve();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using spline_curve = xw::xmaterialize<xspline_curve>;

    using spline_curve_generator = xw::xgenerator<xspline_curve>;

    //
    // spline_curve implementation
    //


    template <class D>
    inline void xspline_curve<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xspline_curve<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xspline_curve<D>::xspline_curve()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xspline_curve<D>::set_defaults()
    {
        this->_model_name() = "SplineCurveModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xspline_curve>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xspline_curve>>;
    extern template class xw::xgenerator<xthree::xspline_curve>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xspline_curve>>;
#endif

#endif