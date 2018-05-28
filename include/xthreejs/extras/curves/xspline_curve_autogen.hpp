#ifndef XTHREE_SPLINE_CURVE_HPP
#define XTHREE_SPLINE_CURVE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"
#include "../../base/xrender.hpp"

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

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

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

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xspline_curve>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xspline_curve>;
        extern template xw::xmaterialize<xthree::xspline_curve>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xspline_curve>>;
        extern template class xw::xgenerator<xthree::xspline_curve>;
        extern template xw::xgenerator<xthree::xspline_curve>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xspline_curve>>;
    #endif
#endif

#endif