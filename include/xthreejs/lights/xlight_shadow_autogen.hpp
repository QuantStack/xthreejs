#ifndef XTHREE_LIGHT_SHADOW_BASE_HPP
#define XTHREE_LIGHT_SHADOW_BASE_HPP

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
    // light_shadow_base declaration
    //

    template<class D>
    class xlight_shadow_base : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::xholder<xthree_widget>, derived_type, camera, object3d());
        XPROPERTY(double, derived_type, bias, 0);
        XPROPERTY(vector2, derived_type, mapSize, vector2({512,512}));
        XPROPERTY(double, derived_type, radius, 1);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xlight_shadow_base();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using light_shadow_base = xw::xmaterialize<xlight_shadow_base>;

    using light_shadow_base_generator = xw::xgenerator<xlight_shadow_base>;

    //
    // light_shadow_base implementation
    //


    template <class D>
    inline void xlight_shadow_base<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(camera, state, buffers);
        xw::set_patch_from_property(bias, state, buffers);
        xw::set_patch_from_property(mapSize, state, buffers);
        xw::set_patch_from_property(radius, state, buffers);
    }

    template <class D>
    inline void xlight_shadow_base<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(camera, patch, buffers);
        xw::set_property_from_patch(bias, patch, buffers);
        xw::set_property_from_patch(mapSize, patch, buffers);
        xw::set_property_from_patch(radius, patch, buffers);
    }

    template <class D>
    inline xlight_shadow_base<D>::xlight_shadow_base()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xlight_shadow_base<D>::set_defaults()
    {
        this->_model_name() = "LightShadowBaseModel";
        this->_view_name() = "";
    }
}


/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xlight_shadow_base>;
        extern template xw::xmaterialize<xthree::xlight_shadow_base>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xlight_shadow_base>>;
        extern template class xw::xgenerator<xthree::xlight_shadow_base>;
        extern template xw::xgenerator<xthree::xlight_shadow_base>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xlight_shadow_base>>;
    #endif
#endif

#endif