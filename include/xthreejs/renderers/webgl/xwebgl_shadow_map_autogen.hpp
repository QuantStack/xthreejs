#ifndef XTHREE_WEBGL_SHADOW_MAP_HPP
#define XTHREE_WEBGL_SHADOW_MAP_HPP

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
    // webgl_shadow_map declaration
    //

    template<class D>
    class xwebgl_shadow_map : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(bool, derived_type, enabled, false);
        XPROPERTY(std::string, derived_type, type, "PCFShadowMap", xenums::ShadowTypes);
        XPROPERTY(bool, derived_type, renderReverseSided, false);
        XPROPERTY(bool, derived_type, renderSingleSided, true);


    protected:

        xwebgl_shadow_map();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_shadow_map = xw::xmaterialize<xwebgl_shadow_map>;

    using webgl_shadow_map_generator = xw::xgenerator<xwebgl_shadow_map>;

    //
    // webgl_shadow_map implementation
    //


    template <class D>
    inline void xwebgl_shadow_map<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(enabled, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
        xw::set_patch_from_property(renderReverseSided, state, buffers);
        xw::set_patch_from_property(renderSingleSided, state, buffers);
    }

    template <class D>
    inline void xwebgl_shadow_map<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(enabled, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
        xw::set_property_from_patch(renderReverseSided, patch, buffers);
        xw::set_property_from_patch(renderSingleSided, patch, buffers);
    }

    template <class D>
    inline xwebgl_shadow_map<D>::xwebgl_shadow_map()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_shadow_map<D>::set_defaults()
    {
        this->_model_name() = "WebGLShadowMapModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xwebgl_shadow_map));
//}
#endif