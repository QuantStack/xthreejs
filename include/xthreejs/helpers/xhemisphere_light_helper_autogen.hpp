#ifndef XTHREE_HEMISPHERE_LIGHT_HELPER_HPP
#define XTHREE_HEMISPHERE_LIGHT_HELPER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // hemisphere_light_helper declaration
    //

    template<class D>
    class xhemisphere_light_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, light);
        XPROPERTY(double, derived_type, size, 1);
        XPROPERTY(xtl::xoptional<xw::html_color>, derived_type, color, "#ffffff");

    protected:

        xhemisphere_light_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using hemisphere_light_helper = xw::xmaterialize<xhemisphere_light_helper>;

    using hemisphere_light_helper_generator = xw::xgenerator<xhemisphere_light_helper>;

    //
    // hemisphere_light_helper implementation
    //

    template <class D>
    inline void xhemisphere_light_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(light, state, buffers);
        xw::set_patch_from_property(size, state, buffers);
        xw::set_patch_from_property(color, state, buffers);
    }

    template <class D>
    inline void xhemisphere_light_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(light, patch, buffers);
        xw::set_property_from_patch(size, patch, buffers);
        xw::set_property_from_patch(color, patch, buffers);
    }

    template <class D>
    inline xhemisphere_light_helper<D>::xhemisphere_light_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xhemisphere_light_helper<D>::set_defaults()
    {
        this->_model_name() = "HemisphereLightHelperModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xhemisphere_light_helper));
//}
#endif