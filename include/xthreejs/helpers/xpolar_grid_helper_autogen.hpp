#ifndef XTHREE_POLAR_GRID_HELPER_HPP
#define XTHREE_POLAR_GRID_HELPER_HPP

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
    // polar_grid_helper declaration
    //

    template<class D>
    class xpolar_grid_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(int, derived_type, radius, 10);
        XPROPERTY(int, derived_type, radials, 16);
        XPROPERTY(int, derived_type, circles, 8);
        XPROPERTY(int, derived_type, divisions, 64);
        XPROPERTY(xw::html_color, derived_type, color1, "0x444444");
        XPROPERTY(xw::html_color, derived_type, color2, "0x888888");

    protected:

        xpolar_grid_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using polar_grid_helper = xw::xmaterialize<xpolar_grid_helper>;

    using polar_grid_helper_generator = xw::xgenerator<xpolar_grid_helper>;

    //
    // polar_grid_helper implementation
    //

    template <class D>
    inline void xpolar_grid_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(radials, state, buffers);
        xw::set_patch_from_property(circles, state, buffers);
        xw::set_patch_from_property(divisions, state, buffers);
        xw::set_patch_from_property(color1, state, buffers);
        xw::set_patch_from_property(color2, state, buffers);
    }

    template <class D>
    inline void xpolar_grid_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(radials, patch, buffers);
        xw::set_property_from_patch(circles, patch, buffers);
        xw::set_property_from_patch(divisions, patch, buffers);
        xw::set_property_from_patch(color1, patch, buffers);
        xw::set_property_from_patch(color2, patch, buffers);
    }

    template <class D>
    inline xpolar_grid_helper<D>::xpolar_grid_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpolar_grid_helper<D>::set_defaults()
    {
        this->_model_name() = "PolarGridHelperModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xpolar_grid_helper));
//}
#endif