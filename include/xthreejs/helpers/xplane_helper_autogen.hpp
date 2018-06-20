#ifndef XTHREE_PLANE_HELPER_HPP
#define XTHREE_PLANE_HELPER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // plane_helper declaration
    //

    template<class D>
    class xplane_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, plane);
        XPROPERTY(double, derived_type, size, 1);
        XPROPERTY(xtl::xoptional<xw::html_color>, derived_type, color, "yellow");
        XPROPERTY(std::string, derived_type, type, "PlaneHelper");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xplane_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using plane_helper = xw::xmaterialize<xplane_helper>;

    using plane_helper_generator = xw::xgenerator<xplane_helper>;

    //
    // plane_helper implementation
    //


    template <class D>
    inline void xplane_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(plane, state, buffers);
        xw::set_patch_from_property(size, state, buffers);
        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xplane_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(plane, patch, buffers);
        xw::set_property_from_patch(size, patch, buffers);
        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xplane_helper<D>::xplane_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xplane_helper<D>::set_defaults()
    {
        this->_model_name() = "PlaneHelperModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xplane_helper>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xplane_helper>;
        extern template xw::xmaterialize<xthree::xplane_helper>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xplane_helper>>;
        extern template class xw::xgenerator<xthree::xplane_helper>;
        extern template xw::xgenerator<xthree::xplane_helper>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xplane_helper>>;
    #endif
#endif

#endif