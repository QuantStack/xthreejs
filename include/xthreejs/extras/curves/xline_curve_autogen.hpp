#ifndef XTHREE_LINE_CURVE_HPP
#define XTHREE_LINE_CURVE_HPP

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
    // line_curve declaration
    //

    template<class D>
    class xline_curve : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xline_curve();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using line_curve = xw::xmaterialize<xline_curve>;

    using line_curve_generator = xw::xgenerator<xline_curve>;

    //
    // line_curve implementation
    //


    template <class D>
    inline void xline_curve<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xline_curve<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xline_curve<D>::xline_curve()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xline_curve<D>::set_defaults()
    {
        this->_model_name() = "LineCurveModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xline_curve));
//}
#endif