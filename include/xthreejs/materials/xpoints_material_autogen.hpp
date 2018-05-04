#ifndef XTHREE_POINTS_MATERIAL_HPP
#define XTHREE_POINTS_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmaterial_autogen.hpp"

namespace xthree
{
    //
    // points_material declaration
    //

    template<class D>
    class xpoints_material : public xmaterial<D>
    {
    public:

        using base_type = xmaterial<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::html_color, derived_type, color, "#ffffff");
        XPROPERTY(bool, derived_type, lights, false);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, map);
        XPROPERTY(double, derived_type, size, 1);
        XPROPERTY(bool, derived_type, sizeAttenuation, true);


    protected:

        xpoints_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using points_material = xw::xmaterialize<xpoints_material>;

    using points_material_generator = xw::xgenerator<xpoints_material>;

    //
    // points_material implementation
    //


    template <class D>
    inline void xpoints_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(lights, state, buffers);
        xw::set_patch_from_property(map, state, buffers);
        xw::set_patch_from_property(size, state, buffers);
        xw::set_patch_from_property(sizeAttenuation, state, buffers);
    }

    template <class D>
    inline void xpoints_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(lights, patch, buffers);
        xw::set_property_from_patch(map, patch, buffers);
        xw::set_property_from_patch(size, patch, buffers);
        xw::set_property_from_patch(sizeAttenuation, patch, buffers);
    }

    template <class D>
    inline xpoints_material<D>::xpoints_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpoints_material<D>::set_defaults()
    {
        this->_model_name() = "PointsMaterialModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xpoints_material));
//}
#endif