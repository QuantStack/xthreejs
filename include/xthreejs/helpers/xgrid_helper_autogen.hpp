#ifndef XTHREE_GRID_HELPER_HPP
#define XTHREE_GRID_HELPER_HPP

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
    // grid_helper declaration
    //

    template<class D>
    class xgrid_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, size, 10);
        XPROPERTY(int, derived_type, divisions, 10);
        XPROPERTY(xw::html_color, derived_type, colorCenterLine, "0x444444");
        XPROPERTY(xw::html_color, derived_type, colorGrid, "0x888888");


    protected:

        xgrid_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using grid_helper = xw::xmaterialize<xgrid_helper>;

    using grid_helper_generator = xw::xgenerator<xgrid_helper>;

    //
    // grid_helper implementation
    //


    template <class D>
    inline void xgrid_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(size, state, buffers);
        xw::set_patch_from_property(divisions, state, buffers);
        xw::set_patch_from_property(colorCenterLine, state, buffers);
        xw::set_patch_from_property(colorGrid, state, buffers);
    }

    template <class D>
    inline void xgrid_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(size, patch, buffers);
        xw::set_property_from_patch(divisions, patch, buffers);
        xw::set_property_from_patch(colorCenterLine, patch, buffers);
        xw::set_property_from_patch(colorGrid, patch, buffers);
    }

    template <class D>
    inline xgrid_helper<D>::xgrid_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xgrid_helper<D>::set_defaults()
    {
        this->_model_name() = "GridHelperModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xgrid_helper));
//}
#endif