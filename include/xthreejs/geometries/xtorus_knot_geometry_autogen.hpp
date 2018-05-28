#ifndef XTHREE_TORUS_KNOT_GEOMETRY_HPP
#define XTHREE_TORUS_KNOT_GEOMETRY_HPP

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
    // torus_knot_geometry declaration
    //

    template<class D>
    class xtorus_knot_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(double, derived_type, tube, 0.4);
        XPROPERTY(int, derived_type, tubularSegments, 64);
        XPROPERTY(int, derived_type, radialSegments, 8);
        XPROPERTY(int, derived_type, p, 2);
        XPROPERTY(int, derived_type, q, 3);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xtorus_knot_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using torus_knot_geometry = xw::xmaterialize<xtorus_knot_geometry>;

    using torus_knot_geometry_generator = xw::xgenerator<xtorus_knot_geometry>;

    //
    // torus_knot_geometry implementation
    //


    template <class D>
    inline void xtorus_knot_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(tube, state, buffers);
        xw::set_patch_from_property(tubularSegments, state, buffers);
        xw::set_patch_from_property(radialSegments, state, buffers);
        xw::set_patch_from_property(p, state, buffers);
        xw::set_patch_from_property(q, state, buffers);
    }

    template <class D>
    inline void xtorus_knot_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(tube, patch, buffers);
        xw::set_property_from_patch(tubularSegments, patch, buffers);
        xw::set_property_from_patch(radialSegments, patch, buffers);
        xw::set_property_from_patch(p, patch, buffers);
        xw::set_property_from_patch(q, patch, buffers);
    }

    template <class D>
    inline xtorus_knot_geometry<D>::xtorus_knot_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xtorus_knot_geometry<D>::set_defaults()
    {
        this->_model_name() = "TorusKnotGeometryModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xtorus_knot_geometry>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xtorus_knot_geometry>;
        extern template xw::xmaterialize<xthree::xtorus_knot_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xtorus_knot_geometry>>;
        extern template class xw::xgenerator<xthree::xtorus_knot_geometry>;
        extern template xw::xgenerator<xthree::xtorus_knot_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xtorus_knot_geometry>>;
    #endif
#endif

#endif