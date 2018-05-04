#ifndef XTHREE_SHAPE_GEOMETRY_HPP
#define XTHREE_SHAPE_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"

namespace xthree
{
    //
    // shape_geometry declaration
    //

    template<class D>
    class xshape_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::vector<xw::xholder<xthree_widget>>, derived_type, shapes, std::vector<xw::xholder<xthree_widget>>({}));
        XPROPERTY(int, derived_type, curveSegments, 12);
        XPROPERTY(int, derived_type, material, 0);


    protected:

        xshape_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using shape_geometry = xw::xmaterialize<xshape_geometry>;

    using shape_geometry_generator = xw::xgenerator<xshape_geometry>;

    //
    // shape_geometry implementation
    //


    template <class D>
    inline void xshape_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(shapes, state, buffers);
        xw::set_patch_from_property(curveSegments, state, buffers);
        xw::set_patch_from_property(material, state, buffers);
    }

    template <class D>
    inline void xshape_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(shapes, patch, buffers);
        xw::set_property_from_patch(curveSegments, patch, buffers);
        xw::set_property_from_patch(material, patch, buffers);
    }

    template <class D>
    inline xshape_geometry<D>::xshape_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xshape_geometry<D>::set_defaults()
    {
        this->_model_name() = "ShapeGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xshape_geometry));
//}
#endif