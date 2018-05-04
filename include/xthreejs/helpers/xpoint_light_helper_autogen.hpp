#ifndef XTHREE_POINT_LIGHT_HELPER_HPP
#define XTHREE_POINT_LIGHT_HELPER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // point_light_helper declaration
    //

    template<class D>
    class xpoint_light_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, light);
        XPROPERTY(double, derived_type, sphereSize, 1);
        XPROPERTY(xtl::xoptional<xw::html_color>, derived_type, color, "#ffffff");


    protected:

        xpoint_light_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using point_light_helper = xw::xmaterialize<xpoint_light_helper>;

    using point_light_helper_generator = xw::xgenerator<xpoint_light_helper>;

    //
    // point_light_helper implementation
    //


    template <class D>
    inline void xpoint_light_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(light, state, buffers);
        xw::set_patch_from_property(sphereSize, state, buffers);
        xw::set_patch_from_property(color, state, buffers);
    }

    template <class D>
    inline void xpoint_light_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(light, patch, buffers);
        xw::set_property_from_patch(sphereSize, patch, buffers);
        xw::set_property_from_patch(color, patch, buffers);
    }

    template <class D>
    inline xpoint_light_helper<D>::xpoint_light_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpoint_light_helper<D>::set_defaults()
    {
        this->_model_name() = "PointLightHelperModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xpoint_light_helper>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xpoint_light_helper>>;
    extern template class xw::xgenerator<xthree::xpoint_light_helper>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xpoint_light_helper>>;
#endif

#endif