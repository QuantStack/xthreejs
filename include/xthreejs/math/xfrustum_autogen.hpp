#ifndef XTHREE_FRUSTUM_HPP
#define XTHREE_FRUSTUM_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // frustum declaration
    //

    template<class D>
    class xfrustum : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, p0);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, p1);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, p2);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, p3);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, p4);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, p5);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xfrustum();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using frustum = xw::xmaterialize<xfrustum>;

    using frustum_generator = xw::xgenerator<xfrustum>;

    //
    // frustum implementation
    //


    template <class D>
    inline void xfrustum<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(p0, state, buffers);
        xw::set_patch_from_property(p1, state, buffers);
        xw::set_patch_from_property(p2, state, buffers);
        xw::set_patch_from_property(p3, state, buffers);
        xw::set_patch_from_property(p4, state, buffers);
        xw::set_patch_from_property(p5, state, buffers);
    }

    template <class D>
    inline void xfrustum<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(p0, patch, buffers);
        xw::set_property_from_patch(p1, patch, buffers);
        xw::set_property_from_patch(p2, patch, buffers);
        xw::set_property_from_patch(p3, patch, buffers);
        xw::set_property_from_patch(p4, patch, buffers);
        xw::set_property_from_patch(p5, patch, buffers);
    }

    template <class D>
    inline xfrustum<D>::xfrustum()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xfrustum<D>::set_defaults()
    {
        this->_model_name() = "FrustumModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xfrustum>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xfrustum>;
        extern template xw::xmaterialize<xthree::xfrustum>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xfrustum>>;
        extern template class xw::xgenerator<xthree::xfrustum>;
        extern template xw::xgenerator<xthree::xfrustum>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xfrustum>>;
    #endif
#endif

#endif