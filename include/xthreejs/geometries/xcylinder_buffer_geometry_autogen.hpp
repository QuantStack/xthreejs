#ifndef XTHREE_CYLINDER_BUFFER_GEOMETRY_HPP
#define XTHREE_CYLINDER_BUFFER_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_buffer_geometry_autogen.hpp"

namespace xthree
{
    //
    // cylinder_buffer_geometry declaration
    //

    template<class D>
    class xcylinder_buffer_geometry : public xbase_buffer_geometry<D>
    {
    public:

        using base_type = xbase_buffer_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radiusTop, 1);
        XPROPERTY(double, derived_type, radiusBottom, 1);
        XPROPERTY(double, derived_type, height, 1);
        XPROPERTY(int, derived_type, radiusSegments, 8);
        XPROPERTY(int, derived_type, heightSegments, 1);
        XPROPERTY(bool, derived_type, openEnded, false);
        XPROPERTY(double, derived_type, thetaStart, 0);
        XPROPERTY(double, derived_type, thetaLength, 6.283185307179586);


    protected:

        xcylinder_buffer_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using cylinder_buffer_geometry = xw::xmaterialize<xcylinder_buffer_geometry>;

    using cylinder_buffer_geometry_generator = xw::xgenerator<xcylinder_buffer_geometry>;

    //
    // cylinder_buffer_geometry implementation
    //


    template <class D>
    inline void xcylinder_buffer_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radiusTop, state, buffers);
        xw::set_patch_from_property(radiusBottom, state, buffers);
        xw::set_patch_from_property(height, state, buffers);
        xw::set_patch_from_property(radiusSegments, state, buffers);
        xw::set_patch_from_property(heightSegments, state, buffers);
        xw::set_patch_from_property(openEnded, state, buffers);
        xw::set_patch_from_property(thetaStart, state, buffers);
        xw::set_patch_from_property(thetaLength, state, buffers);
    }

    template <class D>
    inline void xcylinder_buffer_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radiusTop, patch, buffers);
        xw::set_property_from_patch(radiusBottom, patch, buffers);
        xw::set_property_from_patch(height, patch, buffers);
        xw::set_property_from_patch(radiusSegments, patch, buffers);
        xw::set_property_from_patch(heightSegments, patch, buffers);
        xw::set_property_from_patch(openEnded, patch, buffers);
        xw::set_property_from_patch(thetaStart, patch, buffers);
        xw::set_property_from_patch(thetaLength, patch, buffers);
    }

    template <class D>
    inline xcylinder_buffer_geometry<D>::xcylinder_buffer_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcylinder_buffer_geometry<D>::set_defaults()
    {
        this->_model_name() = "CylinderBufferGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xcylinder_buffer_geometry));
//}
#endif