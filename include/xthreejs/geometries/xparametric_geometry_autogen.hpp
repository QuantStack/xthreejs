#ifndef XTHREE_PARAMETRIC_GEOMETRY_HPP
#define XTHREE_PARAMETRIC_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"

namespace xthree
{
    //
    // parametric_geometry declaration
    //

    template<class D>
    class xparametric_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        
        XPROPERTY(int, derived_type, slices, 3);
        XPROPERTY(int, derived_type, stacks, 3);


    protected:

        xparametric_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using parametric_geometry = xw::xmaterialize<xparametric_geometry>;

    using parametric_geometry_generator = xw::xgenerator<xparametric_geometry>;

    //
    // parametric_geometry implementation
    //


    template <class D>
    inline void xparametric_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(slices, state, buffers);
        xw::set_patch_from_property(stacks, state, buffers);
    }

    template <class D>
    inline void xparametric_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(slices, patch, buffers);
        xw::set_property_from_patch(stacks, patch, buffers);
    }

    template <class D>
    inline xparametric_geometry<D>::xparametric_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xparametric_geometry<D>::set_defaults()
    {
        this->_model_name() = "ParametricGeometryModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xparametric_geometry>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xparametric_geometry>>;
    extern template class xw::xgenerator<xthree::xparametric_geometry>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xparametric_geometry>>;
#endif

#endif