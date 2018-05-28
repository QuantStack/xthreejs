#ifndef XTHREE_SPOT_LIGHT_HPP
#define XTHREE_SPOT_LIGHT_HPP

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
    // spot_light declaration
    //

    template<class D>
    class xspot_light : public xlight<D>
    {
    public:

        using base_type = xlight<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::xholder<xthree_widget>, derived_type, target, object3d());
        XPROPERTY(double, derived_type, distance, 0);
        XPROPERTY(double, derived_type, angle, 1.0471975511965976);
        XPROPERTY(double, derived_type, penumbra, 0);
        XPROPERTY(double, derived_type, decay, 1);
        XPROPERTY(xw::xholder<xthree_widget>, derived_type, shadow, object3d());


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xspot_light();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using spot_light = xw::xmaterialize<xspot_light>;

    using spot_light_generator = xw::xgenerator<xspot_light>;

    //
    // spot_light implementation
    //


    template <class D>
    inline void xspot_light<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(target, state, buffers);
        xw::set_patch_from_property(distance, state, buffers);
        xw::set_patch_from_property(angle, state, buffers);
        xw::set_patch_from_property(penumbra, state, buffers);
        xw::set_patch_from_property(decay, state, buffers);
        xw::set_patch_from_property(shadow, state, buffers);
    }

    template <class D>
    inline void xspot_light<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(target, patch, buffers);
        xw::set_property_from_patch(distance, patch, buffers);
        xw::set_property_from_patch(angle, patch, buffers);
        xw::set_property_from_patch(penumbra, patch, buffers);
        xw::set_property_from_patch(decay, patch, buffers);
        xw::set_property_from_patch(shadow, patch, buffers);
    }

    template <class D>
    inline xspot_light<D>::xspot_light()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xspot_light<D>::set_defaults()
    {
        this->_model_name() = "SpotLightModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xspot_light>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xspot_light>;
        extern template xw::xmaterialize<xthree::xspot_light>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xspot_light>>;
        extern template class xw::xgenerator<xthree::xspot_light>;
        extern template xw::xgenerator<xthree::xspot_light>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xspot_light>>;
    #endif
#endif

#endif