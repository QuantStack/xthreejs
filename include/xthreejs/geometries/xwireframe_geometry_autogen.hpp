#ifndef XTHREE_WIREFRAME_GEOMETRY_HPP
#define XTHREE_WIREFRAME_GEOMETRY_HPP

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
    // wireframe_geometry declaration
    //

    template<class D>
    class xwireframe_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, geometry);


    protected:

        xwireframe_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using wireframe_geometry = xw::xmaterialize<xwireframe_geometry>;

    using wireframe_geometry_generator = xw::xgenerator<xwireframe_geometry>;

    //
    // wireframe_geometry implementation
    //


    template <class D>
    inline void xwireframe_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(geometry, state, buffers);
    }

    template <class D>
    inline void xwireframe_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(geometry, patch, buffers);
    }

    template <class D>
    inline xwireframe_geometry<D>::xwireframe_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwireframe_geometry<D>::set_defaults()
    {
        this->_model_name() = "WireframeGeometryModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xwireframe_geometry>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xwireframe_geometry>>;
    extern template class xw::xgenerator<xthree::xwireframe_geometry>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xwireframe_geometry>>;
#endif

#endif