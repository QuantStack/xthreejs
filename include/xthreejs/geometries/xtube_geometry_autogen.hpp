#ifndef XTHREE_TUBE_GEOMETRY_HPP
#define XTHREE_TUBE_GEOMETRY_HPP

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
    // tube_geometry declaration
    //

    template<class D>
    class xtube_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, path);
        XPROPERTY(int, derived_type, segments, 64);
        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(int, derived_type, radiusSegments, 8);
        XPROPERTY(bool, derived_type, close, false);
        XPROPERTY(std::string, derived_type, type, "TubeGeometry");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xtube_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using tube_geometry = xw::xmaterialize<xtube_geometry>;

    using tube_geometry_generator = xw::xgenerator<xtube_geometry>;

    //
    // tube_geometry implementation
    //


    template <class D>
    inline void xtube_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(path, state, buffers);
        xw::set_patch_from_property(segments, state, buffers);
        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(radiusSegments, state, buffers);
        xw::set_patch_from_property(close, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xtube_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(path, patch, buffers);
        xw::set_property_from_patch(segments, patch, buffers);
        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(radiusSegments, patch, buffers);
        xw::set_property_from_patch(close, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xtube_geometry<D>::xtube_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xtube_geometry<D>::set_defaults()
    {
        this->_model_name() = "TubeGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xtube_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xtube_geometry>;
        extern template xw::xmaterialize<xthree::xtube_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xtube_geometry>>;
        extern template class xw::xgenerator<xthree::xtube_geometry>;
        extern template xw::xgenerator<xthree::xtube_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xtube_geometry>>;
    #endif
#endif

#endif