#ifndef XTHREE_CONE_GEOMETRY_HPP
#define XTHREE_CONE_GEOMETRY_HPP

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
    // cone_geometry declaration
    //

    template<class D>
    class xcone_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 20);
        XPROPERTY(double, derived_type, height, 100);
        XPROPERTY(int, derived_type, radialSegments, 8);
        XPROPERTY(int, derived_type, heightSegments, 1);
        XPROPERTY(bool, derived_type, openEnded, false);
        XPROPERTY(double, derived_type, thetaStart, 0);
        XPROPERTY(double, derived_type, thetaLength, 6.283185307179586);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xcone_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using cone_geometry = xw::xmaterialize<xcone_geometry>;

    using cone_geometry_generator = xw::xgenerator<xcone_geometry>;

    //
    // cone_geometry implementation
    //


    template <class D>
    inline void xcone_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(height, state, buffers);
        xw::set_patch_from_property(radialSegments, state, buffers);
        xw::set_patch_from_property(heightSegments, state, buffers);
        xw::set_patch_from_property(openEnded, state, buffers);
        xw::set_patch_from_property(thetaStart, state, buffers);
        xw::set_patch_from_property(thetaLength, state, buffers);
    }

    template <class D>
    inline void xcone_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(height, patch, buffers);
        xw::set_property_from_patch(radialSegments, patch, buffers);
        xw::set_property_from_patch(heightSegments, patch, buffers);
        xw::set_property_from_patch(openEnded, patch, buffers);
        xw::set_property_from_patch(thetaStart, patch, buffers);
        xw::set_property_from_patch(thetaLength, patch, buffers);
    }

    template <class D>
    inline xcone_geometry<D>::xcone_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcone_geometry<D>::set_defaults()
    {
        this->_model_name() = "ConeGeometryModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xcone_geometry>& widget)
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
        extern template class xw::xmaterialize<xthree::xcone_geometry>;
        extern template xw::xmaterialize<xthree::xcone_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xcone_geometry>>;
        extern template class xw::xgenerator<xthree::xcone_geometry>;
        extern template xw::xgenerator<xthree::xcone_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xcone_geometry>>;
    #endif
#endif

#endif