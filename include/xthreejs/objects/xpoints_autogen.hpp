#ifndef XTHREE_POINTS_HPP
#define XTHREE_POINTS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // points declaration
    //

    template<class D>
    class xpoints : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::xholder<xthree_widget>, derived_type, material);
        XPROPERTY(xw::xholder<xthree_widget>, derived_type, geometry);


    protected:

        xpoints();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using points = xw::xmaterialize<xpoints>;

    using points_generator = xw::xgenerator<xpoints>;

    //
    // points implementation
    //


    template <class D>
    inline void xpoints<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(material, state, buffers);
        xw::set_patch_from_property(geometry, state, buffers);
    }

    template <class D>
    inline void xpoints<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(material, patch, buffers);
        xw::set_property_from_patch(geometry, patch, buffers);
    }

    template <class D>
    inline xpoints<D>::xpoints()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpoints<D>::set_defaults()
    {
        this->_model_name() = "PointsModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xpoints>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xpoints>>;
    extern template class xw::xgenerator<xthree::xpoints>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xpoints>>;
#endif

#endif