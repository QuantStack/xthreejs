#ifndef XTHREE_QUADRATIC_BEZIER_CURVE3_HPP
#define XTHREE_QUADRATIC_BEZIER_CURVE3_HPP

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
    // quadratic_bezier_curve3 declaration
    //

    template<class D>
    class xquadratic_bezier_curve3 : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xquadratic_bezier_curve3();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using quadratic_bezier_curve3 = xw::xmaterialize<xquadratic_bezier_curve3>;

    using quadratic_bezier_curve3_generator = xw::xgenerator<xquadratic_bezier_curve3>;

    //
    // quadratic_bezier_curve3 implementation
    //


    template <class D>
    inline void xquadratic_bezier_curve3<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xquadratic_bezier_curve3<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xquadratic_bezier_curve3<D>::xquadratic_bezier_curve3()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xquadratic_bezier_curve3<D>::set_defaults()
    {
        this->_model_name() = "QuadraticBezierCurve3Model";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xquadratic_bezier_curve3>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xquadratic_bezier_curve3>;
        extern template xw::xmaterialize<xthree::xquadratic_bezier_curve3>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xquadratic_bezier_curve3>>;
        extern template class xw::xgenerator<xthree::xquadratic_bezier_curve3>;
        extern template xw::xgenerator<xthree::xquadratic_bezier_curve3>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xquadratic_bezier_curve3>>;
    #endif
#endif

#endif