#ifndef XTHREE_INSTANCED_INTERLEAVED_BUFFER_HPP
#define XTHREE_INSTANCED_INTERLEAVED_BUFFER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xinterleaved_buffer_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // instanced_interleaved_buffer declaration
    //

    template<class D>
    class xinstanced_interleaved_buffer : public xinterleaved_buffer<D>
    {
    public:

        using base_type = xinterleaved_buffer<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(int, derived_type, meshPerAttribute, 1);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xinstanced_interleaved_buffer();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using instanced_interleaved_buffer = xw::xmaterialize<xinstanced_interleaved_buffer>;

    using instanced_interleaved_buffer_generator = xw::xgenerator<xinstanced_interleaved_buffer>;

    //
    // instanced_interleaved_buffer implementation
    //


    template <class D>
    inline void xinstanced_interleaved_buffer<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(meshPerAttribute, state, buffers);
    }

    template <class D>
    inline void xinstanced_interleaved_buffer<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(meshPerAttribute, patch, buffers);
    }

    template <class D>
    inline xinstanced_interleaved_buffer<D>::xinstanced_interleaved_buffer()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xinstanced_interleaved_buffer<D>::set_defaults()
    {
        this->_model_name() = "InstancedInterleavedBufferModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xinstanced_interleaved_buffer>& widget)
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
        extern template class xw::xmaterialize<xthree::xinstanced_interleaved_buffer>;
        extern template xw::xmaterialize<xthree::xinstanced_interleaved_buffer>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xinstanced_interleaved_buffer>>;
        extern template class xw::xgenerator<xthree::xinstanced_interleaved_buffer>;
        extern template xw::xgenerator<xthree::xinstanced_interleaved_buffer>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xinstanced_interleaved_buffer>>;
    #endif
#endif

#endif