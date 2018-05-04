#ifndef XTHREE_SPHERE_BUFFER_GEOMETRY_HPP
#define XTHREE_SPHERE_BUFFER_GEOMETRY_HPP

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
    // sphere_buffer_geometry declaration
    //

    template<class D>
    class xsphere_buffer_geometry : public xbase_buffer_geometry<D>
    {
    public:

        using base_type = xbase_buffer_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(int, derived_type, widthSegments, 8);
        XPROPERTY(int, derived_type, heightSegments, 6);
        XPROPERTY(double, derived_type, phiStart, 0);
        XPROPERTY(double, derived_type, phiLength, 6.283185307179586);
        XPROPERTY(double, derived_type, thetaStart, 0);
        XPROPERTY(double, derived_type, thetaLength, 3.141592653589793);


    protected:

        xsphere_buffer_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using sphere_buffer_geometry = xw::xmaterialize<xsphere_buffer_geometry>;

    using sphere_buffer_geometry_generator = xw::xgenerator<xsphere_buffer_geometry>;

    //
    // sphere_buffer_geometry implementation
    //


    template <class D>
    inline void xsphere_buffer_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(widthSegments, state, buffers);
        xw::set_patch_from_property(heightSegments, state, buffers);
        xw::set_patch_from_property(phiStart, state, buffers);
        xw::set_patch_from_property(phiLength, state, buffers);
        xw::set_patch_from_property(thetaStart, state, buffers);
        xw::set_patch_from_property(thetaLength, state, buffers);
    }

    template <class D>
    inline void xsphere_buffer_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(widthSegments, patch, buffers);
        xw::set_property_from_patch(heightSegments, patch, buffers);
        xw::set_property_from_patch(phiStart, patch, buffers);
        xw::set_property_from_patch(phiLength, patch, buffers);
        xw::set_property_from_patch(thetaStart, patch, buffers);
        xw::set_property_from_patch(thetaLength, patch, buffers);
    }

    template <class D>
    inline xsphere_buffer_geometry<D>::xsphere_buffer_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xsphere_buffer_geometry<D>::set_defaults()
    {
        this->_model_name() = "SphereBufferGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xsphere_buffer_geometry));
//}
#endif