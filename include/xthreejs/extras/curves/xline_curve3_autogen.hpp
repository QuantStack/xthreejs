#ifndef XTHREE_LINE_CURVE3_HPP
#define XTHREE_LINE_CURVE3_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"

namespace xthree
{
    //
    // line_curve3 declaration
    //

    template<class D>
    class xline_curve3 : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xline_curve3();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using line_curve3 = xw::xmaterialize<xline_curve3>;

    using line_curve3_generator = xw::xgenerator<xline_curve3>;

    //
    // line_curve3 implementation
    //

    template <class D>
    inline void xline_curve3<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xline_curve3<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xline_curve3<D>::xline_curve3()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xline_curve3<D>::set_defaults()
    {
        this->_model_name() = "LineCurve3Model";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xline_curve3));
//}
#endif