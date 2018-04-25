#ifndef XTHREE_PLANE_BUFFER_GEOMETRY_HPP
#define XTHREE_PLANE_BUFFER_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_buffer_geometry_autogen.hpp"

namespace xthree
{
    //
    // plane_buffer_geometry declaration
    //

    template<class D>
    class xplane_buffer_geometry : public xbase_buffer_geometry<D>
    {
    public:

        using base_type = xbase_buffer_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, width, 1);
        XPROPERTY(double, derived_type, height, 1);
        XPROPERTY(int, derived_type, widthSegments, 1);
        XPROPERTY(int, derived_type, heightSegments, 1);

    protected:

        xplane_buffer_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using plane_buffer_geometry = xw::xmaterialize<xplane_buffer_geometry>;

    using plane_buffer_geometry_generator = xw::xgenerator<xplane_buffer_geometry>;

    //
    // plane_buffer_geometry implementation
    //

    template <class D>
    inline void xplane_buffer_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(width, state, buffers);
        xw::set_patch_from_property(height, state, buffers);
        xw::set_patch_from_property(widthSegments, state, buffers);
        xw::set_patch_from_property(heightSegments, state, buffers);
    }

    template <class D>
    inline void xplane_buffer_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(width, patch, buffers);
        xw::set_property_from_patch(height, patch, buffers);
        xw::set_property_from_patch(widthSegments, patch, buffers);
        xw::set_property_from_patch(heightSegments, patch, buffers);
    }

    template <class D>
    inline xplane_buffer_geometry<D>::xplane_buffer_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xplane_buffer_geometry<D>::set_defaults()
    {
        this->_model_name() = "PlaneBufferGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xplane_buffer_geometry));
//}
#endif