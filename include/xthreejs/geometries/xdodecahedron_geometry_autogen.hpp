#ifndef XTHREE_DODECAHEDRON_GEOMETRY_HPP
#define XTHREE_DODECAHEDRON_GEOMETRY_HPP

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
    // dodecahedron_geometry declaration
    //

    template<class D>
    class xdodecahedron_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(int, derived_type, detail, 0);

    protected:

        xdodecahedron_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using dodecahedron_geometry = xw::xmaterialize<xdodecahedron_geometry>;

    using dodecahedron_geometry_generator = xw::xgenerator<xdodecahedron_geometry>;

    //
    // dodecahedron_geometry implementation
    //

    template <class D>
    inline void xdodecahedron_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(detail, state, buffers);
    }

    template <class D>
    inline void xdodecahedron_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(detail, patch, buffers);
    }

    template <class D>
    inline xdodecahedron_geometry<D>::xdodecahedron_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdodecahedron_geometry<D>::set_defaults()
    {
        this->_model_name() = "DodecahedronGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xdodecahedron_geometry));
//}
#endif