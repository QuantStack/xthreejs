#ifndef XTHREE_INTERPOLANT_HPP
#define XTHREE_INTERPOLANT_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // interpolant declaration
    //

    template<class D>
    class xinterpolant : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xinterpolant();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using interpolant = xw::xmaterialize<xinterpolant>;

    using interpolant_generator = xw::xgenerator<xinterpolant>;

    //
    // interpolant implementation
    //


    template <class D>
    inline void xinterpolant<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xinterpolant<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xinterpolant<D>::xinterpolant()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xinterpolant<D>::set_defaults()
    {
        this->_model_name() = "InterpolantModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xinterpolant));
//}
#endif