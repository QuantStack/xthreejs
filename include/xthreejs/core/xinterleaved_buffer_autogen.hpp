#ifndef XTHREE_INTERLEAVED_BUFFER_HPP
#define XTHREE_INTERLEAVED_BUFFER_HPP

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
    // interleaved_buffer declaration
    //

    template<class D>
    class xinterleaved_buffer : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(webgldataunion, derived_type, array);
        XPROPERTY(int, derived_type, stride, 0);
        XPROPERTY(bool, derived_type, dynamic, false);
        XPROPERTY(int, derived_type, version, 0);
        XPROPERTY(bool, derived_type, needsUpdate, false);

        const std::vector<xw::xjson_path_type>& buffer_paths() const;

        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xinterleaved_buffer();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using interleaved_buffer = xw::xmaterialize<xinterleaved_buffer>;

    using interleaved_buffer_generator = xw::xgenerator<xinterleaved_buffer>;

    //
    // interleaved_buffer implementation
    //

    template <class D>
    inline const std::vector<xw::xjson_path_type>&  xinterleaved_buffer<D>::buffer_paths() const
    {
        static const std::vector<xw::xjson_path_type> default_buffer_paths = { 
            { "array", "buffer" },
        };
        return default_buffer_paths;
    }

    template <class D>
    inline void xinterleaved_buffer<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(array, state, buffers);
        xw::set_patch_from_property(stride, state, buffers);
        xw::set_patch_from_property(dynamic, state, buffers);
        xw::set_patch_from_property(version, state, buffers);
        xw::set_patch_from_property(needsUpdate, state, buffers);
    }

    template <class D>
    inline void xinterleaved_buffer<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(array, patch, buffers);
        xw::set_property_from_patch(stride, patch, buffers);
        xw::set_property_from_patch(dynamic, patch, buffers);
        xw::set_property_from_patch(version, patch, buffers);
        xw::set_property_from_patch(needsUpdate, patch, buffers);
    }

    template <class D>
    inline xinterleaved_buffer<D>::xinterleaved_buffer()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xinterleaved_buffer<D>::set_defaults()
    {
        this->_model_name() = "InterleavedBufferModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xinterleaved_buffer>& widget)
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
        extern template class xw::xmaterialize<xthree::xinterleaved_buffer>;
        extern template xw::xmaterialize<xthree::xinterleaved_buffer>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xinterleaved_buffer>>;
        extern template class xw::xgenerator<xthree::xinterleaved_buffer>;
        extern template xw::xgenerator<xthree::xinterleaved_buffer>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xinterleaved_buffer>>;
    #endif
#endif

#endif