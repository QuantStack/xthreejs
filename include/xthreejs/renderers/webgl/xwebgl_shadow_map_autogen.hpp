#ifndef XTHREE_WEBGL_SHADOW_MAP_BASE_HPP
#define XTHREE_WEBGL_SHADOW_MAP_BASE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"
#include "../../base/xrender.hpp"

namespace xthree
{
    //
    // webgl_shadow_map_base declaration
    //

    template<class D>
    class xwebgl_shadow_map_base : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(bool, derived_type, enabled, false);
        XPROPERTY(std::string, derived_type, type, "PCFShadowMap", xenums::ShadowTypes);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xwebgl_shadow_map_base();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_shadow_map_base = xw::xmaterialize<xwebgl_shadow_map_base>;

    using webgl_shadow_map_base_generator = xw::xgenerator<xwebgl_shadow_map_base>;

    //
    // webgl_shadow_map_base implementation
    //


    template <class D>
    inline void xwebgl_shadow_map_base<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(enabled, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xwebgl_shadow_map_base<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(enabled, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xwebgl_shadow_map_base<D>::xwebgl_shadow_map_base()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_shadow_map_base<D>::set_defaults()
    {
        this->_model_name() = "WebGLShadowMapBaseModel";
        this->_view_name() = "";
    }
}


/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xwebgl_shadow_map_base>;
        extern template xw::xmaterialize<xthree::xwebgl_shadow_map_base>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_shadow_map_base>>;
        extern template class xw::xgenerator<xthree::xwebgl_shadow_map_base>;
        extern template xw::xgenerator<xthree::xwebgl_shadow_map_base>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xwebgl_shadow_map_base>>;
    #endif
#endif

#endif