#ifndef XTHREE_ARRAY_CAMERA_HPP
#define XTHREE_ARRAY_CAMERA_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xperspective_camera_autogen.hpp"

namespace xthree
{
    //
    // array_camera declaration
    //

    template<class D>
    class xarray_camera : public xperspective_camera<D>
    {
    public:

        using base_type = xperspective_camera<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xarray_camera();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using array_camera = xw::xmaterialize<xarray_camera>;

    using array_camera_generator = xw::xgenerator<xarray_camera>;

    //
    // array_camera implementation
    //


    template <class D>
    inline void xarray_camera<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xarray_camera<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xarray_camera<D>::xarray_camera()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xarray_camera<D>::set_defaults()
    {
        this->_model_name() = "ArrayCameraModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xarray_camera>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xarray_camera>>;
    extern template class xw::xgenerator<xthree::xarray_camera>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xarray_camera>>;
#endif

#endif