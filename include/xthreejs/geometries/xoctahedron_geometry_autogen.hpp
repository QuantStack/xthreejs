#ifndef XTHREE_OCTAHEDRON_GEOMETRY_HPP
#define XTHREE_OCTAHEDRON_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // octahedron_geometry declaration
    //

    template<class D>
    class xoctahedron_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(int, derived_type, detail, 0);
        XPROPERTY(std::string, derived_type, type, "OctahedronGeometry");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xoctahedron_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using octahedron_geometry = xw::xmaterialize<xoctahedron_geometry>;

    using octahedron_geometry_generator = xw::xgenerator<xoctahedron_geometry>;

    //
    // octahedron_geometry implementation
    //


    template <class D>
    inline void xoctahedron_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(detail, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xoctahedron_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(detail, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xoctahedron_geometry<D>::xoctahedron_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xoctahedron_geometry<D>::set_defaults()
    {
        this->_model_name() = "OctahedronGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xoctahedron_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xoctahedron_geometry>;
        extern template xw::xmaterialize<xthree::xoctahedron_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xoctahedron_geometry>>;
        extern template class xw::xgenerator<xthree::xoctahedron_geometry>;
        extern template xw::xgenerator<xthree::xoctahedron_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xoctahedron_geometry>>;
    #endif
#endif

#endif