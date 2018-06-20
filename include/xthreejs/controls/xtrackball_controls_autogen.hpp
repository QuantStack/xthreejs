#ifndef XTHREE_TRACKBALL_CONTROLS_HPP
#define XTHREE_TRACKBALL_CONTROLS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xcontrols_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // trackball_controls declaration
    //

    template<class D>
    class xtrackball_controls : public xcontrols<D>
    {
    public:

        using base_type = xcontrols<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(bool, derived_type, enabled, true);
        XPROPERTY(double, derived_type, minDistance, 0);
        XPROPERTY(double, derived_type, maxDistance, 1e15);
        XPROPERTY(double, derived_type, rotateSpeed, 1);
        XPROPERTY(double, derived_type, zoomSpeed, 1.2);
        XPROPERTY(double, derived_type, panSpeed, 0.3);
        XPROPERTY(bool, derived_type, staticMoving, false);
        XPROPERTY(double, derived_type, dynamicDampingFactor, 0.2);
        XPROPERTY(bool, derived_type, noRotate, false);
        XPROPERTY(bool, derived_type, noZoom, false);
        XPROPERTY(bool, derived_type, noPan, false);
        XPROPERTY(bool, derived_type, noRoll, false);
        XPROPERTY(vector3, derived_type, target, vector3({0,0,0}));


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xtrackball_controls();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using trackball_controls = xw::xmaterialize<xtrackball_controls>;

    using trackball_controls_generator = xw::xgenerator<xtrackball_controls>;

    //
    // trackball_controls implementation
    //


    template <class D>
    inline void xtrackball_controls<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(enabled, state, buffers);
        xw::set_patch_from_property(minDistance, state, buffers);
        xw::set_patch_from_property(maxDistance, state, buffers);
        xw::set_patch_from_property(rotateSpeed, state, buffers);
        xw::set_patch_from_property(zoomSpeed, state, buffers);
        xw::set_patch_from_property(panSpeed, state, buffers);
        xw::set_patch_from_property(staticMoving, state, buffers);
        xw::set_patch_from_property(dynamicDampingFactor, state, buffers);
        xw::set_patch_from_property(noRotate, state, buffers);
        xw::set_patch_from_property(noZoom, state, buffers);
        xw::set_patch_from_property(noPan, state, buffers);
        xw::set_patch_from_property(noRoll, state, buffers);
        xw::set_patch_from_property(target, state, buffers);
    }

    template <class D>
    inline void xtrackball_controls<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(enabled, patch, buffers);
        xw::set_property_from_patch(minDistance, patch, buffers);
        xw::set_property_from_patch(maxDistance, patch, buffers);
        xw::set_property_from_patch(rotateSpeed, patch, buffers);
        xw::set_property_from_patch(zoomSpeed, patch, buffers);
        xw::set_property_from_patch(panSpeed, patch, buffers);
        xw::set_property_from_patch(staticMoving, patch, buffers);
        xw::set_property_from_patch(dynamicDampingFactor, patch, buffers);
        xw::set_property_from_patch(noRotate, patch, buffers);
        xw::set_property_from_patch(noZoom, patch, buffers);
        xw::set_property_from_patch(noPan, patch, buffers);
        xw::set_property_from_patch(noRoll, patch, buffers);
        xw::set_property_from_patch(target, patch, buffers);
    }

    template <class D>
    inline xtrackball_controls<D>::xtrackball_controls()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xtrackball_controls<D>::set_defaults()
    {
        this->_model_name() = "TrackballControlsModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xtrackball_controls>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xtrackball_controls>;
        extern template xw::xmaterialize<xthree::xtrackball_controls>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xtrackball_controls>>;
        extern template class xw::xgenerator<xthree::xtrackball_controls>;
        extern template xw::xgenerator<xthree::xtrackball_controls>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xtrackball_controls>>;
    #endif
#endif

#endif