#ifndef XTHREE_WEBGL_BUFFER_RENDERER_HPP
#define XTHREE_WEBGL_BUFFER_RENDERER_HPP

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
    // webgl_buffer_renderer declaration
    //

    template<class D>
    class xwebgl_buffer_renderer : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xwebgl_buffer_renderer();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_buffer_renderer = xw::xmaterialize<xwebgl_buffer_renderer>;

    using webgl_buffer_renderer_generator = xw::xgenerator<xwebgl_buffer_renderer>;

    //
    // webgl_buffer_renderer implementation
    //


    template <class D>
    inline void xwebgl_buffer_renderer<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_buffer_renderer<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_buffer_renderer<D>::xwebgl_buffer_renderer()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_buffer_renderer<D>::set_defaults()
    {
        this->_model_name() = "WebGLBufferRendererModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xwebgl_buffer_renderer>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xwebgl_buffer_renderer>;
        extern template xw::xmaterialize<xthree::xwebgl_buffer_renderer>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_buffer_renderer>>;
        extern template class xw::xgenerator<xthree::xwebgl_buffer_renderer>;
        extern template xw::xgenerator<xthree::xwebgl_buffer_renderer>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xwebgl_buffer_renderer>>;
    #endif
#endif

#endif