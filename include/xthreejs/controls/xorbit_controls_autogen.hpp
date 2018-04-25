#ifndef XTHREE_ORBIT_CONTROLS_HPP
#define XTHREE_ORBIT_CONTROLS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xcontrols_autogen.hpp"

namespace xthree
{
    //
    // orbit_controls declaration
    //

    template<class D>
    class xorbit_controls : public xcontrols<D>
    {
    public:

        using base_type = xcontrols<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(bool, derived_type, enabled, true);
        XPROPERTY(double, derived_type, minDistance, 0);
        XPROPERTY(double, derived_type, maxDistance, 1e15);
        XPROPERTY(double, derived_type, minZoom, 0);
        XPROPERTY(double, derived_type, maxZoom, 1e15);
        XPROPERTY(double, derived_type, minPolarAngle, 0);
        XPROPERTY(double, derived_type, maxPolarAngle, 3.141592653589793);
        XPROPERTY(double, derived_type, minAzimuthAngle, -1e15);
        XPROPERTY(double, derived_type, maxAzimuthAngle, 1e15);
        XPROPERTY(bool, derived_type, enableDamping, false);
        XPROPERTY(double, derived_type, dampingFactor, 0.25);
        XPROPERTY(bool, derived_type, enableZoom, true);
        XPROPERTY(double, derived_type, zoomSpeed, 1);
        XPROPERTY(bool, derived_type, enableRotate, true);
        XPROPERTY(double, derived_type, rotateSpeed, 1);
        XPROPERTY(bool, derived_type, enablePan, true);
        XPROPERTY(double, derived_type, keyPanSpeed, 7);
        XPROPERTY(bool, derived_type, autoRotate, false);
        XPROPERTY(double, derived_type, autoRotateSpeed, 2);
        XPROPERTY(bool, derived_type, enableKeys, true);
        XPROPERTY(vector3, derived_type, target, vector3({0,0,0}));

    protected:

        xorbit_controls();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using orbit_controls = xw::xmaterialize<xorbit_controls>;

    using orbit_controls_generator = xw::xgenerator<xorbit_controls>;

    //
    // orbit_controls implementation
    //

    template <class D>
    inline void xorbit_controls<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(enabled, state, buffers);
        xw::set_patch_from_property(minDistance, state, buffers);
        xw::set_patch_from_property(maxDistance, state, buffers);
        xw::set_patch_from_property(minZoom, state, buffers);
        xw::set_patch_from_property(maxZoom, state, buffers);
        xw::set_patch_from_property(minPolarAngle, state, buffers);
        xw::set_patch_from_property(maxPolarAngle, state, buffers);
        xw::set_patch_from_property(minAzimuthAngle, state, buffers);
        xw::set_patch_from_property(maxAzimuthAngle, state, buffers);
        xw::set_patch_from_property(enableDamping, state, buffers);
        xw::set_patch_from_property(dampingFactor, state, buffers);
        xw::set_patch_from_property(enableZoom, state, buffers);
        xw::set_patch_from_property(zoomSpeed, state, buffers);
        xw::set_patch_from_property(enableRotate, state, buffers);
        xw::set_patch_from_property(rotateSpeed, state, buffers);
        xw::set_patch_from_property(enablePan, state, buffers);
        xw::set_patch_from_property(keyPanSpeed, state, buffers);
        xw::set_patch_from_property(autoRotate, state, buffers);
        xw::set_patch_from_property(autoRotateSpeed, state, buffers);
        xw::set_patch_from_property(enableKeys, state, buffers);
        xw::set_patch_from_property(target, state, buffers);
    }

    template <class D>
    inline void xorbit_controls<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(enabled, patch, buffers);
        xw::set_property_from_patch(minDistance, patch, buffers);
        xw::set_property_from_patch(maxDistance, patch, buffers);
        xw::set_property_from_patch(minZoom, patch, buffers);
        xw::set_property_from_patch(maxZoom, patch, buffers);
        xw::set_property_from_patch(minPolarAngle, patch, buffers);
        xw::set_property_from_patch(maxPolarAngle, patch, buffers);
        xw::set_property_from_patch(minAzimuthAngle, patch, buffers);
        xw::set_property_from_patch(maxAzimuthAngle, patch, buffers);
        xw::set_property_from_patch(enableDamping, patch, buffers);
        xw::set_property_from_patch(dampingFactor, patch, buffers);
        xw::set_property_from_patch(enableZoom, patch, buffers);
        xw::set_property_from_patch(zoomSpeed, patch, buffers);
        xw::set_property_from_patch(enableRotate, patch, buffers);
        xw::set_property_from_patch(rotateSpeed, patch, buffers);
        xw::set_property_from_patch(enablePan, patch, buffers);
        xw::set_property_from_patch(keyPanSpeed, patch, buffers);
        xw::set_property_from_patch(autoRotate, patch, buffers);
        xw::set_property_from_patch(autoRotateSpeed, patch, buffers);
        xw::set_property_from_patch(enableKeys, patch, buffers);
        xw::set_property_from_patch(target, patch, buffers);
    }

    template <class D>
    inline xorbit_controls<D>::xorbit_controls()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xorbit_controls<D>::set_defaults()
    {
        this->_model_name() = "OrbitControlsModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xorbit_controls));
//}
#endif