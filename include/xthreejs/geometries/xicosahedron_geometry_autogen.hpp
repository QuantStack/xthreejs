#ifndef XTHREE_ICOSAHEDRON_GEOMETRY_HPP
#define XTHREE_ICOSAHEDRON_GEOMETRY_HPP

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
    // icosahedron_geometry declaration
    //

    template<class D>
    class xicosahedron_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(int, derived_type, detail, 0);


    protected:

        xicosahedron_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using icosahedron_geometry = xw::xmaterialize<xicosahedron_geometry>;

    using icosahedron_geometry_generator = xw::xgenerator<xicosahedron_geometry>;

    //
    // icosahedron_geometry implementation
    //


    template <class D>
    inline void xicosahedron_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(detail, state, buffers);
    }

    template <class D>
    inline void xicosahedron_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(detail, patch, buffers);
    }

    template <class D>
    inline xicosahedron_geometry<D>::xicosahedron_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xicosahedron_geometry<D>::set_defaults()
    {
        this->_model_name() = "IcosahedronGeometryModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xicosahedron_geometry>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xicosahedron_geometry>>;
    extern template class xw::xgenerator<xthree::xicosahedron_geometry>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xicosahedron_geometry>>;
#endif

#endif