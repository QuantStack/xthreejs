#ifndef XTHREE_LIGHT_HPP
#define XTHREE_LIGHT_HPP

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
    // light declaration
    //

    template<class D>
    class xlight : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::html_color, derived_type, color, "#ffffff");
        XPROPERTY(double, derived_type, intensity, 1);


    protected:

        xlight();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using light = xw::xmaterialize<xlight>;

    using light_generator = xw::xgenerator<xlight>;

    //
    // light implementation
    //


    template <class D>
    inline void xlight<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(intensity, state, buffers);
    }

    template <class D>
    inline void xlight<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(intensity, patch, buffers);
    }

    template <class D>
    inline xlight<D>::xlight()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xlight<D>::set_defaults()
    {
        this->_model_name() = "LightModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xlight));
//}
#endif