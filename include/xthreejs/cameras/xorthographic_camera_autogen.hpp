#ifndef XTHREE_ORTHOGRAPHIC_CAMERA_HPP
#define XTHREE_ORTHOGRAPHIC_CAMERA_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xcamera_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // orthographic_camera declaration
    //

    template<class D>
    class xorthographic_camera : public xcamera<D>
    {
    public:

        using base_type = xcamera<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, zoom, 1);
        XPROPERTY(double, derived_type, left, 0);
        XPROPERTY(double, derived_type, right, 0);
        XPROPERTY(double, derived_type, top, 0);
        XPROPERTY(double, derived_type, bottom, 0);
        XPROPERTY(double, derived_type, near, 0.1);
        XPROPERTY(double, derived_type, far, 2000);
        XPROPERTY(std::string, derived_type, type, "OrthographicCamera");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xorthographic_camera();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using orthographic_camera = xw::xmaterialize<xorthographic_camera>;

    using orthographic_camera_generator = xw::xgenerator<xorthographic_camera>;

    //
    // orthographic_camera implementation
    //


    template <class D>
    inline void xorthographic_camera<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(zoom, state, buffers);
        xw::set_patch_from_property(left, state, buffers);
        xw::set_patch_from_property(right, state, buffers);
        xw::set_patch_from_property(top, state, buffers);
        xw::set_patch_from_property(bottom, state, buffers);
        xw::set_patch_from_property(near, state, buffers);
        xw::set_patch_from_property(far, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xorthographic_camera<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(zoom, patch, buffers);
        xw::set_property_from_patch(left, patch, buffers);
        xw::set_property_from_patch(right, patch, buffers);
        xw::set_property_from_patch(top, patch, buffers);
        xw::set_property_from_patch(bottom, patch, buffers);
        xw::set_property_from_patch(near, patch, buffers);
        xw::set_property_from_patch(far, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xorthographic_camera<D>::xorthographic_camera()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xorthographic_camera<D>::set_defaults()
    {
        this->_model_name() = "OrthographicCameraModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xorthographic_camera>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xorthographic_camera>;
        extern template xw::xmaterialize<xthree::xorthographic_camera>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xorthographic_camera>>;
        extern template class xw::xgenerator<xthree::xorthographic_camera>;
        extern template xw::xgenerator<xthree::xorthographic_camera>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xorthographic_camera>>;
    #endif
#endif

#endif