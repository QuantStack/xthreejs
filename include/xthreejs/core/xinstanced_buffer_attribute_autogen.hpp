#ifndef XTHREE_INSTANCED_BUFFER_ATTRIBUTE_HPP
#define XTHREE_INSTANCED_BUFFER_ATTRIBUTE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xbuffer_attribute_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // instanced_buffer_attribute declaration
    //

    template<class D>
    class xinstanced_buffer_attribute : public xbuffer_attribute<D>
    {
    public:

        using base_type = xbuffer_attribute<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(int, derived_type, meshPerAttribute, 1);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xinstanced_buffer_attribute();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using instanced_buffer_attribute = xw::xmaterialize<xinstanced_buffer_attribute>;

    using instanced_buffer_attribute_generator = xw::xgenerator<xinstanced_buffer_attribute>;

    //
    // instanced_buffer_attribute implementation
    //


    template <class D>
    inline void xinstanced_buffer_attribute<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(meshPerAttribute, state, buffers);
    }

    template <class D>
    inline void xinstanced_buffer_attribute<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(meshPerAttribute, patch, buffers);
    }

    template <class D>
    inline xinstanced_buffer_attribute<D>::xinstanced_buffer_attribute()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xinstanced_buffer_attribute<D>::set_defaults()
    {
        this->_model_name() = "InstancedBufferAttributeModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xinstanced_buffer_attribute>& widget)
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
        extern template class xw::xmaterialize<xthree::xinstanced_buffer_attribute>;
        extern template xw::xmaterialize<xthree::xinstanced_buffer_attribute>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xinstanced_buffer_attribute>>;
        extern template class xw::xgenerator<xthree::xinstanced_buffer_attribute>;
        extern template xw::xgenerator<xthree::xinstanced_buffer_attribute>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xinstanced_buffer_attribute>>;
    #endif
#endif

#endif