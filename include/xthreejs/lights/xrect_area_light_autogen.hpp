#ifndef XTHREE_RECT_AREA_LIGHT_HPP
#define XTHREE_RECT_AREA_LIGHT_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xlight_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // rect_area_light declaration
    //

    template<class D>
    class xrect_area_light : public xlight<D>
    {
    public:

        using base_type = xlight<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, width, 10);
        XPROPERTY(double, derived_type, height, 10);
        XPROPERTY(std::string, derived_type, type, "RectAreaLight");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xrect_area_light();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using rect_area_light = xw::xmaterialize<xrect_area_light>;

    using rect_area_light_generator = xw::xgenerator<xrect_area_light>;

    //
    // rect_area_light implementation
    //


    template <class D>
    inline void xrect_area_light<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(width, state, buffers);
        xw::set_patch_from_property(height, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xrect_area_light<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(width, patch, buffers);
        xw::set_property_from_patch(height, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xrect_area_light<D>::xrect_area_light()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xrect_area_light<D>::set_defaults()
    {
        this->_model_name() = "RectAreaLightModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xrect_area_light>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xrect_area_light>;
        extern template xw::xmaterialize<xthree::xrect_area_light>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xrect_area_light>>;
        extern template class xw::xgenerator<xthree::xrect_area_light>;
        extern template xw::xgenerator<xthree::xrect_area_light>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xrect_area_light>>;
    #endif
#endif

#endif