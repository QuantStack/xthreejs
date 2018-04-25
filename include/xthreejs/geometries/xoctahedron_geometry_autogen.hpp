#ifndef XTHREE_OCTAHEDRON_GEOMETRY_HPP
#define XTHREE_OCTAHEDRON_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"

namespace xthree
{
    //
    // octahedron_geometry declaration
    //

    template<class D>
    class xoctahedron_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(int, derived_type, detail, 0);

    protected:

        xoctahedron_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using octahedron_geometry = xw::xmaterialize<xoctahedron_geometry>;

    using octahedron_geometry_generator = xw::xgenerator<xoctahedron_geometry>;

    //
    // octahedron_geometry implementation
    //

    template <class D>
    inline void xoctahedron_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(detail, state, buffers);
    }

    template <class D>
    inline void xoctahedron_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(detail, patch, buffers);
    }

    template <class D>
    inline xoctahedron_geometry<D>::xoctahedron_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xoctahedron_geometry<D>::set_defaults()
    {
        this->_model_name() = "OctahedronGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xoctahedron_geometry));
//}
#endif