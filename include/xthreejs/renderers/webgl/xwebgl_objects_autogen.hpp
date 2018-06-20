#ifndef XTHREE_WEBGL_OBJECTS_HPP
#define XTHREE_WEBGL_OBJECTS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"
#include "../../base/xrender.hpp"

namespace xthree
{
    //
    // webgl_objects declaration
    //

    template<class D>
    class xwebgl_objects : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xwebgl_objects();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_objects = xw::xmaterialize<xwebgl_objects>;

    using webgl_objects_generator = xw::xgenerator<xwebgl_objects>;

    //
    // webgl_objects implementation
    //


    template <class D>
    inline void xwebgl_objects<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_objects<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_objects<D>::xwebgl_objects()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_objects<D>::set_defaults()
    {
        this->_model_name() = "WebGLObjectsModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_objects>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xwebgl_objects>;
        extern template xw::xmaterialize<xthree::xwebgl_objects>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_objects>>;
        extern template class xw::xgenerator<xthree::xwebgl_objects>;
        extern template xw::xgenerator<xthree::xwebgl_objects>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xwebgl_objects>>;
    #endif
#endif

#endif