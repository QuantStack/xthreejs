#ifndef XTHREE_CUBIC_INTERPOLANT_HPP
#define XTHREE_CUBIC_INTERPOLANT_HPP

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
    // cubic_interpolant declaration
    //

    template<class D>
    class xcubic_interpolant : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xcubic_interpolant();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using cubic_interpolant = xw::xmaterialize<xcubic_interpolant>;

    using cubic_interpolant_generator = xw::xgenerator<xcubic_interpolant>;

    //
    // cubic_interpolant implementation
    //


    template <class D>
    inline void xcubic_interpolant<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcubic_interpolant<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcubic_interpolant<D>::xcubic_interpolant()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcubic_interpolant<D>::set_defaults()
    {
        this->_model_name() = "CubicInterpolantModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xcubic_interpolant>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xcubic_interpolant>>;
    extern template class xw::xgenerator<xthree::xcubic_interpolant>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xcubic_interpolant>>;
#endif

#endif