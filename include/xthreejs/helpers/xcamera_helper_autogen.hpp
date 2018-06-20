#ifndef XTHREE_CAMERA_HELPER_HPP
#define XTHREE_CAMERA_HELPER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // camera_helper declaration
    //

    template<class D>
    class xcamera_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, camera);
        XPROPERTY(std::string, derived_type, type, "CameraHelper");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xcamera_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using camera_helper = xw::xmaterialize<xcamera_helper>;

    using camera_helper_generator = xw::xgenerator<xcamera_helper>;

    //
    // camera_helper implementation
    //


    template <class D>
    inline void xcamera_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(camera, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xcamera_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(camera, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xcamera_helper<D>::xcamera_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcamera_helper<D>::set_defaults()
    {
        this->_model_name() = "CameraHelperModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcamera_helper>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xcamera_helper>;
        extern template xw::xmaterialize<xthree::xcamera_helper>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xcamera_helper>>;
        extern template class xw::xgenerator<xthree::xcamera_helper>;
        extern template xw::xgenerator<xthree::xcamera_helper>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xcamera_helper>>;
    #endif
#endif

#endif