#ifndef XTHREE_TEXTURE_HPP
#define XTHREE_TEXTURE_HPP

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
    // texture declaration
    //

    template<class D>
    class xtexture : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, name, "");
        XPROPERTY(std::string, derived_type, mapping, "UVMapping", xenums::MappingModes);
        XPROPERTY(std::string, derived_type, wrapS, "ClampToEdgeWrapping", xenums::WrappingModes);
        XPROPERTY(std::string, derived_type, wrapT, "ClampToEdgeWrapping", xenums::WrappingModes);
        XPROPERTY(std::string, derived_type, magFilter, "LinearFilter", xenums::Filters);
        XPROPERTY(std::string, derived_type, minFilter, "LinearMipMapLinearFilter", xenums::Filters);
        XPROPERTY(std::string, derived_type, format, "RGBAFormat", xenums::PixelFormats);
        XPROPERTY(std::string, derived_type, type, "UnsignedByteType", xenums::DataTypes);
        XPROPERTY(double, derived_type, anisotropy, 1);
        XPROPERTY(vector2, derived_type, repeat, vector2({1,1}));
        XPROPERTY(vector2, derived_type, offset, vector2({0,0}));
        XPROPERTY(bool, derived_type, generateMipmaps, true);
        XPROPERTY(bool, derived_type, premultiplyAlpha, false);
        XPROPERTY(bool, derived_type, flipY, true);
        XPROPERTY(int, derived_type, unpackAlignment, 4);
        XPROPERTY(std::string, derived_type, encoding, "LinearEncoding", xenums::TextureEncodings);
        XPROPERTY(int, derived_type, version, 0);
        XPROPERTY(double, derived_type, rotation, 0);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xtexture();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using texture = xw::xmaterialize<xtexture>;

    using texture_generator = xw::xgenerator<xtexture>;

    //
    // texture implementation
    //


    template <class D>
    inline void xtexture<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(name, state, buffers);
        xw::set_patch_from_property(mapping, state, buffers);
        xw::set_patch_from_property(wrapS, state, buffers);
        xw::set_patch_from_property(wrapT, state, buffers);
        xw::set_patch_from_property(magFilter, state, buffers);
        xw::set_patch_from_property(minFilter, state, buffers);
        xw::set_patch_from_property(format, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
        xw::set_patch_from_property(anisotropy, state, buffers);
        xw::set_patch_from_property(repeat, state, buffers);
        xw::set_patch_from_property(offset, state, buffers);
        xw::set_patch_from_property(generateMipmaps, state, buffers);
        xw::set_patch_from_property(premultiplyAlpha, state, buffers);
        xw::set_patch_from_property(flipY, state, buffers);
        xw::set_patch_from_property(unpackAlignment, state, buffers);
        xw::set_patch_from_property(encoding, state, buffers);
        xw::set_patch_from_property(version, state, buffers);
        xw::set_patch_from_property(rotation, state, buffers);
    }

    template <class D>
    inline void xtexture<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(name, patch, buffers);
        xw::set_property_from_patch(mapping, patch, buffers);
        xw::set_property_from_patch(wrapS, patch, buffers);
        xw::set_property_from_patch(wrapT, patch, buffers);
        xw::set_property_from_patch(magFilter, patch, buffers);
        xw::set_property_from_patch(minFilter, patch, buffers);
        xw::set_property_from_patch(format, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
        xw::set_property_from_patch(anisotropy, patch, buffers);
        xw::set_property_from_patch(repeat, patch, buffers);
        xw::set_property_from_patch(offset, patch, buffers);
        xw::set_property_from_patch(generateMipmaps, patch, buffers);
        xw::set_property_from_patch(premultiplyAlpha, patch, buffers);
        xw::set_property_from_patch(flipY, patch, buffers);
        xw::set_property_from_patch(unpackAlignment, patch, buffers);
        xw::set_property_from_patch(encoding, patch, buffers);
        xw::set_property_from_patch(version, patch, buffers);
        xw::set_property_from_patch(rotation, patch, buffers);
    }

    template <class D>
    inline xtexture<D>::xtexture()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xtexture<D>::set_defaults()
    {
        this->_model_name() = "TextureModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xtexture>& widget)
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
        extern template class xw::xmaterialize<xthree::xtexture>;
        extern template xw::xmaterialize<xthree::xtexture>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xtexture>>;
        extern template class xw::xgenerator<xthree::xtexture>;
        extern template xw::xgenerator<xthree::xtexture>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xtexture>>;
    #endif
#endif

#endif