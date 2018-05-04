#ifndef XTHREE_CUBE_CAMERA_HPP
#define XTHREE_CUBE_CAMERA_HPP

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
    // cube_camera declaration
    //

    template<class D>
    class xcube_camera : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xcube_camera();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using cube_camera = xw::xmaterialize<xcube_camera>;

    using cube_camera_generator = xw::xgenerator<xcube_camera>;

    //
    // cube_camera implementation
    //


    template <class D>
    inline void xcube_camera<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcube_camera<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcube_camera<D>::xcube_camera()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcube_camera<D>::set_defaults()
    {
        this->_model_name() = "CubeCameraModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xcube_camera>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xcube_camera>>;
    extern template class xw::xgenerator<xthree::xcube_camera>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xcube_camera>>;
#endif

#endif