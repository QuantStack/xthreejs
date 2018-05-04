#ifndef XTHREE_POINT_LIGHT_HPP
#define XTHREE_POINT_LIGHT_HPP

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
    // point_light declaration
    //

    template<class D>
    class xpoint_light : public xlight<D>
    {
    public:

        using base_type = xlight<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, power, 12.566370614359172);
        XPROPERTY(double, derived_type, distance, 0);
        XPROPERTY(double, derived_type, decay, 1);
        XPROPERTY(xw::xholder<xthree_widget>, derived_type, shadow, object3d());


    protected:

        xpoint_light();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using point_light = xw::xmaterialize<xpoint_light>;

    using point_light_generator = xw::xgenerator<xpoint_light>;

    //
    // point_light implementation
    //


    template <class D>
    inline void xpoint_light<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(power, state, buffers);
        xw::set_patch_from_property(distance, state, buffers);
        xw::set_patch_from_property(decay, state, buffers);
        xw::set_patch_from_property(shadow, state, buffers);
    }

    template <class D>
    inline void xpoint_light<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(power, patch, buffers);
        xw::set_property_from_patch(distance, patch, buffers);
        xw::set_property_from_patch(decay, patch, buffers);
        xw::set_property_from_patch(shadow, patch, buffers);
    }

    template <class D>
    inline xpoint_light<D>::xpoint_light()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpoint_light<D>::set_defaults()
    {
        this->_model_name() = "PointLightModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xpoint_light));
//}
#endif