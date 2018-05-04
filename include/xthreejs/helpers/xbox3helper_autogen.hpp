#ifndef XTHREE_BOX3HELPER_HPP
#define XTHREE_BOX3HELPER_HPP

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
    // box3helper declaration
    //

    template<class D>
    class xbox3helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, box);
        XPROPERTY(xtl::xoptional<xw::html_color>, derived_type, color, "yellow");


    protected:

        xbox3helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using box3helper = xw::xmaterialize<xbox3helper>;

    using box3helper_generator = xw::xgenerator<xbox3helper>;

    //
    // box3helper implementation
    //


    template <class D>
    inline void xbox3helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(box, state, buffers);
        xw::set_patch_from_property(color, state, buffers);
    }

    template <class D>
    inline void xbox3helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(box, patch, buffers);
        xw::set_property_from_patch(color, patch, buffers);
    }

    template <class D>
    inline xbox3helper<D>::xbox3helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbox3helper<D>::set_defaults()
    {
        this->_model_name() = "Box3HelperModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xbox3helper>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xbox3helper>>;
    extern template class xw::xgenerator<xthree::xbox3helper>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xbox3helper>>;
#endif

#endif