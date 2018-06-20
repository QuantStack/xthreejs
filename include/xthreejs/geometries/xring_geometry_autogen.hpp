#ifndef XTHREE_RING_GEOMETRY_HPP
#define XTHREE_RING_GEOMETRY_HPP

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
    // ring_geometry declaration
    //

    template<class D>
    class xring_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, innerRadius, 0.5);
        XPROPERTY(double, derived_type, outerRadius, 1);
        XPROPERTY(int, derived_type, thetaSegments, 8);
        XPROPERTY(int, derived_type, phiSegments, 8);
        XPROPERTY(double, derived_type, thetaStart, 0);
        XPROPERTY(double, derived_type, thetaLength, 6.283185307179586);
        XPROPERTY(std::string, derived_type, type, "RingGeometry");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xring_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using ring_geometry = xw::xmaterialize<xring_geometry>;

    using ring_geometry_generator = xw::xgenerator<xring_geometry>;

    //
    // ring_geometry implementation
    //


    template <class D>
    inline void xring_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(innerRadius, state, buffers);
        xw::set_patch_from_property(outerRadius, state, buffers);
        xw::set_patch_from_property(thetaSegments, state, buffers);
        xw::set_patch_from_property(phiSegments, state, buffers);
        xw::set_patch_from_property(thetaStart, state, buffers);
        xw::set_patch_from_property(thetaLength, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xring_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(innerRadius, patch, buffers);
        xw::set_property_from_patch(outerRadius, patch, buffers);
        xw::set_property_from_patch(thetaSegments, patch, buffers);
        xw::set_property_from_patch(phiSegments, patch, buffers);
        xw::set_property_from_patch(thetaStart, patch, buffers);
        xw::set_property_from_patch(thetaLength, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xring_geometry<D>::xring_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xring_geometry<D>::set_defaults()
    {
        this->_model_name() = "RingGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xring_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xring_geometry>;
        extern template xw::xmaterialize<xthree::xring_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xring_geometry>>;
        extern template class xw::xgenerator<xthree::xring_geometry>;
        extern template xw::xgenerator<xthree::xring_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xring_geometry>>;
    #endif
#endif

#endif