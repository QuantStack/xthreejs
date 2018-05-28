#ifndef XTHREE_INTERLEAVED_BUFFER_ATTRIBUTE_HPP
#define XTHREE_INTERLEAVED_BUFFER_ATTRIBUTE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // interleaved_buffer_attribute declaration
    //

    template<class D>
    class xinterleaved_buffer_attribute : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, data);
        XPROPERTY(int, derived_type, itemSize, 0);
        XPROPERTY(int, derived_type, offset, 0);
        XPROPERTY(bool, derived_type, normalized, true);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xinterleaved_buffer_attribute();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using interleaved_buffer_attribute = xw::xmaterialize<xinterleaved_buffer_attribute>;

    using interleaved_buffer_attribute_generator = xw::xgenerator<xinterleaved_buffer_attribute>;

    //
    // interleaved_buffer_attribute implementation
    //


    template <class D>
    inline void xinterleaved_buffer_attribute<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(data, state, buffers);
        xw::set_patch_from_property(itemSize, state, buffers);
        xw::set_patch_from_property(offset, state, buffers);
        xw::set_patch_from_property(normalized, state, buffers);
    }

    template <class D>
    inline void xinterleaved_buffer_attribute<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(data, patch, buffers);
        xw::set_property_from_patch(itemSize, patch, buffers);
        xw::set_property_from_patch(offset, patch, buffers);
        xw::set_property_from_patch(normalized, patch, buffers);
    }

    template <class D>
    inline xinterleaved_buffer_attribute<D>::xinterleaved_buffer_attribute()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xinterleaved_buffer_attribute<D>::set_defaults()
    {
        this->_model_name() = "InterleavedBufferAttributeModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xinterleaved_buffer_attribute>& widget)
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
        extern template class xw::xmaterialize<xthree::xinterleaved_buffer_attribute>;
        extern template xw::xmaterialize<xthree::xinterleaved_buffer_attribute>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xinterleaved_buffer_attribute>>;
        extern template class xw::xgenerator<xthree::xinterleaved_buffer_attribute>;
        extern template xw::xgenerator<xthree::xinterleaved_buffer_attribute>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xinterleaved_buffer_attribute>>;
    #endif
#endif

#endif