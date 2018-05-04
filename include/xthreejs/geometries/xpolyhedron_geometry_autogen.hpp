#ifndef XTHREE_POLYHEDRON_GEOMETRY_HPP
#define XTHREE_POLYHEDRON_GEOMETRY_HPP

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
    // polyhedron_geometry declaration
    //

    template<class D>
    class xpolyhedron_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::vector<double>, derived_type, vertices, std::vector<double>({}));
        XPROPERTY(std::vector<double>, derived_type, indices, std::vector<double>({}));
        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(double, derived_type, detail, 0);
        XPROPERTY(std::vector<double>, derived_type, faces, std::vector<double>({}));


    protected:

        xpolyhedron_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using polyhedron_geometry = xw::xmaterialize<xpolyhedron_geometry>;

    using polyhedron_geometry_generator = xw::xgenerator<xpolyhedron_geometry>;

    //
    // polyhedron_geometry implementation
    //


    template <class D>
    inline void xpolyhedron_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(vertices, state, buffers);
        xw::set_patch_from_property(indices, state, buffers);
        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(detail, state, buffers);
        xw::set_patch_from_property(faces, state, buffers);
    }

    template <class D>
    inline void xpolyhedron_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(vertices, patch, buffers);
        xw::set_property_from_patch(indices, patch, buffers);
        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(detail, patch, buffers);
        xw::set_property_from_patch(faces, patch, buffers);
    }

    template <class D>
    inline xpolyhedron_geometry<D>::xpolyhedron_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpolyhedron_geometry<D>::set_defaults()
    {
        this->_model_name() = "PolyhedronGeometryModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xpolyhedron_geometry>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xpolyhedron_geometry>>;
    extern template class xw::xgenerator<xthree::xpolyhedron_geometry>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xpolyhedron_geometry>>;
#endif

#endif