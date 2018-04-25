#ifndef XTHREE_PERSPECTIVE_CAMERA_HPP
#define XTHREE_PERSPECTIVE_CAMERA_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xcamera_autogen.hpp"

namespace xthree
{
    //
    // perspective_camera declaration
    //

    template<class D>
    class xperspective_camera : public xcamera<D>
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
        XPROPERTY(double, derived_type, focus, 10);
        XPROPERTY(double, derived_type, aspect, 1);

    protected:

        xperspective_camera();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using perspective_camera = xw::xmaterialize<xperspective_camera>;

    using perspective_camera_generator = xw::xgenerator<xperspective_camera>;

    //
    // perspective_camera implementation
    //

    template <class D>
    inline void xperspective_camera<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(fov, state, buffers);
        xw::set_patch_from_property(zoom, state, buffers);
        xw::set_patch_from_property(near, state, buffers);
        xw::set_patch_from_property(far, state, buffers);
        xw::set_patch_from_property(focus, state, buffers);
        xw::set_patch_from_property(aspect, state, buffers);
    }

    template <class D>
    inline void xperspective_camera<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(fov, patch, buffers);
        xw::set_property_from_patch(zoom, patch, buffers);
        xw::set_property_from_patch(near, patch, buffers);
        xw::set_property_from_patch(far, patch, buffers);
        xw::set_property_from_patch(focus, patch, buffers);
        xw::set_property_from_patch(aspect, patch, buffers);
    }

    template <class D>
    inline xperspective_camera<D>::xperspective_camera()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xperspective_camera<D>::set_defaults()
    {
        this->_model_name() = "PerspectiveCameraModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xperspective_camera));
//}
#endif