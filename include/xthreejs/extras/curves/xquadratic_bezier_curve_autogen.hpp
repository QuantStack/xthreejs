#ifndef XTHREE_QUADRATIC_BEZIER_CURVE_HPP
#define XTHREE_QUADRATIC_BEZIER_CURVE_HPP

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
    // quadratic_bezier_curve declaration
    //

    template<class D>
    class xquadratic_bezier_curve : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xquadratic_bezier_curve();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using quadratic_bezier_curve = xw::xmaterialize<xquadratic_bezier_curve>;

    using quadratic_bezier_curve_generator = xw::xgenerator<xquadratic_bezier_curve>;

    //
    // quadratic_bezier_curve implementation
    //


    template <class D>
    inline void xquadratic_bezier_curve<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xquadratic_bezier_curve<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xquadratic_bezier_curve<D>::xquadratic_bezier_curve()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xquadratic_bezier_curve<D>::set_defaults()
    {
        this->_model_name() = "QuadraticBezierCurveModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xquadratic_bezier_curve));
//}
#endif