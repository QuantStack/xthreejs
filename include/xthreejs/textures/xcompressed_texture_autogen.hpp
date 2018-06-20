#ifndef XTHREE_COMPRESSED_TEXTURE_HPP
#define XTHREE_COMPRESSED_TEXTURE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xtexture_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // compressed_texture declaration
    //

    template<class D>
    class xcompressed_texture : public xtexture<D>
    {
    public:

        using base_type = xtexture<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xcompressed_texture();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using compressed_texture = xw::xmaterialize<xcompressed_texture>;

    using compressed_texture_generator = xw::xgenerator<xcompressed_texture>;

    //
    // compressed_texture implementation
    //


    template <class D>
    inline void xcompressed_texture<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcompressed_texture<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcompressed_texture<D>::xcompressed_texture()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcompressed_texture<D>::set_defaults()
    {
        this->_model_name() = "CompressedTextureModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcompressed_texture>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xcompressed_texture>;
        extern template xw::xmaterialize<xthree::xcompressed_texture>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xcompressed_texture>>;
        extern template class xw::xgenerator<xthree::xcompressed_texture>;
        extern template xw::xgenerator<xthree::xcompressed_texture>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xcompressed_texture>>;
    #endif
#endif

#endif