#ifndef XTHREE_DIRECTIONAL_LIGHT_HPP
#define XTHREE_DIRECTIONAL_LIGHT_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xlight_autogen.hpp"

namespace xthree
{
    //
    // directional_light declaration
    //

    template<class D>
    class xdirectional_light : public xlight<D>
    {
    public:

        using base_type = xlight<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::xholder<xthree_widget>, derived_type, target, object3d());
        XPROPERTY(xw::xholder<xthree_widget>, derived_type, shadow, object3d());


    protected:

        xdirectional_light();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using directional_light = xw::xmaterialize<xdirectional_light>;

    using directional_light_generator = xw::xgenerator<xdirectional_light>;

    //
    // directional_light implementation
    //


    template <class D>
    inline void xdirectional_light<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(target, state, buffers);
        xw::set_patch_from_property(shadow, state, buffers);
    }

    template <class D>
    inline void xdirectional_light<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(target, patch, buffers);
        xw::set_property_from_patch(shadow, patch, buffers);
    }

    template <class D>
    inline xdirectional_light<D>::xdirectional_light()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdirectional_light<D>::set_defaults()
    {
        this->_model_name() = "DirectionalLightModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xdirectional_light>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xdirectional_light>>;
    extern template class xw::xgenerator<xthree::xdirectional_light>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xdirectional_light>>;
#endif

#endif