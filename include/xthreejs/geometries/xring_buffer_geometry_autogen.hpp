#ifndef XTHREE_RING_BUFFER_GEOMETRY_HPP
#define XTHREE_RING_BUFFER_GEOMETRY_HPP

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
    // ring_buffer_geometry declaration
    //

    template<class D>
    class xring_buffer_geometry : public xbase_buffer_geometry<D>
    {
    public:

        using base_type = xbase_buffer_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, innerRadius, 0.5);
        XPROPERTY(double, derived_type, outerRadius, 1);
        XPROPERTY(int, derived_type, thetaSegments, 8);
        XPROPERTY(int, derived_type, phiSegments, 8);
        XPROPERTY(double, derived_type, thetaStart, 0);
        XPROPERTY(double, derived_type, thetaLength, 6.283185307179586);


    protected:

        xring_buffer_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using ring_buffer_geometry = xw::xmaterialize<xring_buffer_geometry>;

    using ring_buffer_geometry_generator = xw::xgenerator<xring_buffer_geometry>;

    //
    // ring_buffer_geometry implementation
    //


    template <class D>
    inline void xring_buffer_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(innerRadius, state, buffers);
        xw::set_patch_from_property(outerRadius, state, buffers);
        xw::set_patch_from_property(thetaSegments, state, buffers);
        xw::set_patch_from_property(phiSegments, state, buffers);
        xw::set_patch_from_property(thetaStart, state, buffers);
        xw::set_patch_from_property(thetaLength, state, buffers);
    }

    template <class D>
    inline void xring_buffer_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(innerRadius, patch, buffers);
        xw::set_property_from_patch(outerRadius, patch, buffers);
        xw::set_property_from_patch(thetaSegments, patch, buffers);
        xw::set_property_from_patch(phiSegments, patch, buffers);
        xw::set_property_from_patch(thetaStart, patch, buffers);
        xw::set_property_from_patch(thetaLength, patch, buffers);
    }

    template <class D>
    inline xring_buffer_geometry<D>::xring_buffer_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xring_buffer_geometry<D>::set_defaults()
    {
        this->_model_name() = "RingBufferGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xring_buffer_geometry));
//}
#endif