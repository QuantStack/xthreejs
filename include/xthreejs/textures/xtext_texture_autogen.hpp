#ifndef XTHREE_TEXT_TEXTURE_HPP
#define XTHREE_TEXT_TEXTURE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xtexture_autogen.hpp"

namespace xthree
{
    //
    // text_texture declaration
    //

    template<class D>
    class xtext_texture : public xtexture<D>
    {
    public:

        using base_type = xtexture<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::html_color, derived_type, color, "white");
        XPROPERTY(std::string, derived_type, fontFace, "Arial");
        XPROPERTY(int, derived_type, size, 12);
        XPROPERTY(std::string, derived_type, string, "");
        XPROPERTY(bool, derived_type, squareTexture, true);

    protected:

        xtext_texture();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using text_texture = xw::xmaterialize<xtext_texture>;

    using text_texture_generator = xw::xgenerator<xtext_texture>;

    //
    // text_texture implementation
    //

    template <class D>
    inline void xtext_texture<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(fontFace, state, buffers);
        xw::set_patch_from_property(size, state, buffers);
        xw::set_patch_from_property(string, state, buffers);
        xw::set_patch_from_property(squareTexture, state, buffers);
    }

    template <class D>
    inline void xtext_texture<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(fontFace, patch, buffers);
        xw::set_property_from_patch(size, patch, buffers);
        xw::set_property_from_patch(string, patch, buffers);
        xw::set_property_from_patch(squareTexture, patch, buffers);
    }

    template <class D>
    inline xtext_texture<D>::xtext_texture()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xtext_texture<D>::set_defaults()
    {
        this->_model_name() = "TextTextureModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xtext_texture));
//}
#endif