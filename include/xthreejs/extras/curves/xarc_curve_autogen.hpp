#ifndef XTHREE_ARC_CURVE_HPP
#define XTHREE_ARC_CURVE_HPP

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
    // arc_curve declaration
    //

    template<class D>
    class xarc_curve : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xarc_curve();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using arc_curve = xw::xmaterialize<xarc_curve>;

    using arc_curve_generator = xw::xgenerator<xarc_curve>;

    //
    // arc_curve implementation
    //

    template <class D>
    inline void xarc_curve<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xarc_curve<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xarc_curve<D>::xarc_curve()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xarc_curve<D>::set_defaults()
    {
        this->_model_name() = "ArcCurveModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xarc_curve));
//}
#endif