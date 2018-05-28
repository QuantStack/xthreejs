#ifndef XTHREE_COMBINED_CAMERA_HPP
#define XTHREE_COMBINED_CAMERA_HPP

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
    // combined_camera declaration
    //

    template<class D>
    class xcombined_camera : public xcamera<D>
    {
    public:

        using base_type = xcamera<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, fov, 50);
        XPROPERTY(double, derived_type, zoom, 1);
        XPROPERTY(double, derived_type, near, 0.1);
        XPROPERTY(double, derived_type, far, 2000);
        XPROPERTY(double, derived_type, orthoNear, 0.1);
        XPROPERTY(double, derived_type, orthoFar, 2000);
        XPROPERTY(double, derived_type, width, 0);
        XPROPERTY(double, derived_type, height, 0);
        XPROPERTY(std::string, derived_type, mode, "perspective", XEITHER("perspective", "orthographic"));
        XPROPERTY(bool, derived_type, impersonate, true);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xcombined_camera();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using combined_camera = xw::xmaterialize<xcombined_camera>;

    using combined_camera_generator = xw::xgenerator<xcombined_camera>;

    //
    // combined_camera implementation
    //


    template <class D>
    inline void xcombined_camera<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(fov, state, buffers);
        xw::set_patch_from_property(zoom, state, buffers);
        xw::set_patch_from_property(near, state, buffers);
        xw::set_patch_from_property(far, state, buffers);
        xw::set_patch_from_property(orthoNear, state, buffers);
        xw::set_patch_from_property(orthoFar, state, buffers);
        xw::set_patch_from_property(width, state, buffers);
        xw::set_patch_from_property(height, state, buffers);
        xw::set_patch_from_property(mode, state, buffers);
        xw::set_patch_from_property(impersonate, state, buffers);
    }

    template <class D>
    inline void xcombined_camera<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(fov, patch, buffers);
        xw::set_property_from_patch(zoom, patch, buffers);
        xw::set_property_from_patch(near, patch, buffers);
        xw::set_property_from_patch(far, patch, buffers);
        xw::set_property_from_patch(orthoNear, patch, buffers);
        xw::set_property_from_patch(orthoFar, patch, buffers);
        xw::set_property_from_patch(width, patch, buffers);
        xw::set_property_from_patch(height, patch, buffers);
        xw::set_property_from_patch(mode, patch, buffers);
        xw::set_property_from_patch(impersonate, patch, buffers);
    }

    template <class D>
    inline xcombined_camera<D>::xcombined_camera()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcombined_camera<D>::set_defaults()
    {
        this->_model_name() = "CombinedCameraModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xcombined_camera>& widget)
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
        extern template class xw::xmaterialize<xthree::xcombined_camera>;
        extern template xw::xmaterialize<xthree::xcombined_camera>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xcombined_camera>>;
        extern template class xw::xgenerator<xthree::xcombined_camera>;
        extern template xw::xgenerator<xthree::xcombined_camera>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xcombined_camera>>;
    #endif
#endif

#endif