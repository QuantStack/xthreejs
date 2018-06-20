#ifndef XTHREE_DIRECTIONAL_LIGHT_SHADOW_HPP
#define XTHREE_DIRECTIONAL_LIGHT_SHADOW_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xlight_shadow.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // directional_light_shadow declaration
    //

    template<class D>
    class xdirectional_light_shadow : public xlight_shadow<D>
    {
    public:

        using base_type = xlight_shadow<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xdirectional_light_shadow();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using directional_light_shadow = xw::xmaterialize<xdirectional_light_shadow>;

    using directional_light_shadow_generator = xw::xgenerator<xdirectional_light_shadow>;

    //
    // directional_light_shadow implementation
    //


    template <class D>
    inline void xdirectional_light_shadow<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xdirectional_light_shadow<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xdirectional_light_shadow<D>::xdirectional_light_shadow()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdirectional_light_shadow<D>::set_defaults()
    {
        this->_model_name() = "DirectionalLightShadowModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xdirectional_light_shadow>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xdirectional_light_shadow>;
        extern template xw::xmaterialize<xthree::xdirectional_light_shadow>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xdirectional_light_shadow>>;
        extern template class xw::xgenerator<xthree::xdirectional_light_shadow>;
        extern template xw::xgenerator<xthree::xdirectional_light_shadow>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xdirectional_light_shadow>>;
    #endif
#endif

#endif