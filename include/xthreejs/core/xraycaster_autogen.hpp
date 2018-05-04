#ifndef XTHREE_RAYCASTER_HPP
#define XTHREE_RAYCASTER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // raycaster declaration
    //

    template<class D>
    class xraycaster : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector3, derived_type, origin, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, direction, vector3({0,0,0}));
        XPROPERTY(double, derived_type, near, 0);
        XPROPERTY(double, derived_type, far, 1000000);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, ray);
        XPROPERTY(double, derived_type, linePrecision, 1);


    protected:

        xraycaster();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using raycaster = xw::xmaterialize<xraycaster>;

    using raycaster_generator = xw::xgenerator<xraycaster>;

    //
    // raycaster implementation
    //


    template <class D>
    inline void xraycaster<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(origin, state, buffers);
        xw::set_patch_from_property(direction, state, buffers);
        xw::set_patch_from_property(near, state, buffers);
        xw::set_patch_from_property(far, state, buffers);
        xw::set_patch_from_property(ray, state, buffers);
        xw::set_patch_from_property(linePrecision, state, buffers);
    }

    template <class D>
    inline void xraycaster<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(origin, patch, buffers);
        xw::set_property_from_patch(direction, patch, buffers);
        xw::set_property_from_patch(near, patch, buffers);
        xw::set_property_from_patch(far, patch, buffers);
        xw::set_property_from_patch(ray, patch, buffers);
        xw::set_property_from_patch(linePrecision, patch, buffers);
    }

    template <class D>
    inline xraycaster<D>::xraycaster()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xraycaster<D>::set_defaults()
    {
        this->_model_name() = "RaycasterModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xraycaster>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xraycaster>>;
    extern template class xw::xgenerator<xthree::xraycaster>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xraycaster>>;
#endif

#endif