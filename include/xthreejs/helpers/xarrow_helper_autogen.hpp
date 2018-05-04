#ifndef XTHREE_ARROW_HELPER_HPP
#define XTHREE_ARROW_HELPER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // arrow_helper declaration
    //

    template<class D>
    class xarrow_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector3, derived_type, dir, vector3({1,0,0}));
        XPROPERTY(vector3, derived_type, origin, vector3({0,0,0}));
        XPROPERTY(double, derived_type, length, 1);
        XPROPERTY(int, derived_type, hex, 0);
        XPROPERTY(xtl::xoptional<double>, derived_type, headLength);
        XPROPERTY(xtl::xoptional<double>, derived_type, headWidth);


    protected:

        xarrow_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using arrow_helper = xw::xmaterialize<xarrow_helper>;

    using arrow_helper_generator = xw::xgenerator<xarrow_helper>;

    //
    // arrow_helper implementation
    //


    template <class D>
    inline void xarrow_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(dir, state, buffers);
        xw::set_patch_from_property(origin, state, buffers);
        xw::set_patch_from_property(length, state, buffers);
        xw::set_patch_from_property(hex, state, buffers);
        xw::set_patch_from_property(headLength, state, buffers);
        xw::set_patch_from_property(headWidth, state, buffers);
    }

    template <class D>
    inline void xarrow_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(dir, patch, buffers);
        xw::set_property_from_patch(origin, patch, buffers);
        xw::set_property_from_patch(length, patch, buffers);
        xw::set_property_from_patch(hex, patch, buffers);
        xw::set_property_from_patch(headLength, patch, buffers);
        xw::set_property_from_patch(headWidth, patch, buffers);
    }

    template <class D>
    inline xarrow_helper<D>::xarrow_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xarrow_helper<D>::set_defaults()
    {
        this->_model_name() = "ArrowHelperModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xarrow_helper>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xarrow_helper>>;
    extern template class xw::xgenerator<xthree::xarrow_helper>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xarrow_helper>>;
#endif

#endif