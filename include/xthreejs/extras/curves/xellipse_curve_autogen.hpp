#ifndef XTHREE_ELLIPSE_CURVE_HPP
#define XTHREE_ELLIPSE_CURVE_HPP

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
    // ellipse_curve declaration
    //

    template<class D>
    class xellipse_curve : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xellipse_curve();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using ellipse_curve = xw::xmaterialize<xellipse_curve>;

    using ellipse_curve_generator = xw::xgenerator<xellipse_curve>;

    //
    // ellipse_curve implementation
    //


    template <class D>
    inline void xellipse_curve<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xellipse_curve<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xellipse_curve<D>::xellipse_curve()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xellipse_curve<D>::set_defaults()
    {
        this->_model_name() = "EllipseCurveModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xellipse_curve>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xellipse_curve>>;
    extern template class xw::xgenerator<xthree::xellipse_curve>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xellipse_curve>>;
#endif

#endif